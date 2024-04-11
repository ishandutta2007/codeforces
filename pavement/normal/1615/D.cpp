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

int T, N, M, dist[200005], dist2[200005];
vector<iii> edg, cond, adj[200005];
deque<ii> Q;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			dist[i] = 0;
			adj[i].clear();
		}
		edg.clear();
		cond.clear();
		for (int i = 1, u, v, w; i < N; i++) {
			cin >> u >> v >> w;
			if (w != -1) {
				adj[u].eb(v, 0, w);
				adj[v].eb(u, 0, w);
			}
			edg.eb(u, v, w);
		}
		for (int i = 1, a, b, p; i <= M; i++) {
			cin >> a >> b >> p;
			adj[a].eb(b, 1, p);
			adj[b].eb(a, 1, p);
			cond.eb(a, b, p);
		}
		for (int i = 1; i <= N; i++) dist2[i] = 1e9;
		for (int i = 1; i <= N; i++) {
			Q.eb(0, i);
			dist2[i] = 0;
			while (!Q.empty()) {
				auto [d, n] = Q.front();
				Q.pop_front();
				if (d != dist2[n]) continue;
				for (auto u : adj[n])
					if (d + g1(u) < dist2[g0(u)]) {
						dist[g0(u)] = (dist[n] ^ g2(u));
						dist2[g0(u)] = d + g1(u);
						if (g1(u)) Q.eb(dist2[g0(u)], g0(u));
						else Q.emplace_front(dist2[g0(u)], g0(u));
					}
			}
		}
		bool inv = 0;
		for (auto [u, v, w] : edg)
			if (w != -1 && (dist[u] ^ dist[v]) != w) inv = 1;
		for (auto [u, v, w] : cond)
			if ((__builtin_popcountll(dist[u] ^ dist[v]) & 1) != w) inv = 1;
		if (inv) cout << "NO\n";
		else {
			cout << "YES\n";
			for (auto [u, v, w] : edg) cout << u << ' ' << v << ' ' << (dist[u] ^ dist[v]) << '\n';
		}
	}
}