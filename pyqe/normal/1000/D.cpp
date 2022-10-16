#include <bits/stdc++.h>

using namespace std;

long long n,a[1069],cb[1069][1069],dp[1069],dv=998244353;

int main()
{
	long long i,j,z=0;
	
	scanf("%lld",&n);
	cb[0][0]=1;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		for(j=0;j<=i;j++)
		{
			cb[i][j]=cb[i-1][j];
			if(j)
			{
				cb[i][j]=(cb[i][j]+cb[i-1][j-1])%dv;
			}
		}
	}
	dp[n+1]=1;
	for(i=n;i;i--)
	{
		for(j=i+1;j<=n+1;j++)
		{
			if(a[i]>0&&a[i]<=j-1-i)
			{
				dp[i]=(dp[i]+dp[j]*cb[j-1-i][a[i]])%dv;
			}
		}
		z=(z+dp[i])%dv;
	}
	printf("%lld\n",z);
}