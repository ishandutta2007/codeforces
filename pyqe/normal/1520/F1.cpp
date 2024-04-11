#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long t,k,lh,rh,md,zz;
	
	scanf("%lld%lld%lld",&n,&t,&d);
	for(lh=1,rh=n;lh<=rh;)
	{
		md=(lh+rh)/2;
		printf("? 1 %lld\n",md);
		fflush(stdout);
		scanf("%lld",&k);
		if(md-k>=d)
		{
			zz=md;
			rh=md-1;
		}
		else
		{
			lh=md+1;
		}
	}
	printf("! %lld\n",zz);
	fflush(stdout);
}