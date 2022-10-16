#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,ii,u,k,p,lh,rh,md,zz;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		k=n/2;
		p=1;
		for(;k<n-1;)
		{
			p+=(k+n)/2-k;
			for(ii=0;ii<2;ii++)
			{
				k=(k+n)/2;
			}
		}
		printf("? %lld\n",p);
		fflush(stdout);
		scanf("%lld",&k);
		u=1;
		zz=n;
		for(lh=1,rh=n-1;lh<=rh;u*=-1)
		{
			md=(lh+rh)/2;
			p+=md*u;
			printf("? %lld\n",p);
			fflush(stdout);
			scanf("%lld",&k);
			if(k)
			{
				zz=md;
				rh=md-1;
			}
			else
			{
				lh=md+1;
			}
		}
		printf("= %lld\n",zz);
		fflush(stdout);
	}
}