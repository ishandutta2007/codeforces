#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,m,ttl,a[1000069],mn[1000069];
bitset<1000069> kd;

int main()
{
	long long t,rr,i,ii,k,gd,z[2];
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		ttl=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			ttl+=abs(a[i]);
		}
		gd=0;
		for(i=0;i<m;i++)
		{
			scanf("%lld",&k);
			gd=__gcd(gd,k);
		}
		for(i=0;i<gd;i++)
		{
			kd[i]=0;
			mn[i]=inf;
		}
		for(i=1;i<=n;i++)
		{
			kd[i%gd]=kd[i%gd]^a[i]<0;
			mn[i%gd]=min(mn[i%gd],abs(a[i]));
		}
		for(ii=0;ii<2;ii++)
		{
			z[ii]=0;
		}
		for(i=0;i<gd;i++)
		{
			z[kd[i]]+=mn[i];
		}
		printf("%lld\n",ttl-min(z[0],z[1])*2);
	}
}