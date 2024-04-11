// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ff first
#define ss second
#define szof(x) ((int)x.size())
#ifndef LOCAL
#  define cerr __get_ce
#endif

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned long long ull;

using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }


void solve() {
	int n;
	cin >> n;
	vector<vector<pii>> graph(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		--a; --b;
		graph[a].push_back({b, w});
		graph[b].push_back({a, w});
	}

	vector<vector<ll>> dp(n, vector<ll>(3));
	function<void(int, int)> dfs1 = [&](int v, int p) {
		if (v) {
			for (int i = 0; i < szof(graph[v]); ++i) {
				if (graph[v][i].ff == p) {
					graph[v].erase(graph[v].begin() + i);
					break;
				}
			}
		}
		for (auto to : graph[v]) {
			if (to.ff != p) {
				dfs1(to.ff, v);
				ll cur_loop = (ll) to.ss * 2 + dp[to.ff][0];
				ll cur_path = to.ss + dp[to.ff][1];
				dp[v][2] = min({dp[v][2] + cur_loop, dp[v][1] + cur_path, dp[v][0] + (ll) to.ss * 2 + dp[to.ff][2]});
				dp[v][1] = min(dp[v][1] + cur_loop, dp[v][0] + cur_path);
				dp[v][0] += cur_loop;
			}
		}

		// for (int i = 0; i < 3; ++i) {
		// 	cerr << dp[v][i] << " ";
		// }
		// cerr << endl;
	};

	dfs1(0, -1);

	ll ans = dp[0][2];
	function<void(int, int, ll, ll, ll)> dfs2 = [&](int v, int len, ll pdp0, ll pdp1, ll pdp2) {
		// cerr << v << " " << pdp0 << " " << pdp1 << " " << pdp2 << endl;
		if (v != 0) {
			ans = min(ans, dp[v][2] + pdp2);
		}
		vector<vector<ll>> suff_dp(1, vector<ll>(5));
		if (v != 0) {
			suff_dp[0][0] = pdp0 + (ll) len * 2;
			suff_dp[0][1] = pdp1 + len;
			suff_dp[0][2] = min(pdp1 + len, pdp2 + len * 2);
			suff_dp[0][3] = suff_dp[0][2];
			suff_dp[0][4] = suff_dp[0][2];
		}
		for (int i = szof(graph[v]) - 1; i >= 0; --i) {
			suff_dp.push_back(vector<ll>(5));
			auto to = graph[v][i];
			int c = szof(suff_dp) - 1;
			ll cur_loop = (ll) to.ss * 2 + dp[to.ff][0];
			ll cur_path = to.ss + dp[to.ff][1];
			for (int j = 0; j < 5; ++j) {
				suff_dp[c][j] = suff_dp[c - 1][j] + cur_loop;
				if (j) {
					suff_dp[c][j] = min(suff_dp[c][j], suff_dp[c - 1][j - 1] + cur_path);
				}
				if (j >= 2) {
					suff_dp[c][j] = min(suff_dp[c][j], suff_dp[c - 1][j - 2] + to.ss * 2 + dp[to.ff][2]);
				}
			}
		}
		assert(dp[0][2] == suff_dp.back()[2]);

		ans = min(ans, suff_dp.back()[4]);

		vector<ll> cur_dp(3);
		for (int i = 0; i < szof(graph[v]); ++i) {
			auto to = graph[v][i];

			vector<ll> to_dp(3, INFL);
			for (int x = 0; x < 3; ++x) {
				for (int y = 0; x + y < 3; ++y) {
					to_dp[x + y] = min(to_dp[x + y], cur_dp[x] + suff_dp[szof(graph[v]) - 1 - i][y]);
				}
			}

			dfs2(to.ff, to.ss, to_dp[0], to_dp[1], to_dp[2]);

			ll cur_loop = (ll) to.ss * 2 + dp[to.ff][0];
			ll cur_path = to.ss + dp[to.ff][1];
			cur_dp[2] = min({cur_dp[2] + cur_loop, cur_dp[1] + cur_path, cur_dp[0] + to.ss * 2 + dp[to.ff][2]});
			cur_dp[1] = min(cur_dp[1] + cur_loop, cur_dp[0] + cur_path);
			cur_dp[0] = cur_dp[0] + cur_loop;
		}
	};

	dfs2(0, -1, 0, 0, 0);

	cout << ans << "\n";
}


int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_count = 1;
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}