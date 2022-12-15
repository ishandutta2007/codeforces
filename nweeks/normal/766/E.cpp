#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
const int MAXK = 22;

vector<int> G[MAXN];
int subtree_size[MAXN];
int val[MAXN];
int bit_count[MAXK];
int updates[MAXK];
int par[MAXN];
bool blocked[MAXN];
long long ans(0);
queue<int> Q;
int total_paths;
int new_paths;
int N;

inline void read_input(void)
{
	cin >> N;
	for (int i(0); i < N; ++i)
		cin >> val[i];
	for (int i(1); i < N; ++i)
	{
		int u, v;
		cin >> u >> v;
		G[u-1].push_back(v-1);
		G[v-1].push_back(u-1);
	}
}

void buildtree(int u, int p)
{
	subtree_size[u] = 1;
	for (auto v : G[u])
		if (!blocked[v] and v != p)
		{
			par[v] = u;
			buildtree(v, u);
			subtree_size[u] += subtree_size[v];
		}
}

inline int getcentroid(int start)
{
	int centroid(start);
	int best(1e9);

	Q.push(start);
	while (!Q.empty())
	{
		int u = Q.front(); Q.pop();

		int sz = subtree_size[start] - subtree_size[u];
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

void runpaths(int u, int p, int xorsum, int start)
{
	new_paths++;
	for (int k(0); k < MAXK; ++k)
	{
		ans += (total_paths - bit_count[k]) * (xorsum & (1LL<<k));
		if ((xorsum & (1<<k)) == 0)
			ans += (1LL<<k) * bit_count[k];
		updates[k] += ((xorsum^start) & (1 << k)) != 0;
	}
	ans += xorsum^start;
	for (auto v : G[u])
		if (!blocked[v] and v != p)
			runpaths(v, u, xorsum^val[v], start);
}

void run(int entryPoint)
{
	fill(bit_count, bit_count + MAXK, 0);
	total_paths = 0;
	buildtree(entryPoint, entryPoint);
	int centroid = getcentroid(entryPoint);

	ans += val[centroid];
	for (auto v : G[centroid])
	{
		new_paths = 0;
		if (blocked[v])
			continue;
		runpaths(v, centroid, val[v], val[centroid]);
		for (int k(0); k < MAXK; ++k)
			bit_count[k] += updates[k], updates[k] = 0;
		total_paths += new_paths;
	}
	blocked[centroid] = true;
	for (auto v : G[centroid])
		if (!blocked[v])
			run(v);
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	read_input();
	run(0);
	cout << ans << endl;
}