#include <iostream>
#include <fstream>

using namespace std;

int pow(int base, int exponent){
	int output;
	output = base;

	if(exponent == 0){
		return 1;
	}

	for(int i = 1; i < exponent; i++){
		output = output*base;
	}
	return output;
}

long long changeBases(long long number, int base, int convert){
	//base is base of the original numbering system (binary=2,decimal=10)
	//convert is the base you want to convert to
	long long output = 0;

	int i = 0;
	int temp;

	while(number > 0){
		temp = number % convert;
		number = number / convert;

		output = output + temp * pow(base, i);

		i++;
	}
	return output;
}

int main(){
	ifstream inFile;
	ofstream outFile;

	inFile.open("p1in.txt");
	outFile.open("p1out.txt");

	if(!inFile.is_open()){cout << "Could not open file." << endl;}

	int numLines;
	inFile >> numLines;

	cout << numLines << endl;

	for(int i = 0; i < numLines; i++){
		char numType;
		long long number;
		inFile >> numType;
		inFile >> number;
		long long output;
		char outputType;

		if(numType == 'B'){
			output = changeBases(number, 2, 10);
			outputType = 'D';
		}else if(numType == 'D'){
			output = changeBases(number, 10, 2);
			outputType = 'B';
		}else{
			cout << "Unsupported number type" << endl;
		}

		outFile << number << "(" << numType << ") is " << output << "(" << outputType << ")" << endl;
	}

	return 0;
}

