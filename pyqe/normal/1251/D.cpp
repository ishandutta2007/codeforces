#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d;
pair<long long,long long> a[200069];

int main()
{
	long long t,rr,i,z,c,lh,rh,md,zz;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=0;i<n;i++)
		{
			scanf("%lld%lld",&a[i].fr,&a[i].sc);
		}
		sort(a,a+n);
		lh=0;
		rh=d;
		for(md=(lh+rh)/2;lh<=rh;md=(lh+rh)/2)
		{
			z=0;
			c=0;
			for(i=n-1;i>=0;i--)
			{
				if(a[i].sc<md||c+c>n)
				{
					z+=a[i].fr;
				}
				else
				{
					z+=max(a[i].fr,md);
					c++;
				}
			}
			if(z>d||c+c<=n)
			{
				rh=md-1;
			}
			else
			{
				zz=md;
				lh=md+1;
			}
		}
		printf("%lld\n",zz);
	}
}