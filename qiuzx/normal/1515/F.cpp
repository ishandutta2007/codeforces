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
#define N 300010
using namespace std;
ll n,m,a[N],val,fa[N];
bool vis[N],chs[N];
vector<pair<ll,ll> > vt[N];
ll getf(ll x)
{
	if(x==fa[x])
	{
		return x;
	}
	return fa[x]=getf(fa[x]);
}
void dfs(ll x)
{
	ll i;
	vis[x]=true;
	for(i=0;i<vt[x].size();i++)
	{
		if(vis[vt[x][i].F])
		{
			continue;
		}
		dfs(vt[x][i].F);
		if(a[vt[x][i].F]>=val)
		{
			a[x]=a[x]+a[vt[x][i].F]-val;
			fa[getf(x)]=getf(vt[x][i].F);
			printf("%lld\n",vt[x][i].S+1);
		}
	}
	return;
}
void dfs2(ll x)
{
	ll i;
	vis[x]=true;
	for(i=0;i<vt[x].size();i++)
	{
		if(vis[vt[x][i].F])
		{
			continue;
		}
		if(getf(vt[x][i].F)!=getf(x))
		{
			fa[getf(vt[x][i].F)]=getf(x);
			printf("%lld\n",vt[x][i].S+1);
		}
		dfs2(vt[x][i].F);
	}
	return;
}
int main(){
	ll i,x,y,sum=0,ed;
	scanf("%lld%lld%lld",&n,&m,&val);
	for(i=0;i<n;i++)
	{
		fa[i]=i;
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--;
		y--;
		vt[x].push_back(make_pair(y,i));
		vt[y].push_back(make_pair(x,i));
	}
	if(sum<(n-1)*val)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	dfs(0);
	memset(vis,false,sizeof(vis));
	dfs2(0);
	return 0;
}