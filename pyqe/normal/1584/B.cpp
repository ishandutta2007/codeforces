#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,m;

long long val(long long x,long long y)
{
	long long ii,z=inf;
	
	for(ii=0;ii<2;ii++)
	{
		if(x<3)
		{
			z=min(z,y);
		}
		else
		{
			z=min(z,val(x%3,y)+x/3*y);
		}
		swap(x,y);
	}
	return z;
}

int main()
{
	long long t,rr;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		printf("%lld\n",val(n,m));
	}
}