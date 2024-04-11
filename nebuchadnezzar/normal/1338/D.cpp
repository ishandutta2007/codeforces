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
	vector<vector<int>> graph(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	vector<pii> dp(n);

	function<void(int, int)> dfs = [&](int v, int p) {
		dp[v].ss = 1;
		int cnt = 0;
		for (int to : graph[v]) {
			if (to != p) {
				++cnt;
				dfs(to, v);
				dp[v].ff = max(dp[v].ff, max(dp[to].ss, dp[to].ff));
				dp[v].ss = max(dp[v].ss, dp[to].ff + 1);
			}
		}
		dp[v].ff += max(0, cnt - 1);
		// cerr << v << " " << dp[v].ff << " " << dp[v].ss << endl;
	};

	dfs(0, 0);

	int ans = 0;

	function<void(int, int, pii)> dfs2 = [&](int v, int p, pii val) {
		multiset<int> vals1, vals2;
		if (v != p) {
			vals1.insert(max(val.ff, val.ss));
			vals2.insert(val.ff + 1);
		}
		for (int to : graph[v]) {
			if (to != p) {
				vals1.insert(max(dp[to].ss, dp[to].ff));
				vals2.insert(dp[to].ff + 1);
			}
		}
		ans = max(ans, max(*--vals1.end() + max(0, szof(graph[v]) - 1), *--vals2.end()));
		for (int to : graph[v]) {
			if (to != p) {
				int val1 = max(dp[to].ss, dp[to].ff);
				int val2 = dp[to].ff + 1;
				vals1.erase(vals1.find(val1));
				vals2.erase(vals2.find(val2));
				pii nval = {0, 1};
				if (szof(vals1)) {
					nval.ff = *--vals1.end() + max(szof(graph[v]) - 2, 0);
				}
				if (szof(vals2)) {
					nval.ss = *--vals2.end();
				}
				dfs2(to, v, nval);
			}
		}
	};

	dfs2(0, 0, {0, 0});

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