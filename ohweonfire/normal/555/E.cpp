// This amazing code is by Eric Sunli Chen.
#include<bits/stdc++.h>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int maxn=200111;

vector<int> g[maxn];
int bcc[maxn],sz,n,m,q;

namespace BCC
{
	int head[maxn],nxt[maxn<<1],to[maxn<<1],etot=1;
	void addedge(int u,int v)
	{
		nxt[++etot]=head[u];head[u]=etot;to[etot]=v;
		nxt[++etot]=head[v];head[v]=etot;to[etot]=u;
	}
	int dfn[maxn],low[maxn],timer;
	bool bridge[maxn];
	void dfs(int x,int fe)
	{
		dfn[x]=low[x]=++timer;
		for(int i=head[x];i;i=nxt[i])if(i!=fe)
		{
			if(!dfn[to[i]])
			{
				dfs(to[i],i^1);
				if(dfn[x]<low[to[i]])bridge[i>>1]=1;
				else low[x]=min(low[x],low[to[i]]);
			}
			else low[x]=min(low[x],dfn[to[i]]);
		}
	}
	void dfs2(int x,int b)
	{
		bcc[x]=b;
		for(int i=head[x];i;i=nxt[i])if(!bridge[i>>1]&&!bcc[to[i]])dfs2(to[i],b);
	}
	void decomp()
	{
		for(int i=1;i<=n;i++)if(!dfn[i])dfs(i,0);
		for(int i=1;i<=n;i++)if(!bcc[i])dfs2(i,++sz);
		for(int i=1;i<=etot/2;i++)if(bridge[i])
		{
			int u=bcc[to[i*2]],v=bcc[to[i*2+1]];
			g[u].pb(v);
			g[v].pb(u);
//			printf("bridge %d %d\n",to[i*2],to[i*2+1]);
		}
//		for(int i=1;i<=n;i++)printf("i= %d bcc= %d\n",i,bcc[i]);
	}
}

int fa[20][maxn],dep[maxn],up[maxn],down[maxn];

void dfs(int x,int f,int d)
{
	fa[0][x]=f;dep[x]=d;for(int i=1;i<20;i++)fa[i][x]=fa[i-1][fa[i-1][x]];
	for(int i=0;i<(int)g[x].size();i++)if(g[x][i]!=f)dfs(g[x][i],x,d+1);
}
int getlca(int u,int v)
{
	if(dep[u]<dep[v])swap(u,v);
	for(int i=19;i>=0;i--)if(dep[u]-dep[v]>>i)u=fa[i][u];
	if(u==v)return u;
	for(int i=19;i>=0;i--)if(fa[i][u]!=fa[i][v])
	{
		u=fa[i][u];
		v=fa[i][v];
	}
	return fa[0][u];
}

void mark(int u,int v)
{
	int lca=getlca(u,v);
	if(!lca)
	{
		puts("No");
		exit(0);
	}
	up[u]++;up[lca]--;
	down[v]++;down[lca]--;
}

void dfs2(int x)
{
	for(int i=0;i<(int)g[x].size();i++)if(g[x][i]!=fa[0][x])
	{
		dfs2(g[x][i]);
		up[x]+=up[g[x][i]];
		down[x]+=down[g[x][i]];
	}
}

int main()
{
	get3(n,m,q);
	for(int i=1,u,v;i<=m;i++)
	{
		get2(u,v);
		BCC::addedge(u,v);
	}
	BCC::decomp();
	
	for(int i=1;i<=sz;i++)if(!dep[i])dfs(i,0,1);
	for(int i=1,u,v;i<=q;i++)
	{
		get2(u,v);
		mark(bcc[u],bcc[v]);
	}
	for(int i=1;i<=sz;i++)if(dep[i]==1)dfs2(i);
	for(int i=1;i<=sz;i++)if(up[i]&&down[i])
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	return 0;
}