#include <bits/stdc++.h>

using namespace std;

long long n,d=25,a[100069],ls[10][2],inf=1e18;

int main()
{
	long long i,j,k,l,c,z=inf;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'0';
		ls[a[i]][1]=ls[a[i]][0];
		ls[a[i]][0]=i;
	}
	for(i=0;i*d<100;i++)
	{
		k=ls[i*d%10][0];
		l=ls[i*d/10][i*d%10==i*d/10];
		if(!k||!l)
		{
			continue;
		}
		c=0;
		for(j=1;j<=n&&(j==k||j==l||!a[j]);j++)
		{
			c+=j==k||j==l;
		}
		if(j>n&&n>2)
		{
			continue;
		}
		z=min(z,n-k+n-1-l+(k<l)+j-1-c);
	}
	if(z==inf)
	{
		z=-1;
	}
	printf("%lld\n",z);
}