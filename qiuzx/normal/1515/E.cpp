#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 410
using namespace std;
ll fact[N],inv[N],mod;
ll ksm(ll x,ll y)
{
	if(y==0)
	{
		return 1;
	}
	ll ret=ksm(x,y>>1);
	ret=(ret*ret)%mod;
	if(y&1)
	{
		ret=(ret*x)%mod;
	}
	return ret;
}
ll GetC(ll x,ll y)
{
	if(x<y)
	{
		return 0;
	}
	return (fact[x]*((inv[y]*inv[x-y])%mod))%mod;
}
ll dp[N],pre_c[N][N],dp2[N][N],n;
ll dfs2(ll x,ll bef)
{
	if(dp2[x][bef]!=-1)
	{
		return dp2[x][bef];
	}
	if(x==0)
	{
		return dp2[x][bef]=1;
	}
	dp2[x][bef]=(dp[x]*pre_c[bef+x][x])%mod;
	ll i;
	for(i=2;i<x;i++)
	{
		dp2[x][bef]=(dp2[x][bef]+((((dp[i-1]*dfs2(x-i,bef+i-1))%mod)*pre_c[bef+i-1][i-1])%mod))%mod;
	}
	return dp2[x][bef];
}
int main(){
	ll i,j;
	scanf("%lld%lld",&n,&mod);
	fact[0]=inv[0]=1;
	for(i=1;i<N;i++)
	{
		fact[i]=(fact[i-1]*i)%mod;
		inv[i]=ksm(fact[i],mod-2);
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			pre_c[i][j]=GetC(i,j);
		}
	}
	memset(dp2,-1,sizeof(dp2));
	dp[0]=dp[1]=1;
	for(i=2;i<N;i++)
	{
		dp[i]=(dp[i-1]*2)%mod;
	}
	printf("%lld\n",dfs2(n,0));
	return 0;
}