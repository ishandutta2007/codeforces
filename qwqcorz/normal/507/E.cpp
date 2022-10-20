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
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
vector<int>e[N][2];
int dis[N],tot[N],from[N];
void bfs(int s)
{
	queue<int>q;
	memset(dis,0x3f,sizeof(dis));
	dis[s]=1;
	q.push(s);
	while (!q.empty())
	{
		int now=q.front(); q.pop();
		for (int i=0;i<=1;i++)
		for (int to:e[now][i])
		if (dis[to]>dis[now]+1)
		{
			dis[to]=dis[now]+1;
			tot[to]=tot[now]+i;
			from[to]=now;
			q.push(to);
		}
		else if (dis[to]==dis[now]+1&&tot[to]<tot[now]+i)
		{
			tot[to]=tot[now]+i;
			from[to]=now;
		}
	}
}
int u[N],v[N],w[N];
vector<int>g[N];
void GreenDay()
{
	int n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		::u[i]=u,::v[i]=v,::w[i]=w;
		e[u][w].push_back(v);
		e[v][w].push_back(u);
	}
	bfs(1);
	int now=n;
	while (now!=1)
	{
		int nxt=from[now];
		g[now].push_back(nxt);
		g[nxt].push_back(now);
		now=nxt;
	}
	vector<int>ans;
	for (int i=1;i<=m;i++)
	{
		bool flag=0;
		for (int to:g[u[i]]) flag|=to==v[i];
		if (flag!=w[i]) ans.push_back(i);
	}
	print(ans.size());
	for (int i:ans) print(u[i],' '),print(v[i],' '),print(!w[i]);
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
	int T=1;
//	int T=read();
	while (T--) GreenDay();
	
	return 0;
}