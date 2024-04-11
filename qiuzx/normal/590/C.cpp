#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 1010
using namespace std;
char grid[N][N];
int n,m,dist[5][N][N],dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},ans=INF63;
deque<pair<int,int> > dq;
int main(){
	int i,j,k,x,y,tx,ty;
	scanf("%d%d",&n,&m);
	memset(dist,63,sizeof(dist));
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf(" %c",&grid[i][j]);
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<m;k++)
			{
				if((grid[j][k]-'1')==i)
				{
					dq.push_back(make_pair(j,k));
					dist[i][j][k]=0;
				}
			}
		}
		while(!dq.empty())
		{
			x=dq.front().F;
			y=dq.front().S;
			dq.pop_front();
			for(j=0;j<4;j++)
			{
				tx=x+dx[j];
				ty=y+dy[j];
				if(tx<0||tx>=n||ty<0||ty>=m)
				{
					continue;
				}
				if(grid[tx][ty]=='#')
				{
					continue;
				}
				if(grid[x][y]=='.'&&dist[i][tx][ty]>dist[i][x][y]+1)
				{
					dist[i][tx][ty]=dist[i][x][y]+1;
					dq.push_back(make_pair(tx,ty));
				}
				else if(grid[x][y]>='1'&&grid[x][y]<='3'&&dist[i][tx][ty]>dist[i][x][y])
				{
					dist[i][tx][ty]=dist[i][x][y];
					dq.push_front(make_pair(tx,ty));
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(dist[0][i][j]>=INF||dist[1][i][j]>=INF||dist[2][i][j]>=INF)
			{
				continue;
			}
			if(grid[i][j]=='.')
			{
				ans=min(ans,dist[0][i][j]+dist[1][i][j]+dist[2][i][j]+1);
			}
			else
			{
				ans=min(ans,dist[0][i][j]+dist[1][i][j]+dist[2][i][j]);
			}
		}
	}
	if(ans>=INF)
	{
		puts("-1");
	}
	else
	{
		printf("%d\n",ans);
	}
	return 0;
}