#include<bits/stdc++.h>
using namespace std;
const int N=405;
const int M=605;
const int p=998244353;

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
struct node
{
	int to,nxt;
}e[M*2];
int head[N],cnte=0;
void add_edge(int u,int v)
{
	e[++cnte].to=v;
	e[cnte].nxt=head[u];
	head[u]=cnte;
}
int dis[N][N],f[N][N],ans[N][N],q[N],n,m;
void bfs(int s)
{
	int h=1,t=0;
	q[++t]=s;
	dis[s][s]=0;
	f[s][s]=1;
	while (h<=t)
	{
		int now=q[h++];
		for (int i=head[now];i;i=e[i].nxt)
		{
			int to=e[i].to;
			if (!dis[s][to]&&to!=s)
			{
				f[s][to]=f[s][now];
				dis[s][to]=dis[s][now]+1;
				q[++t]=to;
			}
			else if (dis[s][to]==dis[s][now]+1) f[s][to]=2;
		}
	}
}
int solve(int x,int y)
{
	if (f[x][y]==2) return 0;
	int ret=1;
	for (int u=1;u<=n;u++)
	if (dis[x][u]+dis[u][y]!=dis[x][y])
	{
		int tot=0;
		for (int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].to;
			if (dis[x][v]==dis[x][u]-1&&dis[y][v]==dis[y][u]-1)
			tot++;
		}
		ret=1LL*ret*tot%p;
	}
	return ret;
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		add_edge(u,v);
		add_edge(v,u);
	}
	for (int i=1;i<=n;i++) bfs(i);
	for (int i=1;i<=n;i++)
	for (int j=i;j<=n;j++) ans[i][j]=ans[j][i]=solve(i,j);
	for (int i=1;i<=n;i++,putchar('\n'))
	for (int j=1;j<=n;j++) print(ans[i][j],' ');
	
	return 0;
}