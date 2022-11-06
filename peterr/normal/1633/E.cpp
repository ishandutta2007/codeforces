#include <bits/stdc++.h>
 
using namespace std;

struct dsu
{
	dsu(int n)
	{
		par = vector<int>(n);
		sz = vector<int>(n);
		for (int i = 0; i < n; i++)
		{
			par[i] = i;
			sz[i] = 1;
		}
	}
	
	int getRoot(int x)
	{
		if (par[x] != x)
			par[x] = getRoot(par[x]);
		return par[x];
	}
	
	bool mge(int x, int y)
	{
		x = getRoot(x);
		y = getRoot(y);
		if (x == y)
			return false;
		if (sz[x] > sz[y])
			swap(x, y);
		par[x] = y;
		sz[y] += sz[y];
		return true;
	}
	
	vector<int> par;
	vector<int> sz;
};

const int MAXM = 300;
const int MAXK = 1E7;
const int MAXN = 50;
tuple<int, int, int> edges[MAXM];
int queries[MAXK];
vector<tuple<int, int, int>> events;
vector<int> chosenEdges;
bool isChosen[MAXM];
vector<int> adjList[MAXN + 1];
bool visited[MAXN + 1];

void dfs(int v)
{
	visited[v] = true;
	for (int adj : adjList[v])
	{
		if (visited[adj])
			continue;
		dfs(adj);
	}
}

void addEdge(int ind)
{
	chosenEdges.push_back(ind);
	isChosen[ind] = true;
	int u = get<1>(edges[ind]);
	int v = get<2>(edges[ind]);
	adjList[u].push_back(v);
	adjList[v].push_back(u);
}

void removeEdge(int ind)
{
	chosenEdges.erase(find(chosenEdges.begin(), chosenEdges.end(), ind));
	isChosen[ind] = false;
	int u = get<1>(edges[ind]);
	int v = get<2>(edges[ind]);
	adjList[u].erase(find(adjList[u].begin(), adjList[u].end(), v));
	adjList[v].erase(find(adjList[v].begin(), adjList[v].end(), u));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int v, u, w;
		cin >> v >> u >> w;
		edges[i] = {w, u, v};
	}
	sort(edges, edges + m);
	for (int i = 0; i < m; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			events.push_back({(get<0>(edges[i]) + get<0>(edges[j]) + 1) / 2, i, j});
		}
	}
	sort(events.begin(), events.end());
	dsu kruskal(n + 1);
	for (int i = 0; i < m; i++)
	{
		int u = get<1>(edges[i]);
		int v = get<2>(edges[i]);
		if (kruskal.mge(u, v))
			addEdge(i);
	}
	int p, k, a, b, c;
	cin >> p >> k >> a >> b >> c;
	for (int i = 0; i < p; i++)
	{
		cin >> queries[i];
	}
	for (int i = p; i < k; i++)
	{
		queries[i] = (int) (((long long) queries[i - 1] * a + b) % c);
	}
	sort(queries, queries + k);
	int ptr = 0;
	long long ans = 0;
	for (int i = 0; i < k; i++)
	{
		int q = queries[i];
		while (ptr < (int) events.size() && get<0>(events[ptr]) <= q)
		{
			int u = get<1>(events[ptr]);
			int v = get<2>(events[ptr]);
			ptr++;
			if (isChosen[u] == isChosen[v])
				continue;
			if (isChosen[v])
				continue;
			fill(visited, visited + MAXN + 1, false);
			removeEdge(u);
			dfs(1);
			int node1 = get<1>(edges[v]);
			int node2 = get<2>(edges[v]);
			if (visited[node1] != visited[node2])
			{
				addEdge(v);
			}
			else
			{
				addEdge(u);
			}
		}
		long long sum = 0;
		for (int edgeInd : chosenEdges)
		{
			sum += abs(get<0>(edges[edgeInd]) - q);
		}
		ans = ans ^ sum;
	}
	cout << ans << "\n";
	return 0;
}