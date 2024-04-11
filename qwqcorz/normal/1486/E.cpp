#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int M=2e5+5;
const int W=55;
const int inf=1e9+7;

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
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
struct edge
{
	int to,val,nxt;
}e[M*2];
int head[N],cnte=0;
void add(int u,int v,int w)
{
	e[++cnte].to=v;
	e[cnte].val=w;
	e[cnte].nxt=head[u];
	head[u]=cnte;
}
struct node
{
	int pos,w,dis;
	bool operator <(const node &a)const
	{
		return dis>a.dis;
	}
}qwq;
priority_queue<node>q;
int dis[N][W];
bool vis[N][W];
inline int sqr(int x)
{
	return x*x;
}
void dijkstra(int n)
{
	for (int i=1;i<=n;i++)
	for (int j=0;j<=50;j++) dis[i][j]=inf;
	dis[1][0]=0;
	q.push((node){1,0,0});
	while (!q.empty())
	{
		qwq=q.top();
		q.pop();
		int now=qwq.pos,w=qwq.w;
		if (vis[now][w]) continue;
		vis[now][w]=1;
		for (int i=head[now];i;i=e[i].nxt)
		{
			int to=e[i].to,val=e[i].val;
			if (w==0)
			{
				if (dis[to][val]>dis[now][w])
				{
					dis[to][val]=dis[now][w];
					q.push((node){to,val,dis[to][val]});
				}
			}
			else
			{
				if (dis[to][0]>dis[now][w]+sqr(w+val))
				{
					dis[to][0]=dis[now][w]+sqr(w+val);
					q.push((node){to,0,dis[to][0]});
				}
			}
		}
	}
}

signed main()
{
	int n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		add(u,v,w);
		add(v,u,w);
	}
	dijkstra(n);
	for (int i=1;i<=n;i++)
	if (dis[i][0]==inf) print(-1,' ');
	else print(dis[i][0],' ');

	return 0;
}