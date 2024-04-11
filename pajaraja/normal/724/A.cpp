#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int main(int argc, char** argv) 
{
	string a,b;
	int x,y;
	cin>>a;
	cin>>b;
	if(a=="monday") x=0;
	if(a=="tuesday") x=1;
	if(a=="wednesday") x=2;
	if(a=="thursday") x=3;
	if(a=="friday") x=4;
	if(a=="saturday") x=5;
	if(a=="sunday") x=6;
	if(b=="monday") y=0;
	if(b=="tuesday") y=1;
	if(b=="wednesday") y=2;
	if(b=="thursday") y=3;
	if(b=="friday") y=4;
	if(b=="saturday") y=5;
	if(b=="sunday") y=6;
	if(x==y||(x+31)%7==y||(x+30)%7==y) cout<<"YES";
	else cout<<"NO";
	return 0;
}