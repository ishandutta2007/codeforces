#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

vector<string> A;
string s;

int main()
{
	int i = 0;
	int inner;
	while(getline(cin,s))
	{
		A.push_back(s);
		inner = max(inner,(int)A[i].size());
		i++;
	}
	int lines = i;
	for(int j=0;j<(inner+2);j++)
		cout << "*";
	cout << "\n";
	int lopsided = 0;
	for(int j=0;j<lines;j++)
	{
		cout << "*";
		int spaces = inner-A[j].size();
		int left = spaces/2;
		int right = spaces/2;
		if(spaces%2)
		{
			if(lopsided==0) right++;
			else left++;
			lopsided ^= 1;
		}
		for(int c=0;c<left;c++) cout << " ";
		cout << A[j];
		for(int c=0;c<right;c++) cout << " ";
		cout << "*\n";
	}
	for(int j=0;j<(inner+2);j++)
		cout << "*";
	cout << "\n";
	return 0;
}