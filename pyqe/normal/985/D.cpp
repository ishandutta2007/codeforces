#include <bits/stdc++.h>

using namespace std;

long long n,d,rb;

int main()
{
	long long i,k,lh,rh,md,zz,sm,rm;
	
	scanf("%lld%lld",&n,&d);
	for(lh=1,rh=2e9;lh<=rh;)
	{
		md=(lh+rh)/2;
		k=min(md,d)-1;
		sm=md*md-k*(k+1)/2;
		if(sm<=n)
		{
			zz=md;
			rm=n-sm;
			lh=md+1;
		}
		else
		{
			rh=md-1;
		}
	}
	printf("%lld\n",zz+max(zz-d,0ll)+(rm+zz-1)/zz);
}