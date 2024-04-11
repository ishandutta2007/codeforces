#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

const int N=1e5+1e3+7;

int n,m,k,s;

vector<int>col[N];

int head[N],cnt;

struct node{
	int ne,to,w;
}edg[N*2+1];

void build(int u,int v)
{
	++cnt;
	edg[cnt].to=v;
	edg[cnt].ne=head[u];
	head[u]=cnt;
}

int d[N],dis[N][101];

queue<int>q;

void bfs(int c)
{
	fill(d+1,d+n+1,-1);
	for(int i=0;i<col[c].size();i++)
		q.push(col[c][i]),d[col[c][i]]=0;
	while(!q.empty())
	{
		int i=q.front();
		q.pop();
		dis[i][c]=d[i];
		for(int tmp=head[i];tmp;tmp=edg[tmp].ne)
		{
			int v=edg[tmp].to;
			if(d[v]!=-1)
				continue;
			d[v]=d[i]+1;
			q.push(v);
		}
	}
}

int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&s);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		col[x].push_back(i);
	}
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		build(u,v);
		build(v,u);
	}
	for(int i=1;i<=k;i++)
		bfs(i);
	for(int i=1;i<=n;i++)
	{
		sort(dis[i]+1,dis[i]+k+1);
		int ans=0;
		for(int j=1;j<=s;j++)
			ans+=dis[i][j];
		printf("%d ",ans);
	}
}