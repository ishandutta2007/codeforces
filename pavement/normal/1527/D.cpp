#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef double db;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int T, N, dep[200005], sz[200005], anc[200005][25];
vector<int> adj[200005];

int dfs(int n, int e = -1) {
	anc[n][0] = e;
	sz[n] = 1;
	for (int i = 1; i <= 20; i++)
		if (anc[n][i - 1] != -1) anc[n][i] = anc[anc[n][i - 1]][i - 1];
	for (auto u : adj[n])
		if (u != e) {
			dep[u] = dep[n] + 1;
			sz[n] += dfs(u, n);
		}
	return sz[n];
}

int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = 20; i >= 0; i--)
		if (dep[u] - (1 << i) >= dep[v]) u = anc[u][i];
	if (u == v) return u;
	for (int i = 20; i >= 0; i--)
		if (anc[u][i] != anc[v][i]) {
			u = anc[u][i];
			v = anc[v][i];
		}
	return anc[u][0];
}

int dist(int u, int v) {
	return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

ii extend(int p1, int p2, int x) {
	if (dist(p1, x) + dist(x, p2) == dist(p1, p2)) return mp(p1, p2);
	if (dist(p1, x) > dist(p2, x)) swap(p1, p2);
	if (dist(p1, x) + dist(p1, p2) == dist(x, p2)) return mp(x, p2);
	return mp(-1, -1);
}

int cnt(int x, int y) { // if the tree was rooted at x, what is the size of y's subtree?
	if (lca(x, y) == y) {
		int curr = x;
		for (int i = 20; i >= 0; i--)
			if (anc[curr][i] != -1 && dep[anc[curr][i]] > dep[y])
				curr = anc[curr][i];
		return sz[y] - sz[curr];
	} else {
		return sz[y];
	}
	
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) adj[i].clear(), dep[i] = sz[i] = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j <= 20; j++) anc[i][j] = -1;
		for (int i = 1, u, v; i < N; i++) {
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		int p1 = 0, p2 = 0, tmp = 0, tmp2 = 0, ru = 0;
		dfs(0);
		for (auto u : adj[0]) {
			tmp += sz[u] * (sz[u] - 1) / 2;
			int s1;
			if (lca(1, u) == u) s1 = sz[u] - sz[1];
			else s1 = sz[u];
			tmp2 += ru * s1 + s1;
			ru += s1;
		}
		cout << tmp << ' ' << tmp2 << ' ';
		bool z = 0;
		for (int i = 2; i < N; i++) {
			if (z) {
				cout << "0 ";
				continue;
			}
			// add node i - 1 to the path
			ii tmp = extend(p1, p2, i - 1);
			if (tmp.first == -1) {
				cout << "0 ";
				z = 1;
				continue;
			}
			p1 = tmp.first;
			p2 = tmp.second;
			ii tmp2 = extend(p1, p2, i);
			if (tmp2.first > tmp2.second) swap(tmp2.first, tmp2.second);
			if (p1 > p2) swap(p1, p2);
			if (mp(p1, p2) == tmp2) {
				cout << "0 ";
				continue;
			}
			if (dist(i, p1) > dist(i, p2)) swap(p1, p2);
			if (dist(i, p1) + dist(p1, p2) == dist(i, p2)) {
				//cout << "\nNOW " << p1 << ' ' << p2 << ' ' << cnt(p2, p1) << ' ' << cnt(p1, i) << '\n';
				int f1 = cnt(p2, p1) - cnt(p1, i), f2 = cnt(p1, p2);
				cout << f1 * f2 << ' ';
			} else {
				int f1 = cnt(p1, p2), f2 = cnt(p2, p1);
				cout << f1 * f2 << ' ';
			}
		}
		if (z) {
			cout << "0\n";
		} else {
			ii tmp = extend(p1, p2, N - 1);
			if (tmp.first != -1) cout << "1\n";
			else cout << "0\n";
		}
	}
}