#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,ps[100069],inf=1e18;
pair<long long,long long> a[100069];

int main()
{
	long long t,rr,i,p,sm,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&d,&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld%lld",&a[i].fr,&a[i].sc);
		}
		sort(a+1,a+n+1);
		for(i=1;i<=n;i++)
		{
			ps[i]=ps[i-1]+a[i].fr;
		}
		z=-inf;
		for(i=1;i<=n;i++)
		{
			p=max((long long)(upper_bound(a+1,a+n+1,mp(a[i].sc,0ll))-a-1),n-d);
			sm=a[i].sc*(d-(n-p))+ps[n]-ps[p];
			if(a[i].fr<=a[i].sc)
			{
				if(p>n-d)
				{
					sm-=a[i].sc;
				}
				else
				{
					sm-=a[p+1].fr;
				}
				sm+=a[i].fr;
			}
			z=max(z,sm);
		}
		printf("%lld\n",z);
	}
}