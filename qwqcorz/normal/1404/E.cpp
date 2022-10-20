#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=205;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

namespace Flow
{
	const int V=N*N*2;
	const int E=V*3;
	const ll inf=1LL<<60;
	int n,S,T;
	struct edge
	{
		int to,nxt;
		ll val;
	}e[E*2];
	int cur[V],head[V],cnte;
	void add_edge(int u,int v,ll w)
	{
		e[++cnte].to=v;
		e[cnte].val=w;
		e[cnte].nxt=head[u];
		head[u]=cnte;
	}
	void add(int u,int v,ll w)
	{
		add_edge(u,v,w);
		add_edge(v,u,0);
	}
	int deep[V];
	bool bfs()
	{
		for (int i=0;i<=n;i++) cur[i]=head[i],deep[i]=-1;
		queue<int>q;
		q.push(S);
		deep[S]=0;
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
		return deep[T]>=0;
	}
	ll dfs(int now,ll flow)
	{
		if (now==T) return flow;
		if (!flow) return 0;
		ll ret=0,tmp=0;
		for (int i=cur[now];i;cur[now]=i=e[i].nxt)
		{
			int to=e[i].to; ll val=e[i].val;
			if (!val||deep[to]!=deep[now]+1) continue;
			if (tmp=dfs(to,min(flow,val)))
			{
				ret+=tmp,flow-=tmp;
				e[i].val-=tmp,e[i^1].val+=tmp;
				if (!flow) return ret;
			}
		}
		return ret;
	}
	ll solve()
	{
		ll ret=0;
		while (bfs()) ret+=dfs(S,inf);
		return ret;
	}
	void send(int _n,int _S,int _T)
	{
		n=_n,S=_S,T=_T,cnte=1;
		memset(head,0,sizeof(head));
	}
}
char a[N][N];
int A[N][N],B[N][N],cnt=0;

signed main()
{
	int n=read(),m=read(),sum=0;
	for (int i=1;i<=n;i++) scanf("%s",a[i]+1);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	{
		sum+=a[i][j]=='#';
		if (a[i][j]=='#'&&a[i][j+1]=='#') A[i][j]=++cnt;
		if (a[i][j]=='#'&&a[i+1][j]=='#') B[i][j]=++cnt;
	}
	int S=0,T=cnt+1;
	Flow::send(T,S,T);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	{
		if (A[i][j])
		{
			Flow::add(S,A[i][j],1);
			if (B[i][j]) Flow::add(A[i][j],B[i][j],1);
			if (B[i][j+1]) Flow::add(A[i][j],B[i][j+1],1);
		}
		if (B[i][j])
		{
			Flow::add(B[i][j],T,1);
			if (A[i+1][j-1]) Flow::add(A[i+1][j-1],B[i][j],1);
			if (A[i+1][j]) Flow::add(A[i+1][j],B[i][j],1);
		}
	}
	print(sum-(cnt-Flow::solve()));
	
	return 0;
}