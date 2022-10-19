#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 300010
using namespace std;
ll ksm(ll x,ll y)
{
	ll ret=1;
	while(y>0)
	{
		if(y&1)
		{
			ret=(ret*x)%mod;
		}
		x=(x*x)%mod;
		y>>=1;
	}
	return ret;
}
vector<ll> vt[N];
ll n,dp[N][3];
void dfs(ll x,ll lst)
{
	ll i,prod=1;
	dp[x][2]=1;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst)
		{
			dfs(vt[x][i],x);
			dp[x][2]=(dp[x][2]*(dp[vt[x][i]][2]+dp[vt[x][i]][1]))%mod;
			prod=(prod*((dp[vt[x][i]][2]+2*dp[vt[x][i]][1])%mod))%mod;
		}
	}
	dp[x][0]=prod;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst)
		{
			dp[x][1]=(dp[x][1]+((prod*ksm((dp[vt[x][i]][2]+2*dp[vt[x][i]][1])%mod,mod-2))%mod)*dp[vt[x][i]][0])%mod;
		}
	}
	return;
}
int main(){
	ll i,x,y;
	scanf("%lld",&n);
	for(i=1;i<n;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--;
		y--;
		vt[x].push_back(y);
		vt[y].push_back(x);
	}
	dfs(0,-1);
	printf("%lld\n",(dp[0][2]+dp[0][1])%mod);
	return 0;
}