#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int main()
{
	string s;
	int a,b;
	cin >> s;
	int n;
	if(s.size()==1)
		n = ((int)s[s.size()-1])-48;
	else
	{
		a = ((int)s[s.size()-2])-48;
		b = ((int)s[s.size()-1])-48;
		n = 10*a+b;
	}
	if((n%4)) cout << 0 << endl;
	else cout << 4 << endl;
}