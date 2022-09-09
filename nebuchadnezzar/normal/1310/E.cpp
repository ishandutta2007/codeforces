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

const int MOD = 998244353;

void add(int& a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int sum(int a, int b) {
	add(a, b);
	return a;
}

void solve() {
	int n, k;
	cin >> n >> k;
	if (k == 1) {
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

		function<int(int, int)> rec = [&](int last, int left) {
			if (left == 0) {
				return 1;
			}
			if (dp[last][left] != -1) {
				return dp[last][left];
			}
			auto& val = dp[last][left];
			val = 1;
			for (int i = min(last, left); i >= 1; --i) {
				add(val, rec(i, left - i));
			}
			return val;
		};

		int ans = sum(rec(n, n), MOD - 1);

		cout << ans << "\n";
		return;
	}

	if (k == 2) {
		vector<vector<vector<int>>> dp;

		function<int(int, int, int)> rec = [&](int last, int left, int pos) {
			if (left == 0) {
				return 1;
			}
			if (szof(dp) <= pos) {
				dp.resize(pos + 1);
			}
			if (szof(dp[pos]) <= last) {
				dp[pos].resize(last + 1);
			}
			if (szof(dp[pos][last]) <= left) {
				dp[pos][last].resize(left + 1, -1);
			}
			if (dp[pos][last][left] != -1) {
				return dp[pos][last][left];
			}
			auto& val = dp[pos][last][left];
			val = 1;
			for (int i = min(last, left / (pos + 1)); i >= 1; --i) {
				add(val, rec(i, left - i * (pos + 1), pos + 1));
			}
			return val;
		};

		int ans = sum(rec(n, n, 0), MOD - 1);

		cout << ans << "\n";
		return;	
	}

	vector<int> st;

	auto calc_left = [&](vector<int> arr) {
		vector<int> next;
		for (int i = 0; i < k; ++i) {
			if (i + 2 <= k) {
				ll sum = 0;
				for (int j = 0; j < szof(arr); ++j) {
					sum += (j + 1) * arr[j];
				}
				if (sum > n) {
					return -1;
				}
			} else {
				if (accumulate(arr.begin(), arr.end(), 0ll) > n) {
					return -1;
				}
			}
			next.clear();
			for (int j = 0; j < szof(arr); ++j) {
				for (int q = 0; q < arr[j]; ++q) {
					next.push_back(j + 1);
				}
			}
			reverse(next.begin(), next.end());
			swap(next, arr);
		}
		return n - szof(next);
	};

	vector<unordered_map<ull, int>> dp(n + 1);

	function<int(int, int)> rec = [&](int last, int left) {
		if (left == 0) {
			return 1;
		}
		// if (szof(dp) <= last) {
		// 	dp.resize(last + 1);
		// }
		ull h = 0;
		for (int num : st) {
			h = h * 1234567 + num;
		}
		if (dp[last].count(h)) {
			return dp[last][h];
		}
		auto& val = dp[last][h];
		val = 1;
		for (int i = 1; i <= last; ++i) {
			st.push_back(i);
			int nleft = calc_left(st);
			if (nleft < 0) {
				st.pop_back();
				break;
			}
			add(val, rec(i, nleft));
			st.pop_back();
		}
		return val;
	};

	int ans = sum(rec(n, n), MOD - 1);

	cout << ans << "\n";
	return;	
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