#include<bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
const int N=505;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};

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
vector<pair<int,int>>e[N][N];
inline void add_edge(int x,int y,int u,int v)
{
	e[x][y].push_back(mk(u,v));
	e[u][v].push_back(mk(x,y));
}
char a[N][N];
int ans[N][N];
void dfs(int x,int y,int z)
{
	ans[x][y]=z?1:4;
	for (auto to:e[x][y])
	if (!~ans[to.fi][to.se])
	dfs(to.fi,to.se,!z);
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	memset(ans,-1,sizeof(ans));
	int n=read(),m=read();
	for (int i=1;i<=n;i++) scanf("%s",a[i]+1);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	if (a[i][j]=='X')
	{
		vector<pair<int,int>>tmp;
		for (int k=0;k<4;k++)
		{
			int nx=i+dx[k],ny=j+dy[k];
			if (a[nx][ny]=='.') tmp.push_back(mk(nx,ny));
		}
		if (tmp.size()&1) return puts("NO"),0;
		for (int k=0;k<(int)tmp.size();k+=2)
		add_edge(tmp[k].fi,tmp[k].se,tmp[k+1].fi,tmp[k+1].se);
		ans[i][j]=tmp.size()/2*5;
	}
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	if (!~ans[i][j]) dfs(i,j,0);
	puts("YES");
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	print(ans[i][j]," \n"[j==m]);
	
	return 0;
}