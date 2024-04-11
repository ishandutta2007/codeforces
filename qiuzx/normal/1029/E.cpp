//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
ll n,dp[N][2][2],dep[N],ans=0;
vector<ll> vt[N];
void dfs(ll x,ll lst,ll d)
{
	dep[x]=d;
	ll i,ori=0;
	dp[x][1][1]=(d>1);
	dp[x][0][0]=0;
	dp[x][0][1]=INF;
	dp[x][1][0]=INF;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]==lst)
		{
			continue;
		}
		dfs(vt[x][i],x,d+1);
		dp[x][1][1]+=min(min(dp[vt[x][i]][0][0],dp[vt[x][i]][0][1]),dp[vt[x][i]][1][1]);
		ori+=min(dp[vt[x][i]][0][1],dp[vt[x][i]][1][1]);
		dp[x][0][0]+=dp[vt[x][i]][0][1];
	}
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst)
		{
			dp[x][0][1]=min(dp[x][0][1],ori-min(dp[vt[x][i]][0][1],dp[vt[x][i]][1][1])+dp[vt[x][i]][1][1]);
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
	dfs(0,-1,0);
	printf("%lld\n",min(dp[0][0][1],dp[0][1][1]));
	return 0;
}