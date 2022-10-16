#include <bits/stdc++.h>

using namespace std;

long long n,ttl,a[3069];

int main()
{
	long long t,rr,i,j,sm,c;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		ttl=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			ttl+=a[i];
		}
		for(i=n;i;i--)
		{
			if(ttl%i==0)
			{
				sm=0;
				c=0;
				for(j=1;j<=n;j++)
				{
					sm+=a[j];
					if(sm>ttl/i)
					{
						c=-1;
						break;
					}
					c+=sm==ttl/i;
					sm%=ttl/i;
				}
				if(c==i)
				{
					break;
				}
			}
		}
		printf("%lld\n",n-i);
	}
}