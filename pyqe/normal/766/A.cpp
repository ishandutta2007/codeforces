#include <bits/stdc++.h>

using namespace std;

long long n[2];

int main()
{
	long long i,ii,z;
	string s[2];
	
	for(ii=0;ii<2;ii++)
	{
		cin>>s[ii];
		n[ii]=s[ii].length();
	}
	if(s[0]!=s[1])
	{
		z=max(n[0],n[1]);
	}
	else
	{
		z=-1;
	}
	printf("%lld\n",z);
}