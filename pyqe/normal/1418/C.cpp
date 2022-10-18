#include <bits/stdc++.h>

using namespace std;

long long n,ps[200069],dp[200069][2],inf=1e18;

int main()
{
	long long t,rr,i,ii,jj,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		dp[0][0]=0;
		dp[0][1]=inf;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			ps[i]=ps[i-1]+k;
			for(ii=0;ii<2;ii++)
			{
				dp[i][ii]=inf;
				for(jj=0;jj<min(i,2ll);jj++)
				{
					dp[i][ii]=min(dp[i][ii],dp[i-1-jj][!ii]+(ps[i]-ps[i-1-jj])*ii);
				}
			}
		}
		printf("%lld\n",min(dp[n][0],dp[n][1]));
	}
}