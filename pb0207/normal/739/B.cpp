#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;

const ll N=2e5+1e3+7;

struct node{
	ll ne,to;
	ll w;
}edg[N*2+1];

struct path{
	ll v;
	ll x;
};

bool operator <(path a,path b)
{
	return a.v<b.v||(a.v==b.v&&a.x<b.x);
}

ll n,a[N],head[N],cnt,fa[N],dep[N],ans[N];

vector<path>e;

void build(ll u,ll v,ll w)
{
	++cnt;
	edg[cnt].to=v;
	edg[cnt].w=w;
	edg[cnt].ne=head[u];
	head[u]=cnt;
}

void dfs(ll i)
{
	ans[i]=1;
	ll j=lower_bound(e.begin(),e.end(),path{dep[i]-a[i],0})-e.begin()-1;
	if(j>=0)
		ans[e[j].x]--;
	e.push_back(path{dep[i],i});
	for(ll tmp=head[i];tmp;tmp=edg[tmp].ne)
	{
		ll v=edg[tmp].to;
		dep[v]=dep[i]+edg[tmp].w;
		dfs(v);
		ans[i]+=ans[v];
	}
	e.pop_back();
}

int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(ll i=2;i<=n;i++)
	{
		ll w;
		scanf("%lld%lld",&fa[i],&w);
		build(fa[i],i,w);
	}
	dfs(1);
	for(ll i=1;i<=n;i++)
		printf("%lld ",ans[i]-1);
}