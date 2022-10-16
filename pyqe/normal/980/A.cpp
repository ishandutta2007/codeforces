#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,c=0;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=0;i<n;i++)
	{
		c+=s[i]=='o';
	}
	if(!c||n%c==0)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}