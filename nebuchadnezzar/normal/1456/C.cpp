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


void solve() {
	int n, k;
	cin >> n >> k;
	++k;
	vector<int> positive, negative, arr;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
		if (num >= 0) {
			positive.push_back(num);
		} else {
			negative.push_back(num);
		}
	}

	sort(positive.begin(), positive.end());
	sort(negative.begin(), negative.end());

	ll ans = 0;
	for (int i = 0; i < szof(positive); ++i) {
		ans += (ll) (i + 1) * positive[i];
	}

	if (!szof(negative)) {
		for (int num : arr) {
			ans -= num;
		}
		cout << ans << "\n";
		return;
	}

	ll tot_positive = accumulate(positive.begin(), positive.end(), 0ll);

	vector<ll> suff_negative = {0};
	{
		ll cur_sum = 0;
		for (int i = 0; i < szof(negative); ++i) {
			cur_sum += negative[szof(negative) - 1 - i];
			suff_negative.push_back(suff_negative.back() + cur_sum);
		}
	}

	ll cur_val = 0;
	ll best = -INFL * 8;
	ll left_sum = accumulate(negative.begin(), negative.end(), 0ll);
	for (int i = 0; i < szof(negative); ++i) {
		int lvl = i / k + 1;
		cur_val += (ll) lvl * negative[i];
		int left_negative = szof(negative) - 1 - i;
		left_sum -= negative[i];
		best = max(best, cur_val + left_sum * lvl + suff_negative[left_negative] + tot_positive * (lvl + left_negative) + ans);
	}

	for (int num : arr) {
		best -= num;
	}
	cout << best << "\n";
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