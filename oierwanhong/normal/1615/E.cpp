#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
typedef long long ll;
typedef std::pair<int,int> pii;
ll read()
{
	ll f=1,x=0;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template<typename T> inline bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
template<typename T> inline bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
/**********/
const int MAXN = 400011,INF = 1e9+233;
std::vector<int>g[MAXN];
bool vis[MAXN];
int ms[MAXN],fa[MAXN],size[MAXN];
void dfs(int u)
{
	size[u]=1;
	for(auto v:g[u])
		if(v!=fa[u])
		{
			fa[v]=u,dfs(v),size[u]+=size[v];
			if(size[v]>size[ms[u]])ms[u]=v;
		}
}
std::set<pii>s;
int main()
{
	int n=read(),k=read();
	for(int i=1;i<n;++i){int u=read(),v=read();g[u].emplace_back(v),g[v].emplace_back(u);}
	dfs(1);
	for(int i=1;i<=n;++i)s.insert(pii(size[i],i));
	ll ans=-1e18,rest=n;
	for(int r=1;r<=k;++r)
	{
		if(s.empty()){umax(ans,ll(n-r)*r);continue;}
		int u=(--s.end())->second,p=u;
		while(ms[p])p=ms[p];
		while(p&&!vis[p])
		{
			--rest,vis[p]=1,s.erase(pii(size[p],p)),p=fa[p];
		}
		if(s.empty()){umax(ans,ll(n-r)*r);continue;}
		else
		{
			ll p=min(n/2,rest);
			umax(ans,ll(n-r-p)*(r-p));
		}
	}
	printf("%lld\n",ans);
	return 0;
}