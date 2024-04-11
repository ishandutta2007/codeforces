#include <bits/stdc++.h>

using namespace std;

const long long ma=100,inf=1e18;
long long n,ttl,ttl2,a[2][169];
bitset<20069> dp[2];

int main()
{
	long long t,rr,i,j,ii,k,mn,z,z2;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		ttl=0;
		ttl2=0;
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n;i++)
			{
				scanf("%lld",&a[ii][i]);
				ttl+=a[ii][i];
				ttl2+=a[ii][i]*a[ii][i];
			}
			for(i=-n*ma;i<=n*ma;i++)
			{
				dp[ii][n*ma+i]=0;
			}
		}
		dp[0][n*ma]=1;
		for(i=1;i<=n;i++)
		{
			k=abs(a[0][i]-a[1][i]);
			for(j=-n*ma;j<=n*ma;j++)
			{
				if(j-k>=-n*ma)
				{
					dp[1][n*ma+j-k]=dp[1][n*ma+j-k]||dp[0][n*ma+j];
				}
				if(j+k<=n*ma)
				{
					dp[1][n*ma+j+k]=dp[1][n*ma+j+k]||dp[0][n*ma+j];
				}
			}
			for(j=-n*ma;j<=n*ma;j++)
			{
				dp[0][n*ma+j]=dp[1][n*ma+j];
				dp[1][n*ma+j]=0;
			}
		}
		mn=inf;
		for(i=-n*ma;i<=n*ma;i++)
		{
			if(dp[0][n*ma+i])
			{
				mn=min(mn,abs(i));
			}
		}
		z=(ttl-mn)/2;
		z2=z+mn;
		printf("%lld\n",z*z+z2*z2+ttl2*(n-2));
	}
}