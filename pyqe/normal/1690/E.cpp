#include <bits/stdc++.h>

using namespace std;

long long n,d,ttl,a[200069];

int main()
{
	long long t,rr,i,k,lh,rh,md,zz;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		ttl=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			ttl+=k/d;
			a[i]=k%d;
		}
		sort(a+1,a+n+1);
		for(zz=0,lh=1,rh=n/2;lh<=rh;)
		{
			md=(lh+rh)/2;
			for(i=1;i<=md;i++)
			{
				if(a[n+1-i]+a[n-md*2+i]<d)
				{
					break;
				}
			}
			if(i>md)
			{
				zz=md;
				lh=md+1;
			}
			else
			{
				rh=md-1;
			}
		}
		printf("%lld\n",ttl+zz);
	}
}