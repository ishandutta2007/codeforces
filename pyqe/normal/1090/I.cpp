#include <bits/stdc++.h>

using namespace std;

long long n,lb,rb,d,d2,d3,a[10000069],pn[10000069],sx[10000069],dv=1ll<<32,inf=5e18;

int main()
{
	long long t,rr,i,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&n,&lb,&rb,&d,&d2,&d3,a+1,a+2);
		for(i=3;i<=n;i++)
		{
			a[i]=((unsigned long long)a[i-2]*d+(unsigned long long)a[i-1]*d2+d3)%dv;
		}
		pn[0]=inf;
		for(i=1;i<=n;i++)
		{
			a[i]=a[i]%(rb-lb+1)+lb;
			pn[i]=min(pn[i-1],a[i]);
		}
		sx[n+1]=-inf;
		for(i=n;i;i--)
		{
			sx[i]=max(sx[i+1],a[i]);
		}
		z=inf;
		for(i=1;i<=n;i++)
		{
			if(pn[i-1]<a[i])
			{
				z=min(z,a[i]*pn[i-1]);
			}
			if(sx[i+1]>a[i])
			{
				z=min(z,a[i]*sx[i+1]);
			}
		}
		if(z==inf)
		{
			printf("IMPOSSIBLE\n");
			continue;
		}
		printf("%lld\n",z);
	}
}