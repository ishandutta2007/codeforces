#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,c=0;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=0;i<n-1-i;i++)
	{
		c+=s[i]!=s[n-1-i];
	}
	if(c<=1&&(c||n%2))
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}