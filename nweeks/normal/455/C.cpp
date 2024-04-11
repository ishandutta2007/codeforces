#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5;

vector<int> G[MAXN];

int id[MAXN];
int sz[MAXN];
int N, M, Q;
int furthest, maxdis, diameter;

int find(int i)
{
	return id[i] == i ? i : id[i] = find(id[i]);
}

void merge(int u, int v)
{
	id[find(v)] = find(u);
}

void DFS(int u, int d, int p)
{
	if (d > maxdis)
		furthest = u, maxdis = d;
	for (auto v : G[u])
		if (v != p)
			DFS(v, d + 1, u);
}

void DFS_slave(int u, int d, int p)
{
	if (d > diameter)
		diameter = d;
	for (auto v : G[u])
		if (v != p)
			DFS_slave(v, d + 1, u);
}

void comp(int start)
{
	furthest = start;
	maxdis = 0;
	DFS(start, 0, start);
	diameter = 0;
	DFS_slave(furthest, 0, furthest);
	sz[find(start)] = diameter;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M >> Q;
	for (int i(0); i < N; ++i)
		id[i] = i, sz[i] = -1;

	for (int i(0); i < M; ++i)
	{
		int u, v;
		cin >> u >> v;
		G[u-1].push_back(v-1);
		G[v-1].push_back(u-1);
		merge(u-1, v-1);
	}

	for (int i(0); i < N; ++i)
		if (sz[find(i)] == -1)
			comp(i);

	while (Q--)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			int u;
			cin >> u;
			cout << sz[find(u-1)] << '\n';
		}
		else
		{
			int u, v;
			cin >> u >> v;
			--u, --v;
			if (find(u) == find(v)) continue;
			sz[find(u)] = max({sz[find(u)], sz[find(v)], (sz[find(u)]+1)/2 + 1 + (sz[find(v)]+1)/2});
			merge(u, v);
		}
	}
}