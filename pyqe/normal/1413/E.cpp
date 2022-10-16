#include <bits/stdc++.h>

using namespace std;

long long d,d2,d3,d4;

long long tri(long long x)
{
	return x*(x+1)/2;
}

long long val(long long x)
{
	long long k=max(d4*(x+1)-d3,0ll)/d4;
	
	return d*(x+1)-d2*(d3*k+d4*tri(x-k));
}

int main()
{
	long long t,rr,lh,rh,md,zz;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld",&d,&d2,&d3,&d4);
		if(d>d2*d3)
		{
			printf("-1\n");
			continue;
		}
		for(lh=0,rh=d3;lh<=rh;)
		{
			md=(lh+rh)/2;
			if(val(md)>=val(md+1))
			{
				zz=md;
				rh=md-1;
			}
			else
			{
				lh=md+1;
			}
		}
		printf("%lld\n",val(zz));
	}
}