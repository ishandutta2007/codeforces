#include <iostream>
#include <vector>
using namespace std;
#define INF 1000000000

int N,M;
vector<int> edges[3000];

int d[3000][3000];
int mdIn[3000][3];
int mdOut[3000][3];

int que[3000];
bool vis[3000];

void bfs(int source)
{
	for(int i=0;i<N;i++)
		d[source][i] = INF, vis[i] = 0;
	int cur = 0;
	int len = 1;
	vis[source] = 1;
	d[source][source] = 0;
	que[0] = source;
	while(cur < len)
	{
		int x = que[cur];
		for(int j=0;j<edges[x].size();j++)
			if(!vis[edges[x][j]])
			{
				vis[edges[x][j]] = 1;
				d[source][edges[x][j]] = d[source][x]+1;
				que[len++] = edges[x][j];
			}
		cur++;
	}
}

int main()
{
	cin >> N >> M;
	int u,v;
	for(int i=0;i<M;i++)
	{
		cin >> u >> v;
		u--,v--;
		edges[u].push_back(v);
	}
	for(int i=0;i<N;i++)
		bfs(i);
	for(int source=0;source<N;source++)
	{
		for(int k=0;k<3;k++) mdOut[source][k] = source;
		for(int i=0;i<N;i++) if(d[source][i]<INF)
		{
			if(d[source][i] >= d[source][mdOut[source][0]])
			{
				mdOut[source][2] = mdOut[source][1];
				mdOut[source][1] = mdOut[source][0];
				mdOut[source][0] = i;
			}
			else if(d[source][i] >= d[source][mdOut[source][1]])
			{
				mdOut[source][2] = mdOut[source][1];
				mdOut[source][1] = i;
			}
			else if(d[source][i] > d[source][mdOut[source][2]])
				mdOut[source][2] = i;
		}
		
		for(int k=0;k<3;k++) mdIn[source][k] = source;
		for(int i=0;i<N;i++) if(d[i][source]<INF)
		{
			if(d[i][source] >= d[mdIn[source][0]][source])
			{
				mdIn[source][2] = mdIn[source][1];
				mdIn[source][1] = mdIn[source][0];
				mdIn[source][0] = i;
			}
			else if(d[i][source] >= d[mdIn[source][1]][source])
			{
				mdIn[source][2] = mdIn[source][1];
				mdIn[source][1] = i;
			}
			else if(d[i][source] > d[mdIn[source][2]][source])
				mdIn[source][2] = i;
		}
	}
		
		
	int best[4];
	int dbest = 0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(i==j) continue;
			int c;
			if(d[i][j]==INF) continue;
			for(int l=0;l<3;l++)
			{
				if(mdIn[i][l]==i || mdIn[i][l]==j) continue;
				for(int m=0;m<3;m++)
				{
					if(mdOut[j][m]==i || mdOut[j][m]==j || mdOut[j][m]==mdIn[i][l]) continue;
					c = d[i][j]+d[mdIn[i][l]][i]+d[j][mdOut[j][m]];
					if(c>dbest)
					{
						best[0] = mdIn[i][l], best[1] = i, best[2] = j, best[3] = mdOut[j][m];
						dbest = c;
					}
				}
			}
		}
	}
	cout << best[0]+1 << ' ' << best[1]+1 << ' ' << best[2]+1 << ' ' << best[3]+1 << '\n';
}