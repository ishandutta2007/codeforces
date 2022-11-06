#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define PII pair<pair<int, int>, pair<int, int> >
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

class DSU
{
public:
	vector<int> parent;
	int n;
	DSU(int n) : n(n) { parent.resize(n, -1); };
	int root(int x);
	void merge(int x, int y);
	bool areInSame(int x, int y);
};

int DSU::root(int x) { return (parent[x] < 0 ? x : (parent[x] = root(parent[x]))); }

void DSU::merge(int x, int y)
{
	if ((x = root(x)) == (y = root(y))) return;
	if (parent[x] > parent[y]) swap(x, y);
	parent[x] += parent[y];
	parent[y] = x;
}

bool DSU::areInSame(int x, int y) { return (root(x) == root(y)); }

std::vector<std::vector<pair<int, int>> > adj;
std::vector<std::vector<int> > up, op;
std::vector<int> depth, pa, val;
int l;

int lca(int a, int b) {
	if (depth[a] > depth[b]) swap(a, b);
	int d = depth[b] - depth[a];
	int ma = -1;
	for (int i = 0; i <= l; ++i) {
		if (d & (1 << i)) {
			ma = max(ma, op[b][i]);
			b = up[b][i];
		}
	}
	if (a == b) return ma;
	for (int i = l; i >= 0 ; --i) {
		if (up[a][i] != up[b][i]) {
			ma = max(ma, max(op[b][i], op[a][i]));
			a = up[a][i], b = up[b][i];
		}
	}
	return max(ma, max(op[a][0], op[b][0]));
}
void _pre_dfs(int u) {
	for (auto v : adj[u])
		if (v.fi != up[u][0])
		{
			depth[v.fi] = depth[u] + 1;
			up[v.fi][0] = u;
			op[v.fi][0] = v.se;
			_pre_dfs(v.fi);
		}
}

void init(int n) {
	depth.resize(n);
	l = ceil(log2(n));
	up.assign(n, std::vector<int> (l + 1));
	op.assign(n, std::vector<int> (l + 1));
	depth[0] = 0;
	up[0][0] = 0;
	op[0][0] = 0;
	_pre_dfs(0);
	for (int i = 1; i <= l; ++i) for (int u = 0; u < n; ++u) up[u][i] = up[up[u][i - 1]][i - 1];
	for (int i = 1; i <= l; ++i) for (int u = 0; u < n; ++u) op[u][i] = max(op[up[u][i - 1]][i - 1], op[u][i - 1]);
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	int m; cin >> m;
	std::vector<PII> gr;
	std::vector<int> vis(m, -2);
	for (int i = 0; i < m; ++i) {
		int u; cin >> u; u--;
		int v; cin >> v; v--;
		int w; cin >> w;
		gr.push_back({{w, i}, {u, v}});
	}
	sort(gr.begin(), gr.end());
	adj.resize(n);
	DSU d(n);
	for (int i = 0; i < m; ++i) {
		if (!d.areInSame(gr[i].se.fi, gr[i].se.se)) {
			d.merge(gr[i].se.fi, gr[i].se.se);
			adj[gr[i].se.fi].push_back({gr[i].se.se, gr[i].fi.fi});
			adj[gr[i].se.se].push_back({gr[i].se.fi, gr[i].fi.fi});
			vis[gr[i].fi.se] = -1;
		}
	}
	init(n);
	for (int i = 0; i < m; ++i) {
		if (vis[gr[i].fi.se] != -1) {
			vis[gr[i].fi.se] = lca(gr[i].se.fi, gr[i].se.se);
		} 
	}
	for (int i = 0; i < m; ++i) {
		if (vis[i] != -1) {
			cout << vis[i] << " ";
		} 
	}
}