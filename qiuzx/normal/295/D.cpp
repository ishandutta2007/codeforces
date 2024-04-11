//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define mod 1000000007
#define F first
#define S second
#define ll long long
#define N 2010
using namespace std;
ll n,m,dp[N][N],sum[N],sum2[N],fsum[N][N],fsum2[N][N],fsum3[N][N],ans=0;
void getsum(ll x)
{
	ll i;
	sum[0]=dp[x][0];
	sum2[0]=0;
	for(i=1;i<=m;i++)
	{
		sum[i]=(sum[i-1]+dp[x][i])%mod;
		sum2[i]=(sum2[i-1]+dp[x][i]*i)%mod;
	}
	return;
}
int main(){
	ll i,j;
	cin>>n>>m;
	dp[0][0]=1;
	for(i=2;i<=m;i++)
	{
		dp[1][i]=1;
	}
	getsum(1);
	for(i=2;i<=n;i++)
	{
		for(j=2;j<=m;j++)
		{
			dp[i][j]=((((j+1)*sum[j])%mod)+mod-sum2[j])%mod;
		}
		getsum(i);
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			fsum[i][j]=(fsum[i-1][j]+dp[i][j])%mod;
		}
	}
	for(i=0;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			ans=(ans+fsum[n-i][j]*(m-j+1))%mod;
		}
	}
	for(i=0;i<=n;i++)
	{
		fsum2[i][0]=0;
		fsum3[i][0]=fsum[i][0];
		for(j=1;j<=m;j++)
		{
			fsum2[i][j]=(fsum2[i][j-1]+fsum[i][j]*j)%mod;
			fsum3[i][j]=(fsum3[i][j-1]+fsum[i][j])%mod;
		}
	}
	for(i=0;i<=n;i++)
	{
		for(int k=1;k<=m;k++)
		{
			ll coef=((m-k+1)*fsum[n-i][k])%mod,sum=((((k+1)*fsum3[i][k-1])%mod)+mod-fsum2[i][k-1])%mod;
			ans=(ans+coef*sum)%mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}