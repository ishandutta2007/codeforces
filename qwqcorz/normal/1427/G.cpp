#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=205;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int a[N*N],id[N][N],cnt=0,c[N*N];
namespace Flow
{
	struct edge
	{
		int to,nxt,val;
	}e[N*N*4];
	int head[N*N],cnte=1;
	void add_edge(int u,int v)
	{
		e[++cnte].to=v;
		e[cnte].val=0;
		e[cnte].nxt=head[u];
		head[u]=cnte;
	}
	void add(int u,int v)
	{
		add_edge(u,v);
		add_edge(v,u);
	}
	bool vis[N*N];
	int ans=0;
	bool _dfs(int now,int flow)
	{
		if (vis[now]) return 0;
		vis[now]=1;
		if (flow>0&&c[now]<0) return 1;
		if (flow<0&&c[now]>0) return 1;
		for (int i=head[now];i;i=e[i].nxt)
		{
			int to=e[i].to;
			if (flow>0&&e[i].val==-1) continue;
			if (flow<0&&e[i].val!=1) continue;
			if (_dfs(to,flow))
			{
				e[i].val--;
				e[i^1].val++;
				return 1;
			}
		}
		return 0;
	}
	bool dfs(int now,int flow)
	{
		memset(vis,0,sizeof(vis));
		return _dfs(now,flow);
	}
}

signed main()
{
	ll ans=0;
	int n=read();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++) id[i][j]=++cnt;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++) a[id[i][j]]=read();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	if (~a[id[i][j]])
	{
		if (i>1&&~a[id[i-1][j]]) Flow::add(id[i][j],id[i-1][j]);
		if (j>1&&~a[id[i][j-1]]) Flow::add(id[i][j],id[i][j-1]);
	}
	vector<int>p;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	if (i==1||j==1||i==n||j==n) p.push_back(id[i][j]);
	int cntb=0;
	static int b[N*4];
	for (int i:p) b[++cntb]=a[i];
	sort(b+1,b+1+cntb);
	cntb=unique(b+1,b+1+cntb)-b-1;
	for (int i:p) a[i]=lower_bound(b+1,b+1+cntb,a[i])-b;
	for (int i:p) c[i]=-1;
	for (int i=1;i<cntb;i++)
	{
		for (int j:p) if (a[j]==i)
		{
			while (Flow::dfs(j,-1)) Flow::ans--;
			c[j]=1;
		}
		memset(Flow::vis,0,sizeof(Flow::vis));
		for (int j:p) if (c[j]==1) while (Flow::_dfs(j,1)) Flow::ans++,memset(Flow::vis,0,sizeof(Flow::vis));
		ans+=1LL*(b[i+1]-b[i])*Flow::ans;
	}
	print(ans);
	
	return 0;
}