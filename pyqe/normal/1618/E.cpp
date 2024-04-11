#include <bits/stdc++.h>

using namespace std;

long long n,ttl,a[100069],sq[100069];

int main()
{
	long long t,rr,i,k;
	
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
		if(ttl%(n*(n+1)/2))
		{
			printf("NO\n");
			continue;
		}
		ttl/=n*(n+1)/2;
		for(i=1;i<=n;i++)
		{
			k=ttl-(a[i]-a[(i+n-2)%n+1]);
			if(k%n||k<=0)
			{
				break;
			}
			sq[i]=k/n;
		}
		if(i>n)
		{
			printf("YES\n");
			for(i=1;i<=n;i++)
			{
				printf("%lld%c",sq[i]," \n"[i==n]);
			}
		}
		else
		{
			printf("NO\n");
		}
	}
}