#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 5e4;
const int MAXK = 501;

int N, K;
ll ans(0);
vector<int> G[MAXN];
int at_dis[MAXK];
int updates[MAXK];
bool blocked[MAXN];
int subtree_size[MAXN];
int par[MAXN];
queue<int> Q;

void build_tree(int u, int p)
{
	subtree_size[u] = 1;
	for (auto v : G[u])
		if (!blocked[v] and v != p)
		{
			par[v] = u;
			build_tree(v, u);
			subtree_size[u] += subtree_size[v];
		}
}

int get_centroid(int entryPoint)
{
	int centroid(entryPoint);
	int best(1e9);

	Q.push(entryPoint);
	while (!Q.empty())
	{
		int u = Q.front(); Q.pop();

		int sz = subtree_size[entryPoint] - subtree_size[u];
		for (auto v : G[u])
			if (!blocked[v] and v != par[u])
			{
				Q.push(v);
				sz = max(sz, subtree_size[v]);
			}
		if (sz < best)
			best = sz, centroid = u;
	}
	return centroid;
}

void runpaths(int u, int d, int p)
{
	if (d > K) 
		return;
	ans += at_dis[K-d];
	updates[d]++;
	for (auto v : G[u])
		if (!blocked[v] and v != p)
			runpaths(v, d+1, u);
}

void run(int entryPoint)
{
	build_tree(entryPoint, entryPoint);
	entryPoint = get_centroid(entryPoint);
	for (int i(0); i <= K; ++i)
		at_dis[i] = updates[i] = 0;
	at_dis[0] = 1;

	for (auto v : G[entryPoint])
		if (!blocked[v])
		{
			runpaths(v, 1, entryPoint);
			for (int i(0); i <= K; ++i)
			{
				at_dis[i] += updates[i];
				updates[i] = 0;
			}
		}

	blocked[entryPoint] = true;
	for (auto v : G[entryPoint])
		if (!blocked[v])
			run(v);
}

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> N >> K;

	for (int i(1); i < N; ++i)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	run(0);
	cout << ans << endl;
}