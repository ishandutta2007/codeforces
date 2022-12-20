#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if((n%3)==1) n--;
	if((n%3)==2) n++;
	n /= 3;
	int feet = n/12;
	int inch = n%12;
	cout << feet << " " << inch << endl;
	return 0;
}