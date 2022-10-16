#include <bits/stdc++.h>

using namespace std;

long long n,a[300069],mk[300069],ttl=0;

int main()
{
	long long i,j,sm,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",a+i,mk+i);
		ttl+=a[i];
	}
	if(ttl>0)
	{
		for(i=1;i<=n;i++)
		{
			a[i]*=-1;
		}
		ttl*=-1;
	}
	for(i=0;i<62;i++)
	{
		sm=0;
		for(j=1;j<=n;j++)
		{
			sm+=a[j]*((mk[j]^1ll<<i)<1ll<<i);
		}
		if(sm<0)
		{
			z|=1ll<<i;
			for(j=1;j<=n;j++)
			{
				if((mk[j]&1ll<<i)==1ll<<i)
				{
					a[j]*=-1;
				}
			}
		}
	}
	printf("%lld\n",z);
}