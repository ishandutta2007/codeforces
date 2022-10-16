#include <bits/stdc++.h>

using namespace std;

long long n,fq[26];

long long tri(long long x)
{
	return x*(x-1)/2;
}

int main()
{
	long long i,z=0;
	string s;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		cin>>s;
		fq[s[0]-'a']++;
	}
	for(i=0;i<26;i++)
	{
		z+=tri(fq[i]/2)+tri((fq[i]+1)/2);
	}
	printf("%lld\n",z);
}