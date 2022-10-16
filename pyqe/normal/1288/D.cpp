#include <bits/stdc++.h>

using namespace std;

long long n,m,a[300069][8],sr[269];
bitset<269> dp;

int main()
{
	long long i,j,mk,mkk,lh,rh,md,zz,e1,e2,ze1,ze2;
	bool bad;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	for(lh=0,rh=1e9;lh<=rh;)
	{
		md=(lh+rh)/2;
		dp.reset();
		for(i=1;i<=n;i++)
		{
			mk=0;
			for(j=0;j<m;j++)
			{
				mk+=(a[i][j]>=md)<<j;
			}
			dp[mk]=1;
			sr[mk]=i;
		}
		for(mk=(1<<m)-1;mk>=0;mk--)
		{
			if(dp[mk])
			{
				for(i=0;i<m;i++)
				{
					if((mk>>i)%2)
					{
						mkk=mk-(1<<i);
						dp[mkk]=1;
						sr[mkk]=sr[mk];
					}
				}
			}
		}
		bad=1;
		for(mk=0;mk<1<<m;mk++)
		{
			mkk=(1<<m)-1-mk;
			if(dp[mk]&&dp[mkk])
			{
				bad=0;
				e1=sr[mk];
				e2=sr[mkk];
				break;
			}
		}
		if(!bad)
		{
			zz=md;
			ze1=e1;
			ze2=e2;
			lh=md+1;
		}
		else
		{
			rh=md-1;
		}
	}
	printf("%lld %lld\n",ze1,ze2);
}