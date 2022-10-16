#include <bits/stdc++.h>

using namespace std;

long long n,d,a[200069],dv[2],w[2];

int main()
{
	long long t,rr,i,ii,lh,rh,md,zz,z,c,lm;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",a+i);
			a[i]/=100;
		}
		sort(a,a+n,greater<long long>());
		for(ii=0;ii<2;ii++)
		{
			scanf("%lld%lld",w+ii,dv+ii);
		}
		if(w[0]<w[1])
		{
			swap(w[0],w[1]);
			swap(dv[0],dv[1]);
		}
		scanf("%lld",&d);
		lm=dv[0]/__gcd(dv[0],dv[1])*dv[1];
		lh=0;
		rh=n;
		zz=-1;
		for(;lh<=rh;)
		{
			md=(lh+rh)/2;
			z=0;
			c=0;
			for(i=0;i<md/lm;i++,c++)
			{
				z+=a[c]*(w[0]+w[1]);
			}
			for(i=0;i<md/dv[0]-md/lm;i++,c++)
			{
				z+=a[c]*(w[0]);
			}
			for(i=0;i<md/dv[1]-md/lm;i++,c++)
			{
				z+=a[c]*(w[1]);
			}
			if(z>=d)
			{
				zz=md;
				rh=md-1;
			}
			else
			{
				lh=md+1;
			}
		}
		printf("%lld\n",zz);
	}
}