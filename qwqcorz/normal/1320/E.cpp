#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int inf=1<<30;

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
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
struct edge
{
	int to,nxt,val;
}e[N*2];
int head[N],cnt=0;
void add(int u,int v,int w)
{
	e[++cnt].to=v;
	e[cnt].val=w;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
struct tree
{
	int deep[N],top[N],siz[N],son[N],fa[N],dfn[N],cnt=0;
	void dfs0(int now,int father=0)
	{
		deep[now]=deep[father]+1;
		fa[now]=father;
		siz[now]=1;
		for (int i=head[now];i;i=e[i].nxt)
		{
			int to=e[i].to;
			if (to==father) continue;
			dfs0(to,now);
			siz[now]+=siz[to];
			if (siz[to]>siz[son[now]]) son[now]=to;
		}
	}
	void dfs1(int now,int Top=1)
	{
		dfn[now]=++cnt;
		top[now]=Top;
		if (son[now]) dfs1(son[now],Top);
		for (int i=head[now];i;i=e[i].nxt)
		{
			int to=e[i].to;
			if (to==fa[now]||to==son[now]) continue;
			dfs1(to,to);
		}
	}
	int find(int x,int y)
	{
		while (top[x]!=top[y])
		{
			if (deep[top[x]]<deep[top[y]]) swap(x,y);
			x=fa[top[x]];
		}
		if (deep[x]<deep[y]) swap(x,y);
		return y;
	}
	int dis(int x,int y)
	{
		if (deep[x]<deep[y]) swap(x,y);
		return deep[x]-deep[y];
	}
}t;
bool vs[N];
int v[N],s[N],u[N],p[N*2],cntp=0,cl[N],cntcl=0;
int st[N],top=0;
void add_edge(int u,int v,int w)
{
//	print(u,' ');
//	print(v,' ');
//	print(w);
	add(u,v,w);
	add(v,u,w);
	if (!vs[u])
	{
		vs[u]=1;
		cl[++cntcl]=u;
	}
	if (!vs[v])
	{
		vs[v]=1;
		cl[++cntcl]=v;
	}
}
void add_edge(int u,int v)
{
	add_edge(u,v,t.dis(u,v));
}
void build()
{
	top=0;
	for (int i=1,lca;i<=cntp;i++)
	if (top==0) st[++top]=p[i];
	else
	{
		while (t.dfn[lca=t.find(st[top],p[i])]<=t.dfn[st[top-1]]) add_edge(st[top],st[top-1]),top--;
		if (lca==st[top]) st[++top]=p[i];
		else
		{
			add_edge(st[top--],lca);
			st[++top]=lca;
			st[++top]=p[i];
		}
	}
	while (top>1) add_edge(st[top],st[top-1]),top--;
}
void clear()
{
	for (int i=1;i<=cntcl;i++)
	{
		vs[cl[i]]=0;
		head[cl[i]]=0;
	}
	cntcl=cnt=0;
}
struct node
{
	int dis,id,pos;
	bool operator <(const node &a)const
	{
		if (dis==0) return 0;
		if (a.dis==0) return 1;
		if ((dis-1)/s[id]==(a.dis-1)/s[a.id]) return id>a.id;
		return (dis-1)/s[id]>(a.dis-1)/s[a.id];
	}
}qwq,dis[N];
bool vis[N];
priority_queue<node>heap;
void dijkstra(int k)
{
	for (int i=1;i<=cntcl;i++) vis[cl[i]]=0;
	for (int i=1;i<=cntcl;i++) dis[cl[i]]=(node){inf,1,1};
	for (int i=1;i<=k;i++)
	{
//		print(i);
		dis[v[i]]=(node){0,i,v[i]};
		heap.push(dis[v[i]]);
	}
	while (!heap.empty())
	{
		qwq=heap.top();
		heap.pop();
		int now=qwq.pos;
		if (vis[now]) continue;
		vis[now]=1;
//		print(qwq.pos,':');
//		print(qwq.id,' ');
//		print(qwq.dis);
		for (int i=head[now];i;i=e[i].nxt)
		{
			int to=e[i].to;
			node tmp=(node){dis[now].dis+e[i].val,dis[now].id,to};
			if (dis[to]<tmp)
			{
				dis[to]=tmp;
				heap.push(tmp);
			}
		}
	}
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int n=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add(u,v,1);
		add(v,u,1);
	}
	t.dfs0(1);
	t.dfs1(1);
	memset(head,0,sizeof(head));
	cnt=0;
	int q=read();
	while (q--)
	{
		cntp=0;
		int k=read(),m=read();
		for (int i=1;i<=k;i++)
		{
			v[i]=read();
			s[i]=read();
			p[++cntp]=v[i];
		}
		for (int i=1;i<=m;i++)
		{
			u[i]=read();
			p[++cntp]=u[i];
		}
		p[++cntp]=1;
		sort(p+1,p+1+cntp,[&](int x,int y){return t.dfn[x]<t.dfn[y];});
		cntp=unique(p+1,p+1+cntp)-p-1;
//		puts("X");
		build();
//		puts("X");
		dijkstra(k);
//		puts("X");
		clear();
//		puts("-----------------------------");
		for (int i=1;i<=m;i++) print(dis[u[i]].id,' ');
		putchar('\n');
//		puts("-----------------------------");
	}

	return 0;
}