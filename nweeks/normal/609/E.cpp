#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
const int MAXK = 20;

typedef long long ll;

struct Arc
{
	ll u, v, w;

	bool operator<(Arc other) const
	{
		return w < other.w;
	}
};

struct Edge
{
	ll v, w;
};

vector<Edge> G[MAXN];
int par[MAXK][MAXN];
int depth[MAXN];
ll	biggest_edge[MAXK][MAXN];
vector<Arc>	arcs;
int	id[MAXN];

int find(int i) { return id[i] == i ? i : id[i] = find(id[i]); }
void merge(int a, int b) { id[find(b)] = find(a); }

int N, M;

void read_input(void)
{
	cin >> N >> M;

	for (int i(0); i < M; ++i)
	{
		ll u, v, w;
		cin >> u >> v >> w;
		arcs.push_back({u-1, v-1, w});
	}
}

ll get_mst(void)
{
	vector<Arc> cpy(M);
	for (int i(0); i < M; ++i)
		cpy[i] = arcs[i];
	sort(cpy.begin(), cpy.end());
	ll ans(0);

	for (auto e : cpy)
	{
		if (find(e.u) == find(e.v)) continue;
		ans += e.w;
		G[e.u].push_back({e.v, e.w});
		G[e.v].push_back({e.u, e.w});
		merge(e.u, e.v);
	}
	return ans;
}

void root_tree(int u, int p, int d)
{
	depth[u] = d;
	par[0][u] = p;
	for (auto v : G[u])
		if (v.v != p)
		{
			biggest_edge[0][v.v] = v.w;
			root_tree(v.v, u, d+1);
		}
}

void build_sparse(void)
{
	for (int k(1); k < MAXK; ++k)
		for (int i(0); i < MAXN; ++i)
			if (depth[i] - (1 << k) >= 0)
			{
				par[k][i] = par[k-1][par[k-1][i]];
				biggest_edge[k][i] = max(biggest_edge[k-1][i], biggest_edge[k-1][par[k-1][i]]);
			}
}

ll get_lca_cost(int u, int v)
{
	ll	ans(0);
	if (depth[u] < depth[v]) swap(u, v);
	int diff = depth[u] - depth[v];
	for (int k(0); k < MAXK; ++k)
		if (diff & (1<<k))
		{
			ans = max(ans, (ll)biggest_edge[k][u]);
			u = par[k][u];
		}
	if (u == v)
		return ans;
	for (int k(MAXK-1); k >= 0; --k)
	{
		if (depth[u] - (1<<k) < 0) continue;
		if (par[k][u] == par[k][v]) continue;
		ans = max(ans, max(biggest_edge[k][u], biggest_edge[k][v]));
		u = par[k][u];
		v = par[k][v];
	}
	ans = max(ans, biggest_edge[0][u]);
	ans = max(ans, biggest_edge[0][v]);
	return ans;
}

int main(void)
{
	ios_base::sync_with_stdio(false);

	read_input();
	for (int i(0); i < N; ++i)
		id[i] = i;
	ll mst = get_mst();
	root_tree(0, 0, 0);
	build_sparse();

	for (auto e : arcs)
	{
		cout << mst + e.w - get_lca_cost(e.u, e.v) << '\n';
	}
}