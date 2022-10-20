#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define mod 1000000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 310
using namespace std;
ll n,q,tot,a[N],sum[N],deg[N],mn_val=0,dp[100010];
bool vis[N];
vector<ll> vt[N];
void dfs(ll x)
{
	vis[x]=true;
	if(vt[x].size()==0)
	{
		sum[x]=a[x];
		mn_val+=sum[x];
		return;
	}
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		if(vis[vt[x][i]])
		{
			puts("0");
			exit(0);
		}
		dfs(vt[x][i]);
		sum[x]+=sum[vt[x][i]]+a[x];
	}
	mn_val+=sum[x];
	return;
}
int main(){
	ll i,j,x,y;
	scanf("%lld%lld%lld",&n,&q,&tot);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(i=0;i<q;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--;
		y--;
		vt[y].push_back(x);
		deg[x]++;
	}
	for(i=0;i<n;i++)
	{
		if(deg[i]==0)
		{
			dfs(i);
			mn_val-=sum[i];
		}
	}
	for(i=0;i<n;i++)
	{
		if(!vis[i])
		{
			puts("0");
			return 0;
		}
	}
	if(mn_val>tot)
	{
		puts("0");
		return 0;
	}
	tot-=mn_val;
	dp[0]=1;
	for(j=0;j<n;j++)
	{
		for(i=0;i+sum[j]<=tot;i++)
		{
			dp[i+sum[j]]=(dp[i+sum[j]]+dp[i])%mod;
		}
	}
	printf("%lld\n",dp[tot]);
	return 0;
}