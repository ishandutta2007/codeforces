#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 200
using namespace std;
ll n,k,d[N],dist[N][N],dp[N][N],mn[N],path[N],ans[N];
vector<ll> vt[N];
void getdist(ll x,ll lst,ll dst,ll beg)
{
	dist[beg][x]=dst;
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst)
		{
			getdist(vt[x][i],x,dst+1,beg);
		}
	}
	return;
}
void dfs(ll x,ll lst)
{
	ll i,j;
	for(i=0;i<n;i++)
	{
		dp[x][i]=d[dist[x][i]]+k;
	}
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst)
		{
			dfs(vt[x][i],x);
			for(j=0;j<n;j++)
			{
				dp[x][j]+=min(mn[vt[x][i]],dp[vt[x][i]][j]-k);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(mn[x]>dp[x][i])
		{
			mn[x]=dp[x][i];
			path[x]=i;
		}
	}
	return;
}
void getpath(ll x,ll lst)
{
	if(lst==-1||mn[x]<dp[x][ans[lst]]-k)
	{
		ans[x]=path[x];
	}
	else
	{
		ans[x]=ans[lst];
	}
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst)
		{
			getpath(vt[x][i],x);
		}
	}
	return;
}
int main(){
	ll i,x,y;
	scanf("%lld%lld",&n,&k);
	for(i=1;i<n;i++)
	{
		scanf("%lld",&d[i]);
	}
	for(i=1;i<n;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--;
		y--;
		vt[x].push_back(y);
		vt[y].push_back(x);
	}
	for(i=0;i<n;i++)
	{
		getdist(i,-1,0,i);
	}
	memset(mn,63,sizeof(mn));
	dfs(0,-1);
	printf("%lld\n",mn[0]);
	getpath(0,-1);
	for(i=0;i<n;i++)
	{
		printf("%lld ",ans[i]+1);
	}
	puts("");
	return 0;
}