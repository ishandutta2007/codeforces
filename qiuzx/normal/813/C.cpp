#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
ll n,st,dep[N],par[N],mx=0;
vector<ll> vt[N];
void dfs(ll x,ll lst,ll d)
{
	dep[x]=d;
	par[x]=lst;
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst)
		{
			dfs(vt[x][i],x,d+1);
		}
	}
	return;
}
void dfs2(ll x)
{
	mx=max(mx,dep[x]);
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=par[x])
		{
			dfs2(vt[x][i]);
		}
	}
	return;
}
int main(){
	ll i,x,y;
	scanf("%lld%lld",&n,&st);
	st--;
	for(i=1;i<n;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--;
		y--;
		vt[x].push_back(y);
		vt[y].push_back(x);
	}
	dfs(0,-1,0);
	x=st;
	y=0;
	while(y+1<dep[par[x]])
	{
		x=par[x];
		y++;
	}
	dfs2(x);
	printf("%lld\n",2*mx);
	return 0;
}