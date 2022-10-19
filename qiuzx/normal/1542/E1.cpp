#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define F first
#define S second
#define ll long long
#define N 505
using namespace std;
ll n,mod,C[N][N],dp[2][N*N],sum[2][N*N],sum2[N*N],sum3[N*N],ans=0,fact[N];
void getsum(ll x)
{
	ll i;
	sum[x][0]=0;
	for(i=1;i<=n*(n-1)/2+1;i++)
	{
		sum[x][i]=(sum[x][i-1]+dp[x][i-1])%mod;
	}
	return;
}
void getsum2(ll x)
{
	ll i;
	sum2[0]=0;
	for(i=1;i<=n*(n-1)/2+1;i++)
	{
		sum2[i]=(sum2[i-1]+sum[x][i-1])%mod;
	}
	return;
}
void getsum3()
{
	ll i;
	sum3[0]=0;
	for(i=1;i<=n*(n-1)/2+1;i++)
	{
		sum3[i]=(sum3[i-1]+sum2[i-1])%mod;
	}
	return;
}
int main(){
	ll i,j,l,d,v1,trs;
	scanf("%lld%lld",&n,&mod);
	fact[0]=1;
	for(i=1;i<N;i++) fact[i]=(fact[i-1]*i)%mod;
	for(i=0;i<N;i++) C[i][0]=1;
	for(i=1;i<N;i++) for(j=1;j<=i;j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	dp[0][0]=1;
	for(i=0;i<n;i++)
	{
		getsum(i&1);
		getsum2(i&1);
		getsum3();
		l=i+1;
		trs=(C[n][l]*fact[n-l])%mod;
		for(v1=1;v1<=l*(l-1)/2;v1++)
		{
			ans=(ans+((trs*dp[i&1][v1])%mod)*((l*sum2[v1]+mod-sum2[v1>=l?v1-l+1:0]+mod-sum3[v1+1]+sum3[v1+1>=l?v1-l+2:0])%mod))%mod;
		}
		for(j=0;j<=n*(n-1)/2;j++)
		{
			dp[i&1][j]=0;
			dp[(i&1)^1][j]=(dp[(i&1)^1][j]+sum[i&1][j+1]+mod-(j>=i?sum[i&1][j-i]:0))%mod;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
//4 403458273