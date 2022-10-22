#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<ctime>
typedef long long ll;
typedef unsigned un;
typedef std::string str;
typedef std::pair<ll,ll> pll;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
void umax(ll& a,ll t){if(t>a)a=t;}
const ll INF=1ll<<58;
#define MAXN 200011
struct DSU
{
	ll fa[MAXN];
	void build(ll n){for(ll i=1;i<=n;++i)fa[i]=i;}
	ll find(ll x)
	{
		if(fa[x]==x)return x;
		return fa[x]=find(fa[x]);
	}
	bool uni(ll& u,ll& v)
	{
		u=find(u),v=find(v);
		if(u==v)return 1;
		fa[u]=v;return 0;
	}
}s;
bool ring[MAXN],vis[MAXN];
std::vector<ll> a[MAXN];
int main()
{
	ll n=read(),m=read(),ans=0;
	s.build(n);
	while(m--)
	{
		ll u=read(),v=read();
		if(s.uni(u,v))ring[v]=1;
		ring[v]|=ring[u];
	}
	for(ll i=1;i<=n;++i)
		if(s.find(i)==i&&!ring[i])++ans;
	printf("%lld\n",ans );
	return 0;
}