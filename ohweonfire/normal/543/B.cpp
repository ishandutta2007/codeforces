#include <bits/stdc++.h>
using namespace std;
const int maxn=3005;
int dist[maxn][maxn];
int head[maxn],next[maxn*2],to[maxn*2],cnt;
void addedge(int x,int y)
{
	cnt++;
	next[cnt]=head[x];
	head[x]=cnt;
	to[cnt]=y;
}
int que[maxn],n,m;
int s1,t1,l1,s2,t2,l2;
void bfs(int s2)
{
	memset(dist[s2],-1,sizeof(dist[s2]));
	dist[s2][s2]=0;
	int front=0,rear=1;
	que[0]=s2;
	while(front!=rear)
	{
		int x=que[front++];
		for(int u=head[x];u;u=next[u])
			if(dist[s2][to[u]]==-1)
			{
				dist[s2][to[u]]=dist[s2][x]+1;
				que[rear++]=to[u];
			}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int u=1,x,y;u<=m;u++)
	{
		scanf("%d%d",&x,&y);
		addedge(x,y);
		addedge(y,x);
	}
	scanf("%d%d%d%d%d%d",&s1,&t1,&l1,&s2,&t2,&l2);
	for(int u=1;u<=n;u++)
		bfs(u);
	if(dist[s1][t1]>l1||dist[s2][t2]>l2)
	{
		puts("-1");
		return 0;
	}
	int ans=dist[s1][t1]+dist[s2][t2];
	for(int u=1;u<=n;u++)
	{
		if(dist[u][s1]>dist[s1][t1]||dist[u][s2]>dist[s2][t2])
			continue;
		if(dist[s1][u]+dist[u][t1]>l1||dist[s2][u]+dist[u][t2]>l2)
			continue;
		for(int v=1;v<=n;v++)
		{
			if(dist[s1][u]+dist[u][v]+dist[v][t1]<=l1&&dist[s2][u]+dist[u][v]+dist[v][t2]<=l2)
				ans=min(ans,dist[s1][u]+dist[s2][u]+dist[u][v]+dist[v][t1]+dist[v][t2]);
			if(dist[s1][u]+dist[u][v]+dist[v][t1]<=l1&&dist[t2][u]+dist[u][v]+dist[v][s2]<=l2)
				ans=min(ans,dist[s1][u]+dist[t2][u]+dist[u][v]+dist[v][t1]+dist[v][s2]);
		}
	}
	printf("%d\n",m-ans);
	return 0;
}