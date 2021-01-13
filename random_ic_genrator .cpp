// program name : randowm ic generator 

#include <iostream>
#include <stdlib.h> //for rand and srand functions
#include <ctime> //time library
#include <iomanip> //spacing zero value library
using namespace std;

int main ()
{
	srand((unsigned) time(0)); //reset time for random number 
	time_t t = time(NULL); //reset time 
	tm * tPtr = localtime(&t); //local time in the system
	
	char choice;
	int year_rand, mon_rand, day_rand, state_rand, forth_rand, age;
		
	cout << "\n---------------------RANDOM IC GENERATOR----------------------\n" << endl;
	cout << "Start? (y/n) : ";
	cin >> choice;
	
	while (toupper(choice) != 'N')
	{
		//year_rand = rand() % 14; //range from 0 to 13
		year_rand = rand() % 12 + 1; //range from 2 to 14 (range from 2000 to 2014) // 12+1
		mon_rand = rand() % 12 + 1; //range from 1 to 12
		day_rand = rand() % 31 + 1;
		state_rand = rand() % 21 + 1; 
		//forth_rand = rand() % 3000 + 4999; //range from 4999 to 7999
		forth_rand = rand() % 1999;
		
		//cout << "\nIC : " << year_rand << "-" << mon_rand << "-" << day_rand << "-" << state_rand << "-" << forth_rand << endl;
		//cout << "year : " << setw(2) << setfill('0') << year_rand << endl;
		//cout << "months : " << setw(2) << setfill('0') << mon_rand << endl;
		//cout << "days : " << setw(2) << setfill('0') << day_rand << endl;
		//cout << "states : " << setw(2) << setfill('0') << state_rand << endl;
		//cout << "forth number : " << setw(4) << setfill('0') << forth_rand << endl;
		
		cout << "\nIC : ";
		cout << setw(2) << setfill('0') << year_rand;
		cout << setw(2) << setfill('0') << mon_rand;
		cout << setw(2) << setfill('0') << day_rand;
		cout << setw(2) << setfill('0') << state_rand;
		cout << setw(4) << setfill('0') << forth_rand << endl;
		
		if (forth_rand % 2 == 0) 
		{
			cout << "Gender : Female" << endl;	
		}		
		else
		{
			cout << "Gender : Male" << endl;
		}
		
		//age = ((tPtr->tm_year)+1900) - (2000 + year_rand);
		//cout << "Age : " << age << endl;
		
		//int current_year = ((tPtr->tm_year)+1900);
		//cout << "current year : " << current_year << endl;
		
		int current_year = (tPtr->tm_year + 1900); // 120 + 1900 = 2020
		int byear = (tPtr->tm_year - 100); //120 - 100 = 20
		//cout << "current year : " << current_year << endl;
		
		if (year_rand <= byear) 
		{
			age = current_year - (2000 + year_rand);
		}
		else 
		{
			age = current_year - (1900 + year_rand);
		}
		cout << "Age : " << age << endl;
		
		cout << "\nContinue? (y/n) : ";
		cin >> choice;
	}
	return 0;
}

