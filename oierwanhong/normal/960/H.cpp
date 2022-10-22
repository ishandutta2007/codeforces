#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
typedef long long ll;
typedef std::vector<int> P;
typedef std::pair<int,int> pii;
typedef unsigned un;
ll read()
{
    ll x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return f*x;
}
using std::min;
using std::max;
template<typename T>bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T>bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}

const int MAXN = 100011;
std::vector<int>g[MAXN];
namespace LCT
{
	ll s2,s1,sum[MAXN],val[MAXN],tag[MAXN],size[MAXN];
	int fa[MAXN],son[MAXN][2];
	void init(int u)
	{
		for(auto v:g[u])
			if(v!=fa[u])fa[v]=u,init(v);
	}
	bool not_root(int x){return son[fa[x]][0]==x||son[fa[x]][1]==x;}
	void pushup(int x)
	{
		int l=son[x][0],r=son[x][1];
		size[x]=size[l]+size[r]+1,sum[x]=sum[l]+sum[r]+val[x];
	}
	void pushadd(int x,int k){sum[x]+=size[x]*k,tag[x]+=k,val[x]+=k;}
	void pushdown(int x)
	{
		if(!tag[x])return;
		pushadd(son[x][0],tag[x]),pushadd(son[x][1],tag[x]);
		tag[x]=0;
	}
	void rotate(int x)
	{
		int y=fa[x],z=fa[y],k=(son[y][1]==x);
		if(not_root(y))son[z][son[z][1]==y]=x;
		fa[x]=z;
		son[y][k]=son[x][!k],fa[son[x][!k]]=y;
		son[x][!k]=y,fa[y]=x;
		pushup(y),pushup(x);
	}
	int s[MAXN];
	void splay(int x)
	{
		int top=0;
		s[++top]=x;
		for(int y=x;not_root(y);y=fa[y])s[++top]=fa[y];
		while(top)pushdown(s[top--]);
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
	void Add(int x,ll k)
	{
		access(x),splay(x);
		s2+=2*sum[x]*k+size[x]*k*k;
		s1+=size[x]*k;
		pushadd(x,k);
	}
}
std::vector<pii>a[MAXN];
double res[MAXN];
ll b[MAXN];
int cur[MAXN];
int main()
{
	int n=read(),m=read(),q=read();
	ll C=read();
	for(int i=1;i<=n;++i)cur[i]=read(),a[cur[i]].push_back(pii(i,1));
	for(int i=2;i<=n;++i)g[read()].push_back(i);
	for(int i=1;i<=m;++i)b[i]=read();
	LCT::init(1);
	for(int i=1;i<=q;++i)
	{
		int op=read();
		if(op==1)
		{
			int u=read(),x=read();
			a[cur[u]].push_back(pii(u,-1));
			cur[u]=x;
			a[cur[u]].push_back(pii(u,1));
		}
		else a[read()].push_back(pii(i,0));
		res[i]=-1;
	}
	for(int u=1;u<=n;++u)a[cur[u]].push_back(pii(u,-1));
	for(int c=1;c<=m;++c)
	{
		for(auto x:a[c])
			if(x.second)LCT::Add(x.first,x.second);
			else
			{
				res[x.first]=double(LCT::s2*b[c]*b[c] - 2*LCT::s1*b[c]*C + n*C*C)/n;
			}
	}
	for(int i=1;i<=q;++i)
		if(res[i]> -1e-9)printf("%.8lf\n",res[i]);
	return 0;
}