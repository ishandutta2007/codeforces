#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define INF (1<<30)

int N,M,capital,L;
int weight[200000];
int rend[200000];
vector<vector<int> > edges;
int par[100000];
int dist[100000];
bool vis[100000];

struct cmp
{
	bool operator()(int a,int b)
	{
		if(dist[a]==dist[b])
			return a<b;
		return dist[a]<dist[b];
	}
};

set<int,cmp> S;

void dijkstra()
{
	dist[capital] = 0;
	for(int i=0;i<N;i++)
		if(i!=capital)
			dist[i] = INF;
	for(int i=0;i<N;i++)
		S.insert(i);
	while(S.size() > 0)
	{
		int cur = *S.begin();
		int next;
		S.erase(S.begin());
		for(int j=0;j<edges[cur].size();j++)
		{
			next = edges[cur][j];
			if(dist[rend[next]] > (dist[cur]+weight[next]))
			{
				S.erase(rend[next]);
				dist[rend[next]] = dist[cur]+weight[next];
				par[rend[next]] = cur;
				S.insert(rend[next]);
			}
		}
	}
}


int main()
{
	cin >> N >> M >> capital;
	capital--;
	for(int i=0;i<N;i++)
		edges.push_back(vector<int>());
	int a,b,w;
	for(int i=0;i<M;i++)
	{
		cin >> a >> b >> w;
		a--,b--;
		edges[a].push_back(2*i);
		edges[b].push_back(2*i+1);
		weight[2*i] = weight[2*i+1] = w;
		rend[2*i] = b;
		rend[2*i+1] = a;
	}
	cin >> L;
	dijkstra();
	if(L==0)
	{
		cout << 1 << endl;
		return 0;
	}
	int cntVertices = 0;
	int cntEdges = 0;
	for(int i=0;i<N;i++)
	{
		if(dist[i]==L)
			cntVertices++;
		for(int j=0;j<edges[i].size();j++)
		{
			int a = i;
			int b = rend[edges[i][j]];
			int w = weight[edges[i][j]];
			if((dist[a]>L)&&(dist[b]<L))
				cntEdges++;
			else if((dist[a]<L)&&(dist[b]>L))
				cntEdges++;
			else if((dist[a]+dist[b]+w == 2*L)&&(dist[a]<L)&&(dist[b]<L))
				cntEdges++;
			else if((dist[a]+dist[b]+w > 2*L)&&(dist[a]==L)&&(dist[b]<L))
				cntEdges++;
			else if((dist[a]+dist[b]+w > 2*L)&&(dist[a]<L)&&(dist[b]==L))
				cntEdges++;
			else if((dist[a]+dist[b]+w > 2*L)&&(dist[a]<L)&&(dist[b]<L))
				cntEdges += 2;
		}
	}
	cout << cntVertices+cntEdges/2 << endl;
	return 0;
}