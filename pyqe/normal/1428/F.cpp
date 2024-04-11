#include <bits/stdc++.h>

using namespace std;

long long n,od[500069],fh[500069],ls[500069];
bitset<500069> a;

int main()
{
	long long i,p,sm=0,z=0;
	char ch;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf(" %c",&ch);
		a[i]=ch-'0';
		od[i]=(od[i-1]+1)*a[i];
	}
	for(i=n;i;i--)
	{
		if(a[i])
		{
			if(!a[i+1])
			{
				fh[i]=i;
			}
			else
			{
				fh[i]=fh[i+1];
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(a[i])
		{
			p=fh[i]+1-od[i];
			sm+=p-ls[od[i]];
			ls[od[i]]=p;
			z+=sm-od[i]*(fh[i]-i);
		}
		else
		{
			z+=sm;
		}
	}
	printf("%lld\n",z);
}