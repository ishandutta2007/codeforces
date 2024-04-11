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

ll sqr(ll num) {
	return num * num;
}

void solve() {
	vector<vector<int>> arr;
	for (int i = 0; i < 3; ++i) {
		int n;
		cin >> n;
		arr.push_back(vector<int>(n));
	}
	for (int i = 0; i < 3; ++i) {
		for (int& num : arr[i]) {
			cin >> num;
		}
		sort(arr[i].begin(), arr[i].end());
	}

	ll ans = INFL * 6;

	vector<int> order(3);
	iota(order.begin(), order.end(), 0);

	do {
		int cnt1 = 0, cnt2 = -1;
		for (int j = 0; j < szof(arr[order[0]]); ++j) {
			while (cnt1 < szof(arr[order[1]]) && arr[order[1]][cnt1] < arr[order[0]][j]) {
				++cnt1;
			}
			while (cnt2 + 1 < szof(arr[order[2]]) && arr[order[2]][cnt2 + 1] <= arr[order[0]][j]) {
				++cnt2;
			}
			if (cnt1 < szof(arr[order[1]]) && cnt2 > -1) {
				ll cur = sqr(arr[order[0]][j] - arr[order[1]][cnt1]) + sqr(arr[order[0]][j] - arr[order[2]][cnt2]) + sqr(arr[order[1]][cnt1] - arr[order[2]][cnt2]);
				ans = min(ans, cur);
			}
		}
	} while (next_permutation(order.begin(), order.end()));
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