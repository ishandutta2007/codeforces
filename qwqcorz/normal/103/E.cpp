#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e2+5;
const int BIGinf=1ll<<60;
const int inf=1ll<<30;

inline int read()
{
	register int s=0;
	register char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(register int x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
inline void print(const register int x,const register char c='\n')
{
	write(x);
	putchar(c);
}
namespace Dinic
{
	const int N=1e3+5;
	const int M=N*N+5;
	const int inf=1ll<<60;
	int n,S,T,cur[N],head[N],cnt=-1,deep[N];
	struct edge
	{
		int nxt,to,v;
	}e[2*M];
	struct Queue
	{
		int now,dis;
	}q[N];
	void add_edge(int u,int v,int w)
	{
		e[++cnt].to=v;
		e[cnt].v=w;
		e[cnt].nxt=head[u];
		head[u]=cnt;
	}
	void add(int u,int v,int w)
	{
		add_edge(u,v,w);
		add_edge(v,u,0);
	}
	bool bfs()
	{
		for (int i=1;i<=n;i++) cur[i]=head[i];
		memset(deep,0,sizeof(deep));
		int h=1,t=1;
		q[1].now=S;
		q[1].dis=0;
		while (h<=t)
		{
			int now=q[h].now,dis=q[h++].dis;
			for (int i=head[now];~i;i=e[i].nxt)
			if (e[i].v)
			{
				int to=e[i].to;
				if ((!deep[to])&&to!=S)
				{
					deep[to]=dis+1;
					q[++t].dis=dis+1;
					q[t].now=to;
				}
			}
		}
		return deep[T];
	}
	int dfs(int now,int flow)
	{
		if (!flow) return 0;
		if (now==T) return flow;
		int ans=0,to,v,tmp;
		for (int i=cur[now];~i;i=e[i].nxt)
		{
			cur[now]=i;
			if (to=e[i].to,v=e[i].v,deep[now]<deep[to])
			if (tmp=dfs(to,min(flow,v)))
			{
				ans+=tmp;
				flow-=tmp;
				e[i].v-=tmp;
				e[i^1].v+=tmp;
				if (!flow) return ans;
			}
		}
		cur[now]=-1;
		return ans;
	}
	int work()
	{
		if (S==T) return 0;
		int ans=0;
		while (bfs()) ans+=dfs(S,BIGinf);
		return ans;
	}
	void send(int _n,int _S,int _T)
	{
		memset(head,-1,sizeof(head));
		n=_n;
		S=_S;
		T=_T;
	}
}
int SET[N],NUM[N];

signed main()
{
	int n=read(),S=1,T=2,cnt=2,v,sum=0;
	for (int i=1;i<=n;i++) SET[i]=++cnt;
	for (int i=1;i<=n;i++) NUM[i]=++cnt;
	Dinic::send(cnt,S,T);
	for (int i=1;i<=n;i++)
	{
		int m=read();
		for (int j=1;j<=m;j++) Dinic::add(SET[i],NUM[read()],inf);
	}
	for (int i=1;i<=n;i++) Dinic::add(S,SET[i],inf-(v=read())),sum+=v;
	for (int i=1;i<=n;i++) Dinic::add(NUM[i],T,inf);
	print(sum+(Dinic::work()-inf*n));

	return 0;
}