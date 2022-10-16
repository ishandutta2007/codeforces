#include <bits/stdc++.h>

using namespace std;

const long long ma=1e9;
long long n;

int main()
{
	long long lh,rh,md,zz;
	
	scanf("%lld",&n);
	for(lh=1,rh=ma*2;lh<=rh;)
	{
		md=(lh+rh)/2;
		if((md-1)/2+max(md/4-1,0ll)>=n)
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