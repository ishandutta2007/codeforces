#include <bits/stdc++.h>

using namespace std;

const long long ma=1e3;
long long n,a[10069];
bitset<2069> dp,ca;

int main()
{
	long long t,rr,i,lh,rh,md,zz;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		for(lh=0,rh=ma*2;lh<=rh;)
		{
			md=(lh+rh)/2;
			ca.reset();
			for(i=0;i<=md;i++)
			{
				ca[i]=1;
			}
			dp=ca;
			for(i=1;i<=n;i++)
			{
				dp=(dp<<a[i]|dp>>a[i])&ca;
			}
			if(dp.any())
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
}