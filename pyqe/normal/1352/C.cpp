#include <bits/stdc++.h>

using namespace std;

long long n,d,inf=1e18;

int main()
{
	long long t,rr,i,lh,rh,md,zz;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(lh=1,rh=inf;lh<=rh;)
		{
			md=(lh+rh)/2;
			if(md-md/n>=d)
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