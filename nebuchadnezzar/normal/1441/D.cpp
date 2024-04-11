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
	vector<int> color(n);
	for (int& num : color) {
		cin >> num;
	}
	vector<vector<int>> graph(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int ans = INF;

	int cnt1 = 0, cnt2 = 0;
	{
		vector<bool> used(n);
		function<void(int)> dfs = [&](int v) {
			used[v] = true;
			for (int to : graph[v]) {
				if (color[to] == color[v] && !used[to]) {
					dfs(to);
				}
			}
		};
		for (int i = 0; i < n; ++i) {
			if (!used[i]) {
				dfs(i);
				if (color[i] == 1) {
					++cnt1;
				}
				if (color[i] == 2) {
					++cnt2;
				}
				
			}
		}
	}

	ans = min(ans, 1 + cnt2);
	ans = min(ans, 1 + cnt1);

	for (int qwe = 0; qwe < 2; ++qwe) {
		vector<int> sz(n);
		const int MAX_SZ = 100;
		function<vector<int>(int, int)> dfs = [&](int v, int p) {
			vector<int> dp;
			if (color[v] == 1 || color[v] == 0) {
				dp = {1};
			} else {
				dp = {INF, 2};
			}
			sz[v] = 1;
			for (int to : graph[v]) {
				if (to != p) {
					vector<int> tmp = dfs(to, v);
					sz[v] += sz[to];
					vector<int> next_dp(min(sz[v] + 2, MAX_SZ), INF);
					for (int i = 0; i < szof(next_dp); ++i) {
						int dp_val = INF;
						if (i < szof(dp)) {
							dp_val = dp[i];
						} else {
							if ((color[v] == 1 || color[v] == 0) && i % 2 == 0) {
								dp_val = i + 1;
							}
							if ((color[v] == 2 || color[v] == 0) && i % 2 == 1) {
								dp_val = i + 1;
							}
						}
						for (int j = 0; j < szof(tmp); ++j) {
							next_dp[i] = min(next_dp[i], dp_val + tmp[j] - min(i, j) - 1);
						}
					}
					swap(next_dp, dp);
				}
			}
			return dp;
		};

		auto dp = dfs(0, 0);
		ans = min(ans, *min_element(dp.begin(), dp.end()));

		for (int& num : color) {
			if (num == 1) {
				num = 2;
			} else if (num == 2) {
				num = 1;
			}
		}
	}

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
	cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}