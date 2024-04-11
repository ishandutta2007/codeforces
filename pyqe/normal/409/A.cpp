#include <bits/stdc++.h>

using namespace std;

map<char,long long> ky;

int main()
{
	long long n,it,z[2]={0,0},i;
	string s[2];
	
	ky['[']=0;
	ky['8']=1;
	ky['(']=2;
	for(it=0;it<2;it++)
	{
		cin>>s[it];
	}
	n=s[0].length();
	for(i=0;i<n;i+=2)
	{
		if((ky[s[1][i]]+3-ky[s[0][i]])%3==1)
		{
			z[1]++;
		}
		else if((ky[s[1][i]]+3-ky[s[0][i]])%3==2)
		{
			z[0]++;
		}
	}
	if(z[0]>z[1])
	{
		printf("TEAM 1 WINS\n");
	}
	else if(z[0]<z[1])
	{
		printf("TEAM 2 WINS\n");
	}
	else
	{
		printf("TIE\n");
	}
}