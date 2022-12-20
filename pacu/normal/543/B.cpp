#include <iostream>
#include <vector>
using namespace std;

int dist[3000][3000];
vector<vector<int> > edges;

int que[3000];
bool inq[3000];
int N,M;

void bfs(int v)
{
	int cur = 0;
	int len = 1;
	que[0] = v;
	dist[v][v] = 0;
	for(int i=0;i<N;i++)
		inq[i] = 0;
	inq[v] = 1;
	int x;
	while(cur<len)
	{
		x = que[cur];
		for(int j=0;j<edges[x].size();j++)
		{
			if(!inq[edges[x][j]])
			{
				dist[v][edges[x][j]] = 1+dist[v][x];
				que[len++] = edges[x][j];
				inq[edges[x][j]] = 1;
			}
		}
		cur++;
	}
}

int main()
{
	cin >> N >> M;
	for(int i=0;i<N;i++)
		edges.push_back(vector<int>());
	int a,b;
	for(int i=0;i<M;i++)
	{
		cin >> a >> b;
		a--,b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	for(int i=0;i<N;i++)
		bfs(i);
	int s1,t1,l1;
	int s2,t2,l2;
	cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
	s1--,t1--,s2--,t2--;
	int best = dist[s1][t1]+dist[s2][t2];
	if((dist[s1][t1]>l1)||(dist[s2][t2]>l2))
	{
		cout << -1 << "\n";
		return 0;
	}
	int cur1,cur2;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(i==j) continue;
			cur1 = dist[s1][i]+dist[i][j]+dist[j][t1];
			cur2 = dist[s2][i]+dist[i][j]+dist[j][t2];
			if((cur1>l1)||(cur2>l2)) continue;
			if((cur1+cur2-dist[i][j])<best)
				best = cur1+cur2-dist[i][j];
		}
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(i==j) continue;
			cur1 = dist[s1][i]+dist[i][j]+dist[j][t1];
			cur2 = dist[s2][j]+dist[i][j]+dist[i][t2];
			if((cur1>l1)||(cur2>l2)) continue;
			if((cur1+cur2-dist[i][j])<best)
				best = cur1+cur2-dist[i][j];
		}
	}
	cout << M-best << "\n";
	return 0;
}