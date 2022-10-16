#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],sq[200069],zs,inf=1e18;
bitset<200069> vtd,dp[2];

int main()
{
	long long t,rr,i,ii,u,c,mx;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		for(ii=0;ii<2;ii++)
		{
			u=!ii*2-1;
			c=0;
			mx=-inf;
			for(i=1;i<=n;i++)
			{
				vtd[i]=0;
			}
			bad=0;
			for(i=1+(n-1)*ii;i&&i<=n;i+=u)
			{
				c++;
				mx=max(mx,a[i]);
				bad|=vtd[a[i]];
				vtd[a[i]]=1;
				dp[ii][i]=(c==mx)&&!bad;
			}
		}
		zs=0;
		for(i=1;i<=n-1;i++)
		{
			if(dp[0][i]&&dp[1][i+1])
			{
				zs++;
				sq[zs]=i;
			}
		}
		printf("%lld\n",zs);
		for(i=1;i<=zs;i++)
		{
			printf("%lld %lld\n",sq[i],n-sq[i]);
		}
	}
}