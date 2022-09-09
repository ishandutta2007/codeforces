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

char get_c(int num) {
	if (num < 26) {
		return 'a' + num;
	}
	return 'A' + (num - 26);
}

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> inp;
	vector where(n, vector<vector<int>>(52));
	for (int i = 0; i < n; ++i) {
		inp.push_back({});
		string s;
		cin >> s;
		for (int j = 0; j < szof(s); ++j) {
			char c = s[j];
			int val;
			if ('a' <= c && c <= 'z') {
				val = c - 'a';
			} else {
				val = c - 'A' + 26;
			}
			inp[i].push_back(val);
			where[i][val].push_back(j);
		}
	}

	vector<vector<pair<int, pii>>> dp(52, vector<pair<int, pii>>(1 << n, {-1, {-1, -1}}));
	vector<int> arr_pos(n);

	auto get_next_mask = [&](int c) {
		int ret = 0;
		for (int i = 0; i < n; ++i) {
			int d = 0;
			while (d < szof(where[i][c]) && where[i][c][d] <= arr_pos[i]) {
				++d;
			}
			if (d == szof(where[i][c])) {
				return -1;
			}
			if (szof(where[i][c]) == 2) {
				ret = ret * 2 + d;
			}
		}
		return ret;
	};

	function<int(int, int)> rec = [&](int c, int mask) {
		if (dp[c][mask].ff != -1) {
			return dp[c][mask].ff;
		}
		dp[c][mask].ff = 1;
		int tmp = mask;
		for (int i = n - 1; i >= 0; --i) {
			int d = 0;
			if (szof(where[i][c]) == 2) {
				d = tmp % 2;
				tmp /= 2;
			}
			arr_pos[i] = where[i][c][d];
		}

		vector<pii> go;
		for (int next = 0; next < 52; ++next) {
			int next_mask = get_next_mask(next);
			if (next_mask != -1) {
				go.push_back({next, next_mask});
			}
		}

		for (auto [next, next_mask] : go) {
			int tmp = 1 + rec(next, next_mask);
			if (tmp > dp[c][mask].ff) {
				dp[c][mask].ff = tmp;
				dp[c][mask].ss = {next, next_mask};
			}
		}

		return dp[c][mask].ff;
	};

	fill(arr_pos.begin(), arr_pos.end(), -1);
	vector<pii> go;
	for (int next = 0; next < 52; ++next) {
		int next_mask = get_next_mask(next);
		if (next_mask != -1) {
			go.push_back({next, next_mask});
		}
	}

	int ans = 0;
	pii mem = {-1, -1};
	for (auto [next, next_mask] : go) {
		int tmp = rec(next, next_mask);
		if (tmp > ans) {
			ans = tmp;
			mem = {next, next_mask};
		}
	}

	cout << ans << "\n";
	while (mem.ff != -1) {
		cout << get_c(mem.ff);
		mem = dp[mem.ff][mem.ss].ss;
	}
	cout << "\n";
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