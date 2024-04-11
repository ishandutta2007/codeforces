#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
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
struct DSU
{
	int fa[MAXN];
	void init(int n){for(int i=1;i<=n;++i)fa[i]=i;}
	int find(int x)
	{
		if(fa[x]==x)return x;
		return fa[x]=find(fa[x]);
	}
	void uni(int x,int y)
	{
		x=find(x),y=find(y);
		if(x==y)return;
		fa[x]=y;
	}
}dsu;
std::vector<int>g[MAXN];
int fa[MAXN],val[MAXN],dfn[MAXN],ed[MAXN],cur=0;
struct BIT
{
	int t[MAXN];
#define lowb (i&-i)
	void modify(int i,int k)
	{
		while(i<=cur)t[i]+=k,i+=lowb;
	}
	int Qsum(int i)
	{
		int res=0;
		while(i)res+=t[i],i-=lowb;
		return res;
	}
}ts,tc;
void dfs(int u)
{
	dfn[u]=++cur,val[u]=g[u].size()-(u!=1);
	for(auto v:g[u])
		if(v!=fa[u])
		{
			fa[v]=u,dfs(v);
		}
	ed[u]=cur;
}
void Add(int u,int p,int vk,int ck)
{
	ts.modify(dfn[fa[u]],vk);
	if(fa[p])ts.modify(dfn[fa[p]],-vk);
	tc.modify(dfn[fa[u]],ck);
	if(fa[p])tc.modify(dfn[fa[p]],-ck);
}
int Qval(int u){return val[u]+ts.Qsum(ed[u])-ts.Qsum(dfn[u]-1);}
int Qcnt(int u){return tc.Qsum(ed[u])-tc.Qsum(dfn[u]-1);}
struct one
{
	int u,k,dex;
	bool operator< (const one& you)const{return k>you.k;}
}a[MAXN];
int res[MAXN];
std::set<pii>s;
void adds(int u)
{
	s.insert(pii(-((Qval(u)-1)/(Qcnt(u)+1)),u));
}
void dels(int u)
{
	s.erase(pii(-((Qval(u)-1)/(Qcnt(u)+1)),u));
}
int main()
{
	int n=read();
	for(int i=1;i<n;++i){int u=read(),v=read();g[u].emplace_back(v),g[v].emplace_back(u);}
	dfs(1);
	int q=read();
	for(int i=1;i<=q;++i)a[i].u=read(),a[i].k=read(),a[i].dex=i;
	std::sort(a+1,a+q+1);
	dsu.init(n);
	for(int u=1;u<=n;++u)
		if(fa[u])adds(u);
	for(int i=1;i<=q;++i)
	{
		int k=a[i].k,r=a[i].u;
		while(s.size()&&-s.begin()->first >=k)
		{
			int u=s.begin()->second,p=dsu.find(fa[u]);
			//printf("u=%d,val=%d\n",u,val[u]-1);
			s.erase(s.begin());
			if(p!=1)dels(p);
			Add(u,p,Qval(u)-1,Qcnt(u)+1);
			dsu.uni(u,p);
			if(p!=1)adds(p);
		}
		res[a[i].dex]=Qval(r)-ll(Qcnt(r))*k;
	}
	for(int i=1;i<=q;++i)printf("%d\n",res[i]);
	return 0;
}