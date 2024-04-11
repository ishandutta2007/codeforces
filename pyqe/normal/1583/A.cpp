#include <bits/stdc++.h>

using namespace std;

long long n,ttl,a[100069];

int main()
{
	long long t,rr,i,j;
	
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
		for(i=2;i*i<=ttl;i++)
		{
			if(ttl%i==0)
			{
				break;
			}
		}
		if(i*i<=ttl)
		{
			printf("%lld\n",n);
			for(i=1;i<=n;i++)
			{
				printf("%lld%c",i," \n"[i==n]);
			}
			continue;
		}
		for(i=1;i<=n;i++)
		{
			if(a[i]%2)
			{
				printf("%lld\n",n-1);
				for(j=1;j<=n;j++)
				{
					if(j!=i)
					{
						printf("%lld%c",j," \n"[j==n-(i==n)]);
					}
				}
				break;
			}
		}
	}
}