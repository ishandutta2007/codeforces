#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long t,rr,i,k,z=0;
	bool bad0,bad1;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			a[i]=ch-'0';
		}
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			k=ch-'0';
			if(a[i]&&k)
			{
				a[i]=0;
			}
			else if(!a[i]&&!k)
			{
				a[i]=1;
			}
			else
			{
				a[i]=2;
			}
		}
		bad0=0;
		bad1=0;
		z=0;
		for(i=1;i<=n;i++)
		{
			z+=a[i];
			if(!a[i])
			{
				if(bad1)
				{
					z++;
					bad0=0;
					bad1=0;
				}
				else
				{
					bad0=1;
				}
			}
			else if(a[i]==1)
			{
				if(bad0)
				{
					z++;
					bad0=0;
					bad1=0;
				}
				else
				{
					bad1=1;
				}
			}
			else
			{
				bad0=0;
				bad1=0;
			}
		}
		printf("%lld\n",z);
	}
}