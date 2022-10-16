#include <bits/stdc++.h>

using namespace std;

const long long sqn=500,inf=1e18;
long long n,ps[100069],dp[100069][569];

int main()
{
	long long t,rr,i,j;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",ps+i);
			ps[i]+=ps[i-1];
		}
		for(i=0;i<=sqn;i++)
		{
			dp[n+1][i]=0;
		}
		dp[n+1][0]=inf;
		for(i=n;i;i--)
		{
			for(j=0;j<=sqn;j++)
			{
				dp[i][j]=dp[i+1][j];
				if(j&&i+j-1<=n&&dp[i+j][j-1]>ps[i+j-1]-ps[i-1])
				{
					dp[i][j]=max(dp[i][j],ps[i+j-1]-ps[i-1]);
				}
			}
		}
		for(i=sqn;!dp[1][i];i--);
		printf("%lld\n",i);
	}
}