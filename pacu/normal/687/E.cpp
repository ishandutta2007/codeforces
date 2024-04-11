#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N,M;
vector<int> edges[5000];
bool con[5000][5000];
int dist[5000][5000];
int mcyc[5000];

int que[5000];
bool inque[5000];

void bfs(int source)
{
	for(int i=0;i<N;i++)
		inque[i] = 0, dist[source][i] = 1000000000;
	inque[source] = 1;
	int len = 1;
	int cur = 0;
	que[0] = source;
	dist[source][source] = 0;
	while(cur < len)
	{
		int x = que[cur];
		//cout << source << ' ' << x << ": " << dist[source][x] << '\n';
		for(int j=0;j<edges[x].size();j++)
			if(!inque[edges[x][j]])
			{
				inque[edges[x][j]] = 1;
				que[len++] = edges[x][j];
				dist[source][edges[x][j]] = 1 + dist[source][x];
			}
		cur++;
	}
}

vector<int> redges[5000];
bool vis[5000];
int comp[5000];
vector<int> L;
int C;

void dfsSCC(int i)
{
	vis[i] = 1;
	for(int j=0;j<edges[i].size();j++)
		if(!vis[edges[i][j]])
			dfsSCC(edges[i][j]);
	L.push_back(i);
}

void dfsSCC2(int i,int c)
{
	comp[i] = c;
	for(int j=0;j<redges[i].size();j++)
		if(!comp[redges[i][j]])
			dfsSCC2(redges[i][j],c);
}

void scc()
{
	for(int i=0;i<N;i++) vis[i] = comp[i] = 0;
	for(int i=0;i<N;i++)
		for(int j=0;j<edges[i].size();j++)
			redges[edges[i][j]].push_back(i);
	L.clear();
	for(int i=0;i<N;i++)
		if(!vis[i])
			dfsSCC(i);
	reverse(L.begin(),L.end());
	for(int i=0;i<N;i++)
		if(!comp[L[i]])
			dfsSCC2(L[i],++C);
}

vector<int> cedges[5001];
int cmcyc[5001];
bool hasTail[5001];
bool cvis[5001];

int main()
{
	cin >> N >> M;
	int a,b;
	for(int i=0;i<M;i++)
	{
		cin >> a >> b;
		a--,b--;
		con[a][b] = 1;
		edges[a].push_back(b);
	}
	for(int i=0;i<N;i++)
		bfs(i);
	for(int i=0;i<N;i++)
	{
		mcyc[i] = 1000000000;
		for(int j=0;j<N;j++)
			if(j!=i && con[j][i])
				mcyc[i] = min(mcyc[i],dist[i][j]+1);
	}
	scc();
	for(int i=0;i<N;i++)
		for(int j=0;j<edges[i].size();j++)
			if(comp[i] != comp[edges[i][j]])
				cedges[comp[i]].push_back(comp[edges[i][j]]);
	for(int i=1;i<=C;i++)
		cmcyc[i] = 1000000000;
	for(int i=0;i<N;i++)
		cmcyc[comp[i]] = min(cmcyc[comp[i]],mcyc[i]);
	int ans = N;
	for(int i=C;i>=1;i--)
	{
		if(cedges[i].size()==0 && cmcyc[i] < 1000000000)
			ans += 998*cmcyc[i] + 1;
	}
	cout << ans << '\n';
}