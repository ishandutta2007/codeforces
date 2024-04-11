#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
	string a;
	string b;
	cin>>a;
	cin>>b;
	if(a==b)
	{
		cout<<a;
	}
	else
	{
		cout<<1;
	}
	return 0;
}