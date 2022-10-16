#include <bits/stdc++.h>

using namespace std;

long long n,st,fn,d,inf=1e18;

int main()
{
	long long t,rr,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld",&n,&st,&fn,&d);
		z=inf;
		if(fn%d==st%d)
		{
			z=min(z,abs(fn-st)/d);
		}
		if(fn%d==1)
		{
			z=min(z,(st-1+d-1)/d+(fn-1)/d);
		}
		if(fn%d==n%d)
		{
			z=min(z,(n-st+d-1)/d+(n-fn)/d);
		}
		if(z==inf)
		{
			z=-1;
		}
		printf("%lld\n",z);
	}
}