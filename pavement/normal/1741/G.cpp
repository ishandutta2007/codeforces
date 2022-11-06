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
using db = double;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using iiii = tuple<int, int, int, int>;
template<class key, class value = null_type, class cmp = less<key> >
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

int T, N, M, F, K, H[10005], P[15], dist[15][10005], dp[10005][1 << 6];
bool inv[10005], can[10005][1 << 6];
vector<int> adj[10005];
queue<ii> Q;

void bfs(int s, int _dist[]) {
	for (int i = 1; i <= N; i++) {
		_dist[i] = (int)1e9;
	}
	_dist[s] = 0;
	Q.emplace(0, s);
	while (!Q.empty()) {
		auto [d, v] = Q.front();
		Q.pop();
		if (d != _dist[v]) continue;
		for (auto u : adj[v])
			if (_dist[u] > d + 1) {
				_dist[u] = d + 1;
				Q.emplace(_dist[u], u);
			}
	}
}


main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int i = 1, u, v; i <= M; i++) {
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		cin >> F;
		for (int i = 1; i <= F; i++) {
			cin >> H[i];
		}
		cin >> K;
		for (int i = 0; i < K; i++) {
			cin >> P[i];
			inv[P[i]] = 1;
			P[i] = H[P[i]];
			bfs(P[i], dist[i]);
		}
		bfs(1, dist[K]);
		for (int i = 0; i < (1 << K); i++) {
			dp[0][i] = 0;
		}
		dp[0][0] = 1;
		
		for (int i = 1; i <= F; i++) {
			if (inv[i]) continue;
			for (int j = 1; j < (1 << K); j++) {
				vector<ii> vec;
				for (int k = 0; k < K; k++)
					if (j & (1 << k)) vec.eb(P[k], k);
				sort(vec.begin(), vec.end(), [](const auto &lhs, const auto &rhs) {
					return dist[K][lhs.first] < dist[K][rhs.first];
				});
				int d = dist[K][vec[0].first];
				for (int k = 0; k < (int)vec.size() - 1; k++)
					d += dist[vec[k].second][vec[k + 1].first];
				d += dist[vec.back().second][H[i]];
				can[i][j] = (d == dist[K][H[i]]);
			}
		}
		for (int i = 1; i <= F; i++) {
			for (int j = 0; j < (1 << K); j++) {
				dp[i][j] = dp[i - 1][j];
				if (inv[i]) continue;
				for (int s = j; s; s = (s - 1) & j)
					if (can[i][s]) dp[i][j] |= dp[i - 1][j ^ s];
			}
		}
		int ans = 0;
		for (int k = 0; k < (1 << K); k++)
			if (dp[F][k]) ans = max(ans, (int)__builtin_popcountll(k));
		cout << K - ans << '\n';
		
		
		for (int i = 1; i <= N; i++) {
			adj[i].clear();
			for (int j = 1; j <= F; j++) inv[j] = 0;
			for (int j = 0; j < (1 << K); j++) can[i][j] = dp[i][j] = 0;
		}
	}
}