#include <bits/stdc++.h>

using namespace std;

long long ub,n,d,d2,m;

int main()
{
	long long lh,rh,md,zz;
	
	scanf("%lld%lld%lld%lld%lld",&ub,&n,&d,&d2,&m);
	for(lh=0,rh=ub;lh<=rh;)
	{
		md=(lh+rh)/2;
		if(min(d,md)*((n+1)/2)+min(d2,md)*(n/2)>=m*md)
		{
			zz=md;
			lh=md+1;
		}
		else
		{
			rh=md-1;
		}
	}
	printf("%lld\n",zz);
}