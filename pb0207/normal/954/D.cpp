#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int N=1e3+1e2+7;

int head[N],cnt;

struct node{
	int ne,to;
}edg[N*N+1];

void build(int u,int v)
{
	++cnt;
	edg[cnt].to=v;
	edg[cnt].ne=head[u];
	head[u]=cnt;
}

int n,m,s,t;

int d1[N],d2[N],vis[N],g[N][N];

queue<int>q;

void bfs()
{
	q.push(s);
	d1[s]=0;
	vis[s]=1;
	while(!q.empty())
	{
		int i=q.front();
		q.pop();
		for(int tmp=head[i];tmp;tmp=edg[tmp].ne)
		{
			int v=edg[tmp].to;
			if(vis[v])
				continue;
			vis[v]=1;
			d1[v]=d1[i]+1;
			q.push(v);
		}
	}
	memset(vis,0,sizeof(vis));
	q.push(t);
	d2[t]=0;
	vis[t]=1;
	while(!q.empty())
	{
		int i=q.front();
		q.pop();
		for(int tmp=head[i];tmp;tmp=edg[tmp].ne)
		{
			int v=edg[tmp].to;
			if(vis[v])
				continue;
			vis[v]=1;
			d2[v]=d2[i]+1;
			q.push(v);
		}
	}
}

int main()
{
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		build(u,v);
		build(v,u);
		g[u][v]=g[v][u]=1;
	}
	bfs();
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			if(g[i][j])
				continue;
			if(d1[i]+d2[j]+1<d1[t])
				continue;
			if(d2[i]+d1[j]+1<d1[t])
				continue;
			ans++;
		}
	printf("%d",ans);
}