#include<bits/stdc++.h>
using namespace std;
const int N=1028;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int a[N],u[N],v[N],cnt=0,n,d;
void through(int u,int v)
{
	for (int i=0;i<d;i++)
	if (((u^v)>>i)&1)
	print(i,' ');
}
namespace Flow
{
	const int N=2055;
	const int M=7e4+5;
	const int inf=INT_MAX;
	struct edge
	{
		int to,w,p,nxt;
	}e[M*2];
	int head[N*2],cnte;
	void add_edge(int u,int v,int w,int p)
	{
		e[++cnte].to=v;
		e[cnte].w=w;
		e[cnte].p=p;
		e[cnte].nxt=head[u];
		head[u]=cnte;
	}
	void add(int u,int v,int w,int p)
	{
//		print(u,' ');
//		print(v,' ');
//		print(w,' ');
//		print(p);
		add_edge(u,v,w,p);
		add_edge(v,u,0,-p);
	}
	int n,S,T,cost[N],ans1,ans2;
	struct Queue
	{
		int now,f,c,id,nxt;
	}q[1<<23];
	bool spfa()
	{
		for (int i=1;i<=n;i++) cost[i]=inf;
		int h=1,t=1,Min=inf;
		q[1]=(Queue){S,inf,cost[S]=0,0,0};
		while (h<=t)
		{
			int now=q[h].now,f=q[h].f,c=q[h].c,id=h++;
			if (c==cost[now])
			for (int i=head[now];i;i=e[i].nxt)
			{
				int to=e[i].to,w=e[i].w,p=e[i].p;
				if (w&&cost[to]>cost[now]+p)
				{
					q[++t]=(Queue){to,min(f,w),cost[to]=cost[now]+p,i,id};
					if (to==T) Min=t;
				}
			}
		}
		if (Min==inf) return 0;
		int flow=q[Min].f,cost=q[Min].c;
		ans1+=flow;
		ans2+=flow*cost;
		while (Min)
		{
			e[q[Min].id].w-=flow;
			e[q[Min].id^1].w+=flow;
			Min=q[Min].nxt;
		}
		return 1;
	}
	void solve()
	{
		ans1=ans2=0;
		if (S==T) return;
		while (spfa());
	}
	void send(int _n,int _S,int _T)
	{              
		n=_n,S=_S,T=_T;
		memset(head,0,sizeof(head));
		cnte=1;
	}
	void output(int n)
	{
		static int fa[N];
		static bool vis[N];
		static int st[N],top;
		for (int i=1;i<=n;i++) fa[i]=vis[i]=0;
		for (int i=1;i<=n;i++)
		for (int j=head[i];j;j=e[j].nxt)
		if (!e[j].w)
		{
			int to=e[j].to;
			if (n<to&&to<T) vis[fa[to-n]=i]=1;
		}
		bool flag=0;
//		for (int i=1;i<=n;i++) print(fa[i],' ');puts("");
//		for (int i=1;i<=n;i++) print(vis[i],' ');puts("");
		for (int i=1;i<=n;i++)
		if (!vis[i])
		{
			top=0;
			if (flag) putchar('R'),putchar(' ');
			flag=1;
			for (int x=i;x;x=fa[x]) st[++top]=x;
			through(0,a[st[top]]);
			for (;top>1;top--) through(a[st[top]],a[st[top-1]]);
		}
	}
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	d=read(),n=read();
	for (int i=1;i<=n;i++)
	for (int j=0;j<d;j++)
	{
		char c=getchar();
		while (c<'0'||'1'<c) c=getchar();
		a[i]|=(c-'0')<<j;
	}
	for (int i=1;i<=n;i++) u[i]=++cnt;
	for (int i=1;i<=n;i++) v[i]=++cnt;
	int S=0,T=++cnt;
	Flow::send(cnt,S,T);
	for (int i=1;i<=n;i++) Flow::add(S,u[i],1,__builtin_popcount(a[i]));
	for (int i=1;i<=n;i++) Flow::add(v[i],T,1,0);
	for (int i=1;i<=n;i++) Flow::add(u[i],T,1,1);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	if (i!=j&&(a[i]|a[j])==a[j])
	Flow::add(u[i],v[j],1,-__builtin_popcount(a[i]));
	Flow::solve();
	print(Flow::ans2-1);
	Flow::output(n);
	
	return 0;
}