# include <cstdio>
# include <queue>
# include <cstring>
using namespace std;

int M,N;
char inp[51][51];
char dist[51][51];

int neigh[][2]={{0,-1},{0,1},{-1,0},{1,0}};

queue<int>bfsq;

bool bfs(int x,int y)
{
	memset(dist,-1,51*51);
	int u=x*64+y;
	dist[x][y]=0;
	while(!bfsq.empty())bfsq.pop();
	bfsq.push(u);
	
	while(!bfsq.empty())
	{
		u=bfsq.front();
		bfsq.pop();
		x=u>>6,y=u&63;
		for(int n=0;n<4;n++)
		{
			for(int xx=x+neigh[n][0],yy=y+neigh[n][1];xx>=0&&yy>=0&&xx<M&&yy<N;xx+=neigh[n][0],yy+=neigh[n][1])
			{
				if(inp[xx][yy]=='W')break;
				if(dist[xx][yy]>=0)continue;
				dist[xx][yy]=dist[x][y]+1;
				if(dist[xx][yy]>2)return true;
				bfsq.push((xx<<6)|yy);
			}
		}
	}
	
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
			if(inp[i][j]=='B'&&dist[i][j]<0)return true;
	return false;
}

int main()
{
	scanf("%d%d",&M,&N);
	for(int i=0;i<M;i++)
		scanf("%s",inp[i]);
	
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
		{
			if(inp[i][j]=='W')continue;
			if(bfs(i,j))
			{
				printf("NO\n");
				return 0;
			}
		}
	printf("YES\n");
	return 0;
}