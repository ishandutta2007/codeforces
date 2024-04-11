#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	int t,n,r=0;
	cin>>n;
	string s;
	cin>>s;
	int k[26];
	fill(k,k+26,0);
	for(int i=0;i<n;i++)
	{
		t=s[i]-'a';
		k[t]++;
	}
	for(int i=0;i<26;i++)
	{
		if(k[i]!=0)
		{
			r=r+k[i]-1;
		}
	}
	if(n>26)
	{
		r=-1;
	}
	cout<<r;
	return 0;
}