#include <bits/stdc++.h>

using namespace std;

long long n,m,d,pc[169],cb[169][169],dp[169][169][169],dv;

int main()
{
	long long i,j,r,p,p2,c,sm=0;
	
	scanf("%lld%lld%lld%lld",&n,&m,&d,&dv);
	for(j=0,i=1;j<n;i++)
	{
		if(i==1)
		{
			c=1;
		}
		else
		{
			for(c=0;!(i-1>>c&1);c++);
			c=c+1+(1ll<<c==i-1);
		}
		sm+=c;
		for(;j<n&&j<sm;)
		{
			j++;
			pc[j]=i;
		}
	}
	cb[0][0]=1;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=i;j++)
		{
			cb[i][j]=cb[i-1][j];
			if(j)
			{
				cb[i][j]=(cb[i][j]+cb[i-1][j-1])%dv;
			}
		}
	}
	for(i=0;i<=n;i++)
	{
		dp[0][i][0]=1;
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=n-i;j++)
		{
			for(r=0;r<=pc[i];r++)
			{
				for(p=1;p<=i;p++)
				{
					for(p2=r-(j+1==m)-pc[i-p];p2<=pc[p-1];p2++)
					{
						dp[i][j][r]=(dp[i][j][r]+dp[p-1][j+1][p2]*dp[i-p][j+1][r-(j+1==m)-p2]%dv*cb[i-1][p-1])%dv;
					}
				}
			}
		}
	}
	printf("%lld\n",dp[n][0][d]);
}