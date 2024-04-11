#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

char ranks[MAXN];

vector<int> G[MAXN];
int par[MAXN];
int subtree_size[MAXN];
bool blocked[MAXN];
int N;
queue<int> Q;

void build_tree(int u, int p)
{
	subtree_size[u] = 1;
	for (auto v : G[u])
		if (v != p and !blocked[v])
		{
			par[v] = u;
			build_tree(v, u);
			subtree_size[u] += subtree_size[v];
		}
}

int getcentroid(int entryPoint)
{
	int best(1e9);
	int centroid = entryPoint;
	Q.push(centroid);
	par[entryPoint] = -1;

	while (!Q.empty())
	{
		int u = Q.front(); Q.pop();
		
		int sz = subtree_size[entryPoint] - subtree_size[u];
		for (auto v : G[u])
			if (!blocked[v] and par[u] != v)
			{
				sz = max(sz, subtree_size[v]);
				Q.push(v);
			}
		if (best > sz)
			best = sz, centroid = u;
	}
	return centroid;
}

void run(int entryPoint, char letter)
{
	build_tree(entryPoint, entryPoint);
	entryPoint = getcentroid(entryPoint);

	ranks[entryPoint] = letter;
	blocked[entryPoint] = true;
	for (auto v : G[entryPoint])
		if (!blocked[v])
			run(v, letter + 1);
}

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> N;
	for (int i(1); i < N; ++i)
	{
		int u, v;
		cin >> u >> v;
		G[u-1].push_back(v-1);
		G[v-1].push_back(u-1);
	}
	run(0, 'A');
	for (int i(0); i < N; ++i)
		cout << ranks[i] << ' ';
	cout << endl;

}