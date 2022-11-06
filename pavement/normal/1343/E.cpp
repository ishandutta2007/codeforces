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
#define g4(a) get<4>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using db = double;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using iiii = tuple<int, int, int, int>;
template<class key, class value = null_type, class cmp = less<key> >
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

int TC, n, e, a, b, c, ans = LLONG_MAX, p[200005], dist[3][200005];
vector<int> adj[200005];
queue<ii> Q;

void bfs(int x, int t) {
	Q.emplace(0, x);
	for (int i = 1; i <= n; i++)
		dist[t][i] = (int)1e16;
	dist[t][x] = 0;
	while (!Q.empty()) {
		auto [d, v] = Q.front();
		Q.pop();
		if (d != dist[t][v]) continue;
		for (auto u : adj[v])
			if (dist[t][u] > d + 1) {
				dist[t][u] = d + 1;
				Q.emplace(dist[t][u], u);
			}
	}
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> TC;
	while (TC--) {
		cin >> n >> e >> a >> b >> c;
		for (int i = 1; i <= e; i++) cin >> p[i];
		sort(p + 1, p + 1 + e);
		partial_sum(p + 1, p + 1 + e, p + 1);
		for (int u, v, i = 1; i <= e; i++) {
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		bfs(a, 0);
		bfs(b, 1);
		bfs(c, 2);
		for (int x = 1; x <= n; x++) {
			int ed = dist[0][x] + dist[1][x] + dist[2][x];
			if (ed <= e) ans = min(ans, p[ed] + p[dist[1][x]]);
		}
		cout << ans << '\n';
		ans = LLONG_MAX;
		for (int i = 1; i <= n; i++) {
			p[i] = 0;
			for (int j = 0; j < 3; j++)
				dist[j][i] = 0;
			adj[i].clear();
		}
	}
}