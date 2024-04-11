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
	string s;
	cin >> s;
	vector<int> arr;
	vector<int> pos_arr;
	for (int i = 0; i < 10; ++i) {
		arr.push_back(s[i] - '0');
		if (s[i] == '?') {
			pos_arr.push_back(i);
		}
	}

	int ans = 10;

	for (int mask = 0; mask < 1 << szof(pos_arr); ++mask) {
		for (int i = 0; i < szof(pos_arr); ++i) {
			arr[pos_arr[i]] = (mask >> i) & 1;
		}
		vector<int> cnt(2), left(2, 5);
		int res = 10;
		for (int i = 0; i < 10; ++i) {
			cnt[i % 2] += arr[i];
			--left[i % 2];
			if (cnt[0] > cnt[1] + left[1] || cnt[1] > cnt[0] + left[0]) {
				res = i + 1;
				break;
			}
		}
		ans = min(ans, res);
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