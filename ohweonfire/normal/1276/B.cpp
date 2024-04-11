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
const int maxm=1000111;

int n,m,a,b;
vector<int> g[maxm];

namespace bcc
{
	int head[maxn],nxt[maxm],to[maxm],etot=1;
	void addedge(int u,int v)
	{
		nxt[++etot]=head[u];head[u]=etot;to[etot]=v;
		nxt[++etot]=head[v];head[v]=etot;to[etot]=u;
	}
	
	int dfn[maxn],low[maxn],timer,bcnt,mark[maxn];
	
	int stk[maxm],top;
	void clear(int n)
	{
		bcnt=0;timer=0;
		for(int i=1;i<=n;i++)dfn[i]=0;
		for(int i=1;i<=n;i++)mark[i]=0;
		etot=1;
		memset(head,0,sizeof(int)*(n+3));
	}
	void dfs(int x,int fe)
	{
		dfn[x]=low[x]=++timer;
		for(int i=head[x];i;i=nxt[i])if(i!=fe)
		{
			if(dfn[to[i]]<dfn[x])stk[++top]=i>>1;
			if(!dfn[to[i]])
			{
				dfs(to[i],i^1);
				low[x]=min(low[x],low[to[i]]);
				if(low[to[i]]>=dfn[x])
				{
					bcnt++;
					while(top)
					{
						int e=stk[top--],u=to[e<<1],v=to[(e<<1)|1];
						if(mark[u]!=bcnt)
						{
							mark[u]=bcnt;
							g[u].pb(n+bcnt);g[n+bcnt].pb(u);
						}
						if(mark[v]!=bcnt)
						{
							mark[v]=bcnt;
							g[v].pb(n+bcnt);g[n+bcnt].pb(v);
						}
						if(e==(i>>1))break;
					}
				}
			}
			else low[x]=min(low[x],dfn[to[i]]);
		}
	}
	
	int decomp()
	{
		for(int i=1;i<=n;i++)if(!dfn[i])dfs(i,0);
		return bcnt+n;
	}
};


int dfs(int x,int f,int forbidden)
{
	if(x==forbidden)return -1;
	int ret=(x<=n);
	for(int i=0;i<(int)g[x].size();i++)if(g[x][i]!=f)
	{
		int v=dfs(g[x][i],x,forbidden);
		if(v==-1)return -1;
		else ret+=v;
	}
	return ret;
}

void solve()
{
	get2(n,m);get2(a,b);
	bcc::clear(n);
	for(int i=1;i<=n+m;i++)g[i].clear();
	for(int i=1,u,v;i<=m;i++)
	{
		get2(u,v);
		bcc::addedge(u,v);
	}
	bcc::decomp();
	int s1=0,s2=0;
	for(int i=0;i<(int)g[a].size();i++)
	{
		int val=dfs(g[a][i],a,b);
		if(val!=-1)s1+=val;
	}
	for(int i=0;i<(int)g[b].size();i++)
	{
		int val=dfs(g[b][i],b,a);
		if(val!=-1)s2+=val;
	}
	printf("%lld\n",(LL)s1*s2);
}

int main()
{
	int tc;
	get1(tc);
	while(tc--)solve();
	return 0;
}