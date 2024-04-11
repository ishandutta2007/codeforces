#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
typedef long long ll;
typedef unsigned un;
typedef std::vector<int> P;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template <typename T> bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
template <typename T> bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
int abs(int x){return x>0?x:-x;}
/**********/
const int MAXN = 400011;
int p[MAXN],a[MAXN],b[MAXN];
int fa[MAXN],size[MAXN],ms[MAXN],dep[MAXN];
int dfn[MAXN],node[MAXN],cur=0;
std::vector<int>g[MAXN];
void dfs1(int u)
{
	size[u]=1,dfn[u]=++cur,node[cur]=u;
	for(auto v:g[u])
	{
		dep[v]=dep[u]+1,dfs1(v),size[u]+=size[v];
		if(size[v]>size[ms[u]])ms[u]=v;
	}
}
int Top[MAXN];
void dfs2(int s)
{
	for(int u=s;u;u=ms[u])Top[u]=s;
	for(int u=s;u;u=ms[u])
		for(auto v:g[u])
			if(v!=ms[u])dfs2(v);
}
int LCA(int u,int v)
{
	while(Top[u]!=Top[v])
	{
		if(dep[Top[u]]>=dep[Top[v]])u=fa[Top[u]];
		else v=fa[Top[v]];
	}
	return dep[u]>dep[v]?v:u;
}
ll val[MAXN];
ll dist(int u,int v)
{
	return val[u]+val[v]-2*val[LCA(u,v)];
}
int stk[MAXN],top=0;
std::set<int>s;
ll ans;
bool must[MAXN];
int son[MAXN];
void Add(int x)
{
	auto it=s.lower_bound(dfn[x]),tp=it;
	int pre=node[(it==s.begin()?*s.rbegin():*--tp)];
	int nxt=node[(it==s.end()?*s.begin():*it)];
	ans-=dist(pre,nxt);
	ans+=dist(pre,x)+dist(x,nxt);
	s.insert(dfn[x]);
}
void Remove(int x)
{
	s.erase(dfn[x]);
	auto it=s.lower_bound(dfn[x]),tp=it;
	int pre=node[(it==s.begin()?*s.rbegin():*--tp)];
	int nxt=node[(it==s.end()?*s.begin():*it)];
	ans-=dist(pre,x)+dist(x,nxt),ans+=dist(pre,nxt);
}
int main()
{
	int n=read(),m=read(),R=n+1;
	for(int i=1;i<=n;++i)p[i]=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i)b[i]=read();
	stk[0]=R;
	for(int i=1;i<=n;++i)
	{
		while(top&&p[stk[top]]<=p[i])--top;
		fa[i]=stk[top],stk[++top]=i;
		val[i]=a[i]-b[i],val[fa[i]]+=b[i];
		g[fa[i]].push_back(i);
	}
	for(int i=n;i;--i)
		if(val[i]<0)val[fa[i]]+=val[i],val[i]=0;
	for(int i=1;i<=n;++i)val[i]+=val[fa[i]];
	dfs1(R),dfs2(R);
	ans=0;
	son[R]=1000000000;
	s.insert(dfn[R]);
	while(m--)
	{
		int x=read();
		if(must[x])
		{
			if(!--son[fa[x]])Remove(fa[x]);
		}
		else
		{
			if(!son[fa[x]]++)Add(fa[x]);
		}
		must[x]^=1;
		printf("%lld\n",(ans>>1)+val[R]);
	}
	return 0;
}