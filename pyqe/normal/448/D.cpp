#include <bits/stdc++.h>

using namespace std;

long long n,m,d;

int main()
{
	long long i,j,lh,rh,md,z,k;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	lh=1;
	rh=n*m;
	for(;lh<=rh;)
	{
		md=(lh+rh)/2;
		k=0;
		for(i=1;i<=n;i++)
		{
			k+=min(m,md/i);
		}
		if(k>=d)
		{
			z=md;
			rh=md-1;
		}
		else
		{
			lh=md+1;
		}
	}
	printf("%lld\n",z);
}