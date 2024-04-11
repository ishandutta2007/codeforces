#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;

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
bool vis[N];
int c[N],dis[N];
unordered_map<int,int>e[N];
vector<int>g[N][4];

signed main(signed bangumi,char *ss1672[])
{
	(void)bangumi,(void)ss1672;
	int n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		e[u][v]|=1<<w;
	}
	for (int i=1;i<=n;i++)
	for (auto j:e[i])
	g[j.first][j.second].push_back(i);
	memset(c,-1,sizeof(c));
	dis[1]=-1;
	dis[n]=0;
	static int q[N],h=1,t=0;
	q[++t]=n;
	while (h<=t)
	{
		int now=q[h++];
		for (int x=1;x<=2;x++)
		for (int to:g[now][x])
		if (c[to]<0||c[to]==x) c[to]=x;
		else if (!vis[to]) dis[q[++t]=to]=dis[now]+1,vis[to]=1;
		for (int to:g[now][3]) if (!vis[to]) dis[q[++t]=to]=dis[now]+1,vis[to]=1;
	}
	print(dis[1]);
	for (int i=1;i<=n;i++) putchar(!max(c[i]-1,0)+'0');
	
	return 0;
}