#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long lh,rh,md,zz;
	
	scanf("%lld%lld",&n,&d);
	d%=n*(n+1)/2;
	for(lh=0,rh=n;lh<=rh;)
	{
		md=(lh+rh)/2;
		if(md*(md+1)/2<=d)
		{
			zz=md;
			lh=md+1;
		}
		else
		{
			rh=md-1;
		}
	}
	printf("%lld\n",d-zz*(zz+1)/2);
}