#include <iostream>
#include <math.h>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main()
{
	int say = 8;
	string a;
	cin>>a;
	if(a[0]=='a' || a[0]=='h')
	{
		say=5;
	}
	if(a[1]=='1' || a[1]=='8')
	{
		if(say==5)
		{
			say=3;
		}
		else
		{
			say=5;
		}
	}
	cout<<say;
}