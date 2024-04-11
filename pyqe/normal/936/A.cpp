#include <bits/stdc++.h>

using namespace std;

long long n,m,d;

int main()
{
	long long lh,rh,md,zz,sm,zm,z;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	m=((n-1)/m+1)*m-n;
	for(lh=1,rh=d*2;lh<=rh;)
	{
		md=(lh+rh)/2;
		sm=(n*2+m)*(md/(n+m))+2*min(md%(n+m),n)+max(md%(n+m)-n,0ll);
		if(sm>=d*2)
		{
			zz=md;
			zm=sm;
			rh=md-1;
		}
		else
		{
			lh=md+1;
		}
	}
	z=zz*2-(zm-d*2);
	printf("%lld.%lld\n",z/2,z%2*5);
}