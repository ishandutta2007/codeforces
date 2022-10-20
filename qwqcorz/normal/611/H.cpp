#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
const int M=7;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}
int get()
{
	int ret=0;
	char c=getchar();
	while (c!='?') c=getchar();
	while (c=='?') c=getchar(),ret++;
	return ret;
}

namespace Flow
{
	const int V=M*M*M;
	const int E=V*V;
	const int inf=1e9+7;
	int n,S,T;
	struct edge
	{
		int to,val,nxt,col;
	}e[E*2];
	int cur[V],head[V],cnte;
	void add_edge(int u,int v,int w,int col)
	{
		e[++cnte].to=v;
		e[cnte].val=w;
		e[cnte].col=col;
		e[cnte].nxt=head[u];
		head[u]=cnte;
	}
	void add(int u,int v,int w,int col)
	{
//		print(u,' '),print(v,' '),print(w);
		add_edge(u,v,w,col);
		add_edge(v,u,0,col);
	}
	int deep[V];
	bool bfs()
	{
		for (int i=0;i<=n;i++) deep[i]=-1,cur[i]=head[i];
		queue<int>q;
		q.push(S),deep[S]=0;
		while (!q.empty())
		{
			int now=q.front(); q.pop();
			for (int i=head[now];i;i=e[i].nxt)
			if (e[i].val)
			{
				int to=e[i].to;
				if (deep[to]<0) deep[to]=deep[now]+1,q.push(to);
			}
		}
		return ~deep[T];
	}
	int dfs(int now,int flow)
	{
		int ret=0;
		if (!flow) return 0;
		if (now==T) return flow;
		for (int i=cur[now];i;cur[now]=i=e[i].nxt)
		{
			int to=e[i].to,val=e[i].val,tmp;
			if (deep[to]!=deep[now]+1) continue;
			if ((tmp=dfs(to,min(flow,val))))
			{
				ret+=tmp;
				flow-=tmp;
				e[i].val-=tmp;
				e[i^1].val+=tmp;
				if (!flow) return ret;
			}
		}
		return ret;
	}
	int solve()
	{
		int ret=0;
		while (bfs()) ret+=dfs(S,inf);
		return ret;
	}
	void send(int _n,int _S,int _T)
	{
		n=_n,S=_S,T=_T,cnte=1;
		memset(head,0,sizeof(head));
	}
}
struct dsu
{
	int fa[M];
	void send(int n){for (int i=1;i<=n;i++) fa[i]=i;}
	int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
	void merge(int x,int y)
	{
		x=find(x),y=find(y);
		if (x==y) return;
		fa[x]=y;
	}
}d;
int log10(int x){int ret=0;while (x) x/=10,ret++;return ret;}
int a[M],tot[M][M],n,m,fa[M];
void solve()
{
	static int b[M][M];
	memcpy(b,tot,sizeof(b));
	for (int i=1;i<m;i++)
	{
		int u=i,v=fa[i];
		if (u>v) swap(u,v);
		b[u][v]--;
	}
	int cnt=0,S=0;
	static int idL[M][M],idR[M];
	for (int i=1;i<=m;i++)
	for (int j=i;j<=m;j++)
	if (b[i][j]) idL[i][j]=++cnt;
	for (int i=1;i<=m;i++) idR[i]=++cnt;
	int T=++cnt;
	Flow::send(T,S,T);
	for (int i=1;i<=m;i++)
	for (int j=i;j<=m;j++)
	if (b[i][j]) Flow::add(S,idL[i][j],b[i][j],0);
	for (int i=1;i<=m;i++) Flow::add(idR[i],T,a[i]-1,0);
	for (int i=1;i<=m;i++)
	for (int j=i;j<=m;j++)
	if (b[i][j])
	{
		Flow::add(idL[i][j],idR[i],b[i][j],j);
		Flow::add(idL[i][j],idR[j],b[i][j],i);
	}
	if (Flow::solve()==n-m)
	{
		int myh[M]={0,1,10,100,1000,10000,100000};
		int now[M]={0,1,10,100,1000,10000,100000};
		vector<pair<int,int>>ans;
		for (int i=1;i<m;i++) ans.push_back(make_pair(myh[i],myh[fa[i]]));
		for (int i=1;i<=m;i++)
		for (int j=Flow::head[idR[i]];j;j=Flow::e[j].nxt)
		{
			int to=Flow::e[j].col;
			if (!to) continue;
			for (int k=1;k<=Flow::e[j].val;k++)
			ans.push_back(make_pair(++now[i],myh[to]));
		}
		for (auto i:ans) print(i.first,' '),print(i.second);
		exit(0);
	}
}
bool check()
{
	d.send(m);
	for (int i=1;i<m;i++) d.merge(i,fa[i]);
	int tmp=0;
	for (int i=1;i<=m;i++) tmp+=i==d.fa[i];
	return tmp==1;
}
void dfs(int now)
{
	if (now==m)
	{
		if (check()) solve();
		return;
	}
	for (int i=1;i<=m;i++)
	if (i!=now)
	{
		int u=i,v=now;
		if (u>v) swap(u,v);
		if (!tot[u][v]) continue;
		fa[now]=i,dfs(now+1);
	}
}

signed main()
{
	n=read(),m=log10(n);
	for (int i=1;i<n;i++)
	{
		int u=get(),v=get();
		if (u>v) swap(u,v);
		tot[u][v]++;
	}
	for (int i=1;i<=n;i++) a[log10(i)]++;
	dfs(1);
	puts("-1");
	
	return 0;
}