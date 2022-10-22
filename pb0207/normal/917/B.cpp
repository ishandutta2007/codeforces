#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=2e5+1e3+7;

int head[N],cnt;

int f[101][101][27];

struct node{
	int ne,to,w;
}edg[N*2+1];

void build(int u,int v,int w)
{
	++cnt;
	edg[cnt].to=v;
	edg[cnt].w=w;
	edg[cnt].ne=head[u];
	head[u]=cnt;
}

int dfs(int x,int y,int last)
{
	int mx=0;
	if(f[x][y][last]!=-1)
		return f[x][y][last];
	int &ret=f[x][y][last];
	ret=0;
	for(int tmp=head[x];tmp;tmp=edg[tmp].ne)
	{
		int v=edg[tmp].to;
		if(edg[tmp].w>=last)
			ret|=!(dfs(y,v,edg[tmp].w));
	}
	return ret;
}

int n,m,deg[N];

int main()
{
	memset(f,-1,sizeof(f));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		char w[2];
		scanf("%d%d%s",&u,&v,w);
		build(u,v,(int)(w[0]-'a'+1));
		deg[v]++;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dfs(i,j,0);
	for(int i=1;i<=n;i++,puts(""))
		for(int j=1;j<=n;j++)
			putchar(f[i][j][0]?'A':'B');
}