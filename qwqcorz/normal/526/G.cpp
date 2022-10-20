#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

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
	int to,val,nxt;
}e[N*2];
int head[N],cnte=0;
void add_edge(int u,int v,int w)
{
	e[++cnte].to=v;
	e[cnte].val=w;
	e[cnte].nxt=head[u];
	head[u]=cnte;
}
int n,q;
struct Tree
{
	int root;
	int dis[N],son[N],top[N],deep[N],fa[N][17],len[N],cnt,sum[N],p[N],id[N],val[N],num[N];
	void dfs0(int now,int father)
	{
		fa[now][0]=father;
		deep[now]=deep[father]+1;
		for (int i=head[now];i;i=e[i].nxt)
		{
			int to=e[i].to;
			if (to==father) continue;
			val[to]=val[now]+e[i].val;
			dfs0(to,now);
			if (dis[now]<dis[to]+e[i].val)
			{
				dis[now]=dis[to]+e[i].val;
				son[now]=to;
			}
		}
	}
	void dfs1(int now,int father,int Top)
	{
		top[now]=Top;
		if (son[now]) dfs1(son[now],now,Top);
		for (int i=head[now];i;i=e[i].nxt)
		{
			int to=e[i].to;
			if (to==father||to==son[now]) continue;
			dfs1(to,now,to);
		}
	}
	int get(int x,int y)
	{
		for (int i=16;i>=0;i--) if (id[fa[x][i]]>y) x=fa[x][i];
		return fa[x][0];
	}
	int calc(int x,int y)
	{
		y=y*2-1;
		if (y>=cnt) return sum[cnt];
		if (id[x]<=y) return sum[y];
		int u=get(x,y);
		int v=get(x,y-1);
		return max(sum[y]-dis[u]+val[x]-val[u]+dis[x],sum[y-1]+val[x]-val[v]+dis[x]);
	}
	void YSGS()
	{
		dfs0(root,0);
		dfs1(root,0,root);
		for (int j=1;j<17;j++)
		for (int i=1;i<=n;i++)
		fa[i][j]=fa[fa[i][j-1]][j-1];
		for (int i=1;i<=n;i++) if (top[i]==i) len[++cnt]=dis[i]+val[i]-val[fa[i][0]],num[cnt]=i;
		for (int i=1;i<=cnt;i++) p[i]=i;
		sort(p+1,p+1+cnt,[&](int x,int y){return len[x]>len[y];});
		for (int i=1;i<=cnt;i++) sum[i]=sum[i-1]+len[p[i]];
		for (int i=1;i<=cnt;i++) id[num[p[i]]]=i;
		for (int i=1;i<=n;i++) id[i]=id[top[i]];
	}
}t1,t2;
int id,Max=0;
void dfs(int now,int father,int dis)
{
	if (dis>Max) Max=dis,id=now;
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==father) continue;
		dfs(to,now,dis+e[i].val);
	}
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	n=read(),q=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read(),w=read();
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	dfs(1,0,0);
	int A=id;
	Max=0;
	dfs(A,0,0);
	int B=id;
	t1.root=A;
	t2.root=B;
	t1.YSGS();
	t2.YSGS();
	for (int i=1,lastans=0;i<=q;i++)
	{
		int x=read(),y=read();
		x=(x+lastans-1)%n+1;
		y=(y+lastans-1)%n+1;
		print(lastans=max(t1.calc(x,y),t2.calc(x,y)));
	}

	return 0;
}