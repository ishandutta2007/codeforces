#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 50;

int n, m, id[N][55], d[N * 55], tot;
vector<pair<int, int>> G[N * 55];
vector<tuple<int, int, int>> edges;

void dijkstra(int s)
{
	priority_queue<pair<int, int>> pq;
	memset(d, 0x3f, sizeof d);
	d[s] = 0;
	pq.emplace(-d[s], s);
	while (!pq.empty())
	{
		auto [dist, x] = pq.top(); pq.pop();
		if (-dist == d[x])
		{
			for (auto [y, w] : G[x])
			{
				if (d[y] > d[x] + w)
				{
					d[y] = d[x] + w;
					pq.emplace(-d[y], y);
				}
			}
		}
	}
}

void add_edges(int u, int v, int w)
{
	for (int k = 1; k <= 50; ++k)
		if (id[u][k])
			G[id[u][k]].emplace_back(id[v][0], (k + w) * (k + w));
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) id[i][0] = ++tot;
	for (int i = 1; i <= m; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		edges.emplace_back(u, v, w);
		if (!id[u][w]) id[u][w] = ++tot;
		if (!id[v][w]) id[v][w] = ++tot;
		G[id[u][0]].emplace_back(id[v][w], 0);
		G[id[v][0]].emplace_back(id[u][w], 0);
	}
	for (auto [u, v, w] : edges)
		add_edges(u, v, w), add_edges(v, u, w);
	dijkstra(1);
	for (int i = 1; i <= n; ++i)
		if (d[i] == 0x3f3f3f3f)
			cout << -1 << " ";
		else 
			cout << d[i] << " ";
}