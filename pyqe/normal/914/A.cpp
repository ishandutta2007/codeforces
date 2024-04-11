#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n;

int main()
{
	long long i,k,lh,rh,md,zz,z=-inf;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		for(zz=-1,lh=0,rh=k;lh<=rh;)
		{
			md=(lh+rh)/2;
			if(md*md<=k)
			{
				zz=md;
				lh=md+1;
			}
			else
			{
				rh=md-1;
			}
		}
		if(zz*zz!=k)
		{
			z=max(z,k);
		}
	}
	printf("%lld\n",z);
}