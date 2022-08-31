#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
struct edge
{
	int v,nxt;
}e[500005];
int n,h[100005],t,d[100005];
ll a[100005],ans;
map<ll,int> b[100005];
ll gcd(ll x,ll y)
{
	if(!y) return x;
	return gcd(y,x%y);
}
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa,int dep)
{
	d[u]=dep;
	if(u!=1)
	{
		b[u][a[u]]=u;
		for(map<ll,int>::iterator i=b[fa].begin();i!=b[fa].end();i++)
		{
			ll val=gcd(i->first,a[u]);
			int id=i->second;
			if(!b[u].count(val)) b[u][val]=id;
			else if(d[b[u][val]]>d[id]) b[u][val]=id;
		}
	}
	ll nw=0,tnw=d[u];
	for(map<ll,int>::iterator i=b[u].begin();i!=b[u].end();i++)
	{
		ll val=i->first;
		int id=i->second;
		if(!val) tnw=d[id]-1;
		ans=(ans+1ll*(val-nw)%mod*(tnw-d[id]+1)%mod)%mod;
		nw=val;
	}
	//printf("u=%d,ans=%I64d\n",u,ans);
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u,dep+1);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	b[1][a[1]]=1;
	dfs(1,0,1);
	printf("%I64d",ans);
	return 0;
}