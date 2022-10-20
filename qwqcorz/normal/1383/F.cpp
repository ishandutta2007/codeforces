#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5;
const int K=10;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

namespace Flow
{
	const int V=N;
	const int E=N;
	const int inf=1e9+7;
	int n;
	struct edge
	{
		int to,nxt,val;
	}e[E*2];
	int cur[V],head[V],cnte;
	void add_edge(int u,int v,int w)
	{
		e[++cnte].to=v;
		e[cnte].val=w;
		e[cnte].nxt=head[u];
		head[u]=cnte;
	}
	void add(int u,int v,int w)
	{
		add_edge(u,v,w);
		add_edge(v,u,0);
	}
	int deep[V];
	bool bfs(int S,int T)
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
				if (to==T) return 1;
			}
		}
		return deep[T]>=0;
	}
	int dfs(int now,int T,int flow)
	{
		if (now==T) return flow;
		if (!flow) return 0;
		int ret=0,tmp=0;
		for (int i=cur[now];i;cur[now]=i=e[i].nxt)
		{
			int to=e[i].to,val=e[i].val;
			if (!val||deep[to]!=deep[now]+1) continue;
			if (tmp=dfs(to,T,min(flow,val)))
			{
				ret+=tmp,flow-=tmp;
				e[i].val-=tmp,e[i^1].val+=tmp;
				if (!flow) return ret;
			}
		}
		return ret;
	}
	int solve(int S,int T)
	{
		int ret=0;
		while (bfs(S,T)) ret+=dfs(S,T,inf);
		return ret;
	}
	void send(int _n)
	{
		n=_n,cnte=1;
		memset(head,0,sizeof(head));
	}
	struct node
	{
		int flow,id;
	}b[V];
	int q[V];
	int BFS(int S,int T)
	{
		for (int i=0;i<=n;i++) b[i].flow=0;
		bool flag=1;
		int h=1,t=0;
		b[q[++t]=S]=(node){inf,0};
		while (h<=t&&flag)
		{
			int now=q[h++];
			for (int i=head[now];i;i=e[i].nxt)
			{
				int to=e[i].to,val=e[i].val,tmp=b[to].flow;
				if (!val||tmp>=min(b[now].flow,val)) continue;
				b[to].flow=min(b[now].flow,val);
				b[to].id=i;
				if (tmp) continue;
				q[++t]=to;
				if (to==T)
				{
					flag=0;
					break;
				}
			}
		}
		if (flag) return 0;
		int now=T,flow=b[T].flow;
		while (now!=S)
		{
			int id=b[now].id;
			e[id].val-=flow;
			e[id^1].val+=flow;
			now=e[id^1].to;
		}
		return flow;
	}
	int EK(int S,int T)
	{
		int ret=0;
		while (1)
		{
			int res=BFS(S,T);
			ret+=res;
			if (!res) return ret;
		}
	}
}
int n,m,k,Q,res[1<<K];
void dfs(int S,int k,int sum)
{
	res[S]=sum;
	vector<int>tmp(Flow::cnte+1);
	for (int i=2;i<=Flow::cnte;i++) tmp[i]=Flow::e[i].val;
	for (int i=0;i<k;i++)
	{
		Flow::e[2+i*2].val+=25;
		dfs(S|1<<i,i,sum+Flow::EK(1,n));
		for (int j=2;j<=Flow::cnte;j++) Flow::e[j].val=tmp[j];
	}
}
int w[K],sum[1<<K],Log[1<<K];

signed main()
{
	n=read(),m=read(),k=read(),Q=read();
	Flow::send(n);
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		Flow::add(u,v,w);
	}
	int all=(1<<k)-1;
	dfs(0,k,Flow::solve(1,n));
	for (int i=2;i<(1<<k);i++) Log[i]=Log[i/2]+1;
	while (Q--)
	{
		int ans=1e9+7;
		for (int i=0;i<k;i++) w[i]=read();
		for (int i=1;i<(1<<k);i++) sum[i]=sum[i&(i-1)]+w[Log[i&-i]];
		for (int i=0;i<(1<<k);i++) ans=min(ans,sum[i]+res[all^i]);
		print(ans);
	}
	
	return 0;
}