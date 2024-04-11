#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int inf=INT_MAX;

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
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
struct edge
{
	int to,val,nxt;
}e[N*8];
int head[N],cnte=0;
void add_edge(int u,int v,int w)
{
	e[++cnte].to=v;
	e[cnte].val=w;
	e[cnte].nxt=head[u];
	head[u]=cnte;
}
struct node
{
	int pos,val;
	bool operator <(const node &a)const
	{
		return val>a.val;
	}
}qwq;
priority_queue<node>q;
int dis[N],n;
bool vis[N];
int dijkstra(int n,int S,int T)
{
	for (int i=1;i<=n;i++) vis[i]=0;
	for (int i=1;i<=n;i++) dis[i]=inf;
	while (!q.empty()) q.pop();
	q.push((node){S,0});
	dis[S]=0;
	while (!q.empty())
	{
		qwq=q.top();
		q.pop();
		int now=qwq.pos;
		if (vis[now]) continue;
		vis[now]=1;
		for (int i=head[now];i;i=e[i].nxt)
		{
			int to=e[i].to,val=e[i].val;
			if (dis[to]>dis[now]+val)
			{
				dis[to]=dis[now]+val;
				q.push((node){to,dis[to]});
			}
		}
	}
	return dis[T];
}
struct point
{
	int x,y,id;
}a[N];
bool cmpX(point u,point v)
{
	return u.x<v.x;
}
bool cmpY(point u,point v)
{
	return u.y<v.y;
}
void add(int u,int v)
{
	add_edge(a[u].id,a[v].id,min(abs(a[u].x-a[v].x),abs(a[u].y-a[v].y)));
	add_edge(a[v].id,a[u].id,min(abs(a[u].x-a[v].x),abs(a[u].y-a[v].y)));
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	n=read(),n=read();
	int S=n+1,T=n+2;
	for (int i=n+1;i<=n+2;i++) a[i].x=read(),a[i].y=read(),a[i].id=i;
	for (int i=1;i<=n;i++) a[i].x=read(),a[i].y=read(),a[i].id=i;
	add_edge(S,T,abs(a[S].x-a[T].x)+abs(a[S].y-a[T].y));
	for (int i=1;i<=n;i++) add_edge(i,T,abs(a[T].x-a[i].x)+abs(a[T].y-a[i].y));
	for (int i=1;i<=n;i++) add(S,i);
	sort(a+1,a+1+n,cmpX);
	for (int i=2;i<=n;i++) add(i-1,i);
	sort(a+1,a+1+n,cmpY);
	for (int i=2;i<=n;i++) add(i-1,i);
	print(dijkstra(n+2,S,T));
	
	return 0;
}