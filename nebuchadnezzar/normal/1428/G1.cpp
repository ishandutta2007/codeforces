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
#define int long long

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

const int MAXN = 333333;
const int RMAXN = 999999;

void solve() {
	int k;
	cin >> k;
	--k;
	vector<int> cost;
	for (int i = 0; i < 6; ++i) {
		int num;
		cin >> num;
		cost.push_back(num);
	}

	auto calc_cost = [&](int num) {
		ll ret = 0;
		int pos = 0;
		while (num) {
			if (num % 10 % 3 == 0) {
				ret += (ll) cost[pos] * (num % 10 / 3);
			}

			num /= 10;
			++pos;
		}
		return ret;
	};

	vector<pair<int, ll>> items;

	for (int i = 0; i < 6; ++i) {
		ll weight = 1;
		for (int j = 0; j < i; ++j) {
			weight *= 10;
		}
		int amount = k * 3;
		for (int bp = 1; bp <= amount; bp *= 2) {
			if (weight * bp <= MAXN) {
				items.push_back({weight * bp, (ll) cost[i] * bp});
			}
			amount -= bp;
		}
		if (amount && weight * amount <= MAXN) {
			items.push_back({weight * amount, (ll) cost[i] * amount});
		}
	}

	vector<ll> dp(MAXN + 1, -INFL);
	dp[0] = 0;
	for (auto p : items) {
		for (int i = MAXN - p.ff; i >= 0; --i) {
			dp[i + p.ff] = max(dp[i + p.ff], dp[i] + p.ss);
		}
	}

	// for (int i = 1; i <= MAXN; ++i) {
	// 	dp[i] = max(dp[i], dp[i - 1]);
	// }

	vector<ll> act_dp(RMAXN + 1, -INFL);
	for (int i = 0; i <= MAXN; ++i) {
		act_dp[i * 3] = dp[i];
	}
	vector<ll> next(RMAXN + 1);
	for (int i = 0; i < 6; ++i) {
		fill(next.begin(), next.end(), -INFL);
		for (int d = 0; d < 10; ++d) {
			int c = d % 3 == 0 ? (ll) cost[i] * (d / 3) : 0;
			int w = d;
			for (int j = 0; j < i; ++j) {
				w *= 10;
			}
			for (int j = RMAXN - w; j >= 0; --j) {
				next[j + w] = max(next[j + w], act_dp[j] + c);
			}
		}
		swap(next, act_dp);
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int n;
		cin >> n;
		cout << act_dp[n] << "\n";
	}
}


int32_t main() {
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