#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,a[5069],dp[5069],fq[5069];

int main()
{
	long long t,rr,i,j,mx;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		for(i=0;i<=n+1;i++)
		{
			dp[i]=-inf;
		}
		dp[0]=0;
		for(i=0;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				fq[j]=0;
			}
			mx=0;
			for(j=i+1;j<=n+1;j++)
			{
				if((j-1-i)%2==0&&mx*2<=j-1-i&&(!i||j>n||a[j]==a[i]))
				{
					dp[j]=max(dp[j],dp[i]+1);
				}
				if(j<=n)
				{
					fq[a[j]]++;
					mx=max(mx,fq[a[j]]);
				}
			}
		}
		printf("%lld\n",dp[n+1]-1);
	}
}