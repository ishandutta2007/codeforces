#include <bits/stdc++.h>

using namespace std;

long long n,m;

inline long long tri(long long x)
{
	return x*(x+1)/2;
}

int main()
{
	long long t,rr,lh,rh,md,zz,sm;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(zz=n*2-1,lh=1,rh=n*2-1;lh<=rh;)
		{
			md=(lh+rh)/2;
			if(md<=n)
			{
				sm=tri(md);
			}
			else
			{
				sm=tri(n)+tri(n-1)-tri(n*2-1-md);
			}
			if(sm>=m)
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