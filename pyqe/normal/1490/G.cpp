#include <bits/stdc++.h>

using namespace std;

long long n,dp[200069];

int main()
{
	long long tt,rrr,t,rr,i,k,sm,w,z;
	
	scanf("%lld",&tt);
	for(rrr=0;rrr<tt;rrr++)
	{
		scanf("%lld%lld",&n,&t);
		sm=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			sm+=k;
			dp[i]=max(dp[i-1],sm);
		}
		for(rr=0;rr<t;rr++)
		{
			scanf("%lld",&k);
			if(sm<=0&&k>dp[n])
			{
				z=-1;
			}
			else
			{
				z=0;
				if(sm>0)
				{
					w=(max(k-dp[n],0ll)+sm-1)/sm;
					z+=w*n;
					k-=w*sm;
				}
				z+=lower_bound(dp+1,dp+n+1,k)-dp;
				z=max(z-1,0ll);
			}
			printf("%lld%c",z," \n"[rr==t-1]);
		}
	}
}