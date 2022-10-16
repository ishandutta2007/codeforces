#include <bits/stdc++.h>

using namespace std;

long long n,d,ma=1e5,a[1069],dp[1069][1069],dv=998244353;

int main()
{
	long long i,j,r,p,sm,ls=0,z=0;
	
	scanf("%lld%lld",&n,&d);
	d--;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(i=ma/d;i;i--)
	{
		for(j=0;j<=d;j++)
		{
			dp[0][j]=0;
		}
		sm=0;
		for(r=0,j=1;j<=n;j++)
		{
			for(;r<n&&a[r+1]+i<=a[j];)
			{
				r++;
				for(p=0;p<=d;p++)
				{
					dp[r][p]=(dp[r][p]+dp[r-1][p])%dv;
				}
			}
			for(p=1;p<=d;p++)
			{
				dp[j][p]=dp[r][p-1];
			}
			dp[j][0]=1;
			sm=(sm+dp[j][d])%dv;
		}
		z=(z+i*(sm+dv-ls))%dv;
		ls=sm;
	}
	printf("%lld\n",z);
}