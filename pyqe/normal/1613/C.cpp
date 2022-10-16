#include <bits/stdc++.h>

using namespace std;

const long long inf=2e18;
long long n,d,a[100069];

int main()
{
	long long t,rr,i,lh,rh,md,zz,sm;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		a[n+1]=inf;
		for(lh=1,rh=d;lh<=rh;)
		{
			md=(lh+rh)/2;
			sm=0;
			for(i=1;i<=n;i++)
			{
				sm+=min(md,a[i+1]-a[i]);
			}
			if(sm>=d)
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