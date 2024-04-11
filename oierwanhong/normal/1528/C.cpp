//By OIerwanhong ,7/9
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

const int MAXN = 300011,mod = 998244353;
std::vector<int>a[MAXN],b[MAXN];
int st[MAXN],ed[MAXN],cur,n;
namespace LCT
{
	int fa[MAXN],son[MAXN][2];
	bool sum[MAXN],val[MAXN];
	void dfs(int u)
	{
		st[u]=++cur;
		for(auto v:b[u])fa[v]=u,dfs(v);
		ed[u]=cur;
	}
	void init(int n)
	{
		for(int i=1;i<=n;++i)fa[i]=son[i][0]=son[i][1]=0,sum[i]=val[i]=0;
		cur=0;
		dfs(1);
	}
	bool not_root(int x){return son[fa[x]][0]==x||son[fa[x]][1]==x;}
	void pushup(int x){sum[x]=sum[son[x][0]]|sum[son[x][1]]|val[x];}
	void rotate(int x)
	{
		int y=fa[x],z=fa[y],k=(son[y][1]==x);
		if(not_root(y))son[z][son[z][1]==y]=x;
		fa[x]=z;
		son[y][k]=son[x][!k],fa[son[x][!k]]=y;
		son[x][!k]=y,fa[y]=x;
		pushup(y),pushup(x);
	}
	void splay(int x)
	{
		while(not_root(x))
		{
			int y=fa[x];
			if(not_root(y))rotate((son[y][1]==x)==(son[fa[y]][1]==y)?y:x);
			rotate(x);
		}
	}
	void access(int x)
	{
		for(int y=0;x;y=x,x=fa[x])
			splay(x),son[x][1]=y,pushup(x);
	}
	int add(int x)
	{
		access(x),splay(x);
		if(!sum[x])return val[x]=1,pushup(x),0;
		int y=x;
		while(y)
		{
			if(sum[son[y][1]]){y=son[y][1];continue;}
			if(val[y])break;
			y=son[y][0];
		}
		if(!y){std::cerr<<"ERR!!";}
		splay(y),val[y]=0,pushup(y);
		splay(x),val[x]=1,pushup(x);
		return y;
	}
	void del(int x,int y)
	{
		access(x),splay(x);
		val[x]=0,pushup(x);
		if(y)splay(y),val[y]=1,pushup(y);
	}
}
int ans,now;
int pre[MAXN];
void dfs(int u)
{
		pre[u]=LCT::add(u);
		if(!pre[u])++now;
		umax(ans,now);
	for(auto v:a[u])dfs(v);
		LCT::del(u,pre[u]);
		if(!pre[u])--now;
}
int main()
{
	int task=read();
	while(task--)
	{
		n=read();
		for(int i=1;i<=n;++i)a[i].clear(),b[i].clear(),pre[i]=0;
		ans=cur=0;
		for(int i=2;i<=n;++i)a[read()].push_back(i);
		for(int i=2;i<=n;++i)b[read()].push_back(i);
		LCT::init(n);
		dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}