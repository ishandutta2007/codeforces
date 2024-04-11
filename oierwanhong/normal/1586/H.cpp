#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
typedef unsigned un;
typedef long long ll;
typedef std::pair<int,int> pii;
ll read(){ll x=0;bool f=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f?-x:x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template<typename T> inline bool umin(T& a,T b){if(b<a)return a=b,1;return 0;}
template<typename T> inline bool umax(T& a,T b){if(b>a)return a=b,1;return 0;}
/**********/
const int MAXN = 800011;
struct Kedge
{
	int u,v,w,val;
}ke[MAXN];
bool cmpW(Kedge a,Kedge b){return a.w>b.w;}
bool cmpV(Kedge a,Kedge b){return a.val<b.val;}
struct DSU
{
	int fa[MAXN];
	void init(int n){for(int i=1;i<=n;++i)fa[i]=i;}
	int find(int x)
	{
		if(fa[x]==x)return x;
		return fa[x]=find(fa[x]);
	}
	void uni(int x,int y){fa[find(x)]=find(y);}
}dsu;
std::vector<int>ta[MAXN],tb[MAXN];

int va[MAXN],vb[MAXN],size[MAXN],dep[MAXN],ms[MAXN], pre[MAXN],top[MAXN];
int fa[20][MAXN];
int RA,RB;

void dfs1(int u)
{
	size[u]=1;
	for(auto v:tb[u])
	{
		pre[v]=u,dep[v]=dep[u]+1,dfs1(v),size[u]+=size[v];
		if(size[v]>size[ms[u]])ms[u]=v;
	}
}
void dfs2(int u,int now_top)
{
	top[u]=now_top;
	if(ms[u])dfs2(ms[u],now_top);
	for(auto v:tb[u])
		if(v!=ms[u])dfs2(v,v);
}
int Qmax(int u,int v)
{
	while(top[u]!=top[v])
		if(dep[top[u]]>=dep[top[v]])u=pre[top[u]];
		else v=pre[top[v]];
	return dep[u]>dep[v]?vb[v]:vb[u];
}
void Kruskal(int n,int m)
{
	dsu.init(n+n),std::sort(ke+1,ke+m+1,cmpW);
	RA=n;
	for(int i=1;i<=m;++i)
	{
		int u=dsu.find(ke[i].u),v=dsu.find(ke[i].v);
		if(u!=v)
		{
			va[++RA]=ke[i].w,dsu.uni(u,RA),dsu.uni(v,RA),ta[RA].emplace_back(u),ta[RA].emplace_back(v),fa[0][u]=fa[0][v]=RA;
		}
	}
	for(int k=1;k<20;++k)
		for(int u=1;u<=RA;++u)fa[k][u]=fa[k-1][fa[k-1][u]];
	dsu.init(n+n),std::sort(ke+1,ke+m+1,cmpV);
	RB=n;
	for(int i=1;i<=m;++i)
	{
		int u=dsu.find(ke[i].u),v=dsu.find(ke[i].v);
		if(u!=v)vb[++RB]=ke[i].val,dsu.uni(u,RB),dsu.uni(v,RB),tb[RB].emplace_back(u),tb[RB].emplace_back(v);
	}
	dfs1(RB),dfs2(RB,RB);
}
std::vector<int>Q[MAXN];
int p[MAXN],a[MAXN],f[MAXN],st[MAXN];
pii res[MAXN];
void dfs3(int u)
{
	p[u]=u;
	for(auto v:ta[u])
	{
		dfs3(v);
		if(a[p[v]]>a[p[u]])p[u]=p[v],f[u]=f[v];
		else if(a[p[v]]==a[p[u]])umax(f[u],f[v]),umax(f[u],Qmax(p[u],p[v]));
	}
	for(auto x:Q[u])
	{
		res[x]=pii(p[u],f[u]);
	}
}
int main()
{
	int n=read(),m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<n;++i)ke[i].u=read(),ke[i].v=read(),ke[i].w=read(),ke[i].val=read();
	Kruskal(n,n-1);
	for(int i=1;i<=m;++i)
	{
		int c=read(),u=read();
		st[i]=u;
		for(int k=19;k>=0;--k)
			if(va[fa[k][u]]>=c)u=fa[k][u];
		Q[u].emplace_back(i);
	}
	dfs3(RA);
	for(int i=1;i<=m;++i)
	{
		printf("%d %d\n",a[res[i].first],std::max(res[i].second,Qmax(res[i].first,st[i])));
	}
	return 0;
}