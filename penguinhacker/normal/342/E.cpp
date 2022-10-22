#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array


#define debug(x) cerr << "[" << #x << "] = [" << x << "]\n"

template<class A, class B> ostream& operator<< (ostream& out, pair<A, B> p) {
	return out << '[' << p.first << ", " << p.second << ']';
}

template<class A, int sz> ostream& operator<< (ostream& out, ar<A, sz> a) {
	out << '[';
	for (int i = 0; i < sz; ++i) {
		if (i > 0) out << ", ";
		out << a[i];
	}
	return out << ']';
}

template<class T> ostream& operator<< (ostream& out, vector<T>& v) {
	out << '[';
	for (int i = 0; i < v.size(); ++i) {
		if (i > 0) {
			out << ", ";
		}
		out << v[i];
	}
	return out << ']';
}


const int mxN = 1e5;
int n, m, sz[mxN], best[mxN];
bool removed[mxN];
vector<int> adj[mxN];
vector<pair<int, int>> par[mxN];

int dfs_sz(int u, int p = -1) {
	sz[u] = 1;
	for (int v : adj[u]) if (v != p && !removed[v])
		sz[u] += dfs_sz(v, u);
	return sz[u];
}

int get_centroid(int u, int p, int subtree_size) {
	for (int v : adj[u]) if (v != p && !removed[v] && 2 * sz[v] > subtree_size)
		return get_centroid(v, u, subtree_size);
	return u;
}

void dfs(int u, int centroid, int p = -1, int d = 0) {
	par[u].emplace_back(centroid, d);
	for (int v : adj[u]) if (v != p && !removed[v])
		dfs(v, centroid, u, d + 1);
}

void centroid(int u = 0) {
	u = get_centroid(u, -1, dfs_sz(u));
	removed[u] = 1;
	dfs(u, u);
	for (int v : adj[u]) if (!removed[v]) {
		centroid(v);
	}
	removed[u] = 0;
}

void upd(int u) {
	for (pair<int, int> p : par[u]) {
		best[p.first] = min(best[p.first], p.second);
	}
}

void qry(int u) {
	int ans = 1e9;
	for (pair<int, int> p : par[u]) {
		ans = min(ans, best[p.first] + p.second);
	}
	assert(ans < 1e9);
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i < n; ++i) {
		int a, b; cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	centroid();
	memset(best, 0x3f, sizeof(best));
	upd(0);
	for (int i = 0; i < m; ++i) {
		int t, u; cin >> t >> u, --u;
		if (t == 1) { // change node to red
			upd(u);
		}
		else if (t == 2) { // qry for answer
			qry(u);
		}
		else assert(0);
	}
	return 0;
}