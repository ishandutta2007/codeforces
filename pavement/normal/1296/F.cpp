#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef TEST
#define getchar_unlocked _getchar_nolock
#endif
#define int long long
#define ins insert
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define pp pop
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef double db;
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, M, val[5005];
iii ed[5005];
vector<int> path;
vector<ii> adj[5005];

bool upd(int n, int v, int w, int e) {
	for (auto u : adj[n])
		if (u.first == v) {
			val[u.second] = w;
			return 1;
		} else if (u.first != e) {
			if (upd(u.first, v, w, n)) {
				val[u.second] = w;
				return 1;
			}
		}
	return 0;
}

bool pat(int n, int v, int e) {
	if (n == v) return 1;
	for (auto u : adj[n])
		if (u.first != e && pat(u.first, v, n)) {
			path.pb(u.second);
			return 1;
		}
	return 0;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1, u, v; i < N; i++) {
		cin >> u >> v;
		adj[u].eb(v, i);
		adj[v].eb(u, i);
	}
	cin >> M;
	for (int i = 1, u, v, w; i <= M; i++) {
		cin >> u >> v >> w;
		ed[i] = mt(w, u, v);
	}
	sort(ed + 1, ed + 1 + M);
	for (int i = 1, u, v, w; i <= M; i++) {
		tie(w, u, v) = ed[i];
		upd(u, v, w, -1);
	}
	for (int i = 1, u, v, w; i <= M; i++) {
		tie(w, u, v) = ed[i];
		path.clear();
		pat(u, v, -1);
		int y = 1e9;
		for (int j : path) y = min(y, val[j]);
		if (y != w) return cout << "-1\n", 0;
	}
	for (int i = 1; i < N; i++) cout << max(1ll, val[i]) << ' ';
	cout << '\n';
	
}