// Reads students names and grades, and then finds the average after dropping the lowest grade.

#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    ifstream infile;
    infile.open("read.txt");
    ofstream outputfile;
    outputfile.open("write.txt");

    // Declare variables

    char grade;
    double num;
    double lowest = 0;
    double total = 0;
    double average = 0;
    double average_Highest = -1; //Initialize value, To use in the first case
    double average_Lowest = 0;
    string name;
    string name_Highest; // person with highest average
    string name_Lowest; // person with lowest average


    outputfile << "\t\tREPORT\n";
    outputfile.width(10);
    outputfile << left << "Name";
    outputfile << "\t\t\tGrade\n\n";


    infile >> name;  // Storing the name of the first student

    while(!infile.eof())
    {
        total = 0;

        for(int i = 0; i < 7; i++)
        {
            infile >> num;              // Reads students grades
            if(num < lowest || i == 0)    // Determining lowest letter grade in array
            {
                lowest = num;
            }
            total += num;               // Calculating the sum
        }
        average = ((total - lowest)/6);    // Calculate average divides by 6 after dropping lowest grade there is no longer 7 numbers


        // Determining letter grade
        if(average >= 90 && average <= 100)
            grade = 'A';
        else if(average >= 80 && average < 90)
            grade = 'B';
        else if(average >= 70 && average < 80)
            grade = 'C';
        else if(average >= 60 && average < 70)
            grade = 'D';
        else if(average >= 0 && average < 60)
            grade = 'F';

        outputfile.width(34);
        outputfile << left << name ;
        outputfile << grade << "\n" << endl; // first student

        // if there is only one person in the file that person has both the highest and lowest grades
         if (average_Highest == -1)
        {
            name_Highest = name;
            name_Lowest = name;
            average_Highest = average;
            average_Lowest = average;
        }
         else if (average > average_Highest)
        {
              name_Highest = name;
              average_Highest = average;
        }
         else if (average < average_Lowest)
        {
              name_Lowest = name;
              average_Lowest = average;
        }
        infile >> name; // Storing student's name or checks if is the end of file
    }
    outputfile << setprecision(2) << fixed << showpoint;
    outputfile << "The student with the highest grade is " << name_Highest << " (" << average_Highest << ")" << "\n" << endl; // student with highest grade
    outputfile << "The student with the lowest grade is " << name_Lowest << " (" << average_Lowest << ")" << endl; // student with lowest grade
    return 0;
}
