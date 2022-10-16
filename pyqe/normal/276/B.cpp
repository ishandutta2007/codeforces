#include <bits/stdc++.h>

using namespace std;

long long n,fq[26];

int main()
{
	long long i,k,c=0;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		k=s[i-1]-'a';
		fq[k]++;
	}
	for(i=0;i<26;i++)
	{
		c+=fq[i]%2;
	}
	if(!c||c%2)
	{
		printf("First\n");
	}
	else
	{
		printf("Second\n");
	}
}