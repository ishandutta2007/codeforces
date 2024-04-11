#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k,sm=0,z=1;
	string s;
	
	cin>>s;
	n=s.length();
	if(n==1)
	{
		printf("0\n");
		return 0;
	}
	for(i=0;i<n;i++)
	{
		k=s[i]-'0';
		sm+=k;
	}
	for(;sm>=10;sm=k,z++)
	{
		k=0;
		for(;sm;k+=sm%10,sm/=10);
	}
	printf("%lld\n",z);
}