#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=998244353;
ll dp[300001][3],used[300001];
vector<ll> gt[300001];
vector<ll> down[300001];
ll n,m,i,j,k,t,t1,u,v,a,b;
void dfs(ll x)
{
	used[x]=1;
	for (int g : gt[x]) if (!used[g])
	{
		down[x].push_back(g);
		dfs(g);
	}
	if (down[x].size())
	{
	
	ll u=1;
	u=1;
	for (ll g : down[x])
	{
		u*=(dp[g][0]+dp[g][1]);
		u%=MOD;
	}
	dp[x][0]+=u;
	u=1;
	for (ll g : down[x])
	{
		u*=(dp[g][0]+dp[g][2]);
		u%=MOD;
	}
	dp[x][0]+=u;
	u=1;
	for (ll g : down[x])
	{
		u*=(dp[g][0]);
		u%=MOD;
	}
	dp[x][0]-=u;
	dp[x][0]%=MOD;
	dp[x][0]+=MOD;
	dp[x][0]%=MOD;
	
	
	u=1;
	for (ll g : down[x])
	{
		u*=(dp[g][0]+dp[g][1]);
		u%=MOD;
	}
	dp[x][1]+=u;
	u=1;
	for (ll g : down[x])
	{
		u*=(dp[g][0]+dp[g][2]);
		u%=MOD;
	}
	dp[x][1]+=u;
	u=1;
	dp[x][1]%=MOD;
	dp[x][1]+=MOD;
	dp[x][1]%=MOD;
	
	u=1;
	for (ll g : down[x])
	{
		u*=(dp[g][0]+dp[g][1]);
		u%=MOD;
	}
	dp[x][2]+=u;
	}
	else {
	dp[x][0]=1; dp[x][1]=2; dp[x][2]=1;}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for (i=1;i<n;i++)
	{
		cin>>u>>v;
		gt[u].push_back(v);
		gt[v].push_back(u);
	}
	dfs(1);
	for (i=1;i<=n;i++)
	{
//		cout<<i<<": "<<dp[i][0]<<' '<<dp[i][1]<<' '<<dp[i][2]<<endl;
	}
	cout<<(dp[1][0]+MOD-1)%MOD;
}