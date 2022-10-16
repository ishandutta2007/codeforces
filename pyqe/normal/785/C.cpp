#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long i,z,lh,rh,md,zz;
	
	scanf("%lld%lld",&n,&m);
	z=min(n,m);
	n-=z;
	for(lh=0,rh=2e9;lh<=rh;)
	{
		md=(lh+rh)/2;
		if(md*(md+1)/2>=n)
		{
			zz=md;
			rh=md-1;
		}
		else
		{
			lh=md+1;
		}
	}
	printf("%lld\n",z+zz);
}