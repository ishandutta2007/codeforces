#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],dp[2][200069];

int main()
{
	long long t,rr,i,ii,u;
	
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
			dp[ii][(n+1)*ii]=0;
			for(i=1+(n-1)*ii;i&&i<=n;i+=u)
			{
				if(dp[ii][i-u]!=-1&&dp[ii][i-u]<=a[i])
				{
					dp[ii][i]=a[i]-dp[ii][i-u];
				}
				else
				{
					dp[ii][i]=-1;
				}
			}
		}
		for(i=1;i<n;i++)
		{
			if(dp[0][i-1]!=-1&&dp[1][i+2]!=-1&&dp[0][i-1]<=a[i+1]&&dp[1][i+2]<=a[i]&&a[i+1]-dp[0][i-1]==a[i]-dp[1][i+2])
			{
				break;
			}
		}
		if(i<n||!dp[0][n])
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}