#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define int long long
#define se second
#ifndef print
#define print(...)
#endif
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

class DSU
{
public:
	int *parent;
	int n;
	DSU(int n) : n(n) { parent = new int[n]; for (int i = 0; i < n; ++i) parent[i] = -1; };
	int root(int x);
	void merge(int x, int y);
	bool areInSame(int x, int y);
	~DSU();
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

DSU::~DSU()
{
	delete parent;
}

std::vector<int> adj[200005];
DSU d(200005);

int vis[200005];

int gl = -1;
int dfs(int u, int p, int l) {
	// print(u, p, l);
	vis[u] = l;
	int lev = l + 1;
	for (int v : adj[u]) {
		if (v != p) {
			if (vis[v]) {
				lev = min(lev, vis[v]);
				gl = v;
			} else {
				lev = min(lev, dfs(v, u, l + 1));
			}
		}
	}
	// print(u, lev, vis[u]);
	if (lev < l) d.merge(u, p);
	return lev; 
}

std::vector<int> a;

int dfs(int u, int p) {
	int uu = 0;
	for (int v : adj[u]) {
		if (v != p) {
			uu = max(dfs(v, u), uu);
		} 
	}
	return uu + a[u];
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	int m; cin >> m;
	a.resize(n, 0);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int ad[n] = {};
	for (int i = 0; i < m; ++i) {
		int u; cin >> u; u--;
		int v; cin >> v; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	int s; cin >> s; s--;
	// print(1);
	dfs(s, s, 1);
	// print(1);
	if (gl != -1) {
		for (int i = 0; i < n; ++i) vis[i] = 0;
		for (int i = 0; i < n; ++i) {
			int r = d.root(i);
			if (d.parent[r] < -2 && d.root(r) != s && !vis[r]) {
				vis[r] = 1;
				adj[s].pb(r);
				adj[r].pb(s);
			} 
		}
		for (int i = 0; i < n; ++i) vis[i] = 0;
		dfs(s, s, 1);
	}
	// print(adj[s]);
	// for (int i = 0; i < n; ++i) print(d.root(i));
	// print(1);
	d.parent[d.root(s)]--;
	for (int i = 0; i < n; ++i) vis[i] = 0;
	int ma = 0;
	for (int i = 0; i < n; ++i) {
		if (d.parent[d.root(i)] < -1) {
			for (int u : adj[i]) {
				if (d.parent[d.root(u)] == -1) {
					// print(u);
					ma = max(ma, dfs(u, i));
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		if (d.parent[d.root(i)] < -1) {
			ma += a[i];
		} 
	}
	cout << ma;
}