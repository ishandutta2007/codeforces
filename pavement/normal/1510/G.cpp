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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int T, N, K, sz[105], to[105];
vector<int> path, adj[105], vec[105];

int dfs(int n) {
	int curm = 0;
	for (auto u : adj[n]) {
		int tmp = dfs(u);
		if (tmp > curm) {
			curm = tmp;
			to[n] = u;
		}
	}
	vec[n].pb(n);
	for (int k : vec[to[n]]) vec[n].pb(k);
	return curm + 1;
}

int getsz(int n) {
	sz[n] = 1;
	for (auto u : adj[n])
		sz[n] += getsz(u);
	return sz[n];
}

void getall(int n, int x) {
	if (x <= 0) return;
	for (auto u : adj[n]) {
		if (min(x, sz[u]) > 0) {
			path.pb(u);
			getall(u, min(x, sz[u]) - 1);
			path.pb(n);
			x -= min(x, sz[u]);
		}
	}
}

void dfs2(int n) {
	for (auto u : adj[n]) {
		if (u == to[n]) continue;
		if (min(sz[u], K) > 0) {
			path.pb(u);
			getall(u, min(sz[u], K) - 1);
			path.pb(n);
			K -= min(sz[u], K);
		}
	}
	if (to[n]) {
		path.pb(to[n]);
		dfs2(to[n]);
	}
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		for (int i = 0; i < 105; i++) {
			sz[i] = to[i] = 0;
			adj[i].clear();
			vec[i].clear();
		}
		path.clear();
		cin >> N >> K;
		for (int i = 2, p; i <= N; i++) {
			cin >> p;
			adj[p].pb(i);
		}
		getsz(1);
		dfs(1);
		if (vec[1].size() >= K) {
			cout << K - 1 << '\n';
			for (int i = 0; i < K; i++) cout << vec[1][i] << ' ';
			cout << '\n';
		} else {
			K -= vec[1].size();
			path.pb(1);
			dfs2(1);
			cout << path.size() - 1 << '\n';
			for (int i : path) cout << i << ' ';
			cout << '\n';
		}
	}
}