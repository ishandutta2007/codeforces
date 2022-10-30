#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int main(int argc, char** argv) 
{
	int n,br1=0,br2;
	string s;
	cin>>n;
	br2=n-1;
	cin>>s;
	while(s[br1]!='>'&&br1<n) br1++;
	while(s[br2]!='<'&&br2>=0) br2--;
	int r=br1+n-1-br2;
	cout<<r;
	return 0;
}