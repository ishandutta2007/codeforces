#include <bits/stdc++.h>

using namespace std;

long long n,m,a[5069],dp[5069][5069],wg[5069],dv=1e9+7;

int main()
{
	long long t,rr,i,j,k,l,z=0;
	
	scanf("%lld%lld%lld",&n,&m,&t);
	for(i=1;i<=n;i++)
	{
		dp[0][i]=1;
	}
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%dv;
		}
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		for(j=0;j<=m;j++)
		{
			wg[i]=(wg[i]+dp[j][i]*dp[m-j][i])%dv;
		}
		z=(z+a[i]*wg[i])%dv;
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		z=(z+(l+dv-a[k])*wg[k])%dv;
		a[k]=l;
		printf("%lld\n",z);
	}
}