#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long t,rr,i,xr,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		xr=0;
		for(i=n/4*4;i<n;i++)
		{
			xr^=i;
		}
		z=n+(xr!=m)+((xr^m)==n);
		printf("%lld\n",z);
	}
}