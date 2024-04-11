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
	int n, d, m;
	cin >> n >> d >> m;
	vector<int> arr1, arr2;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		if (num > m) {
			arr2.push_back(num);
		} else {
			arr1.push_back(num);
		}
	}

	sort(arr1.begin(), arr1.end());
	reverse(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());
	reverse(arr2.begin(), arr2.end());
	vector<ll> pref1 = {0}, pref2 = {0};
	for (int num : arr1) {
		pref1.push_back(pref1.back() + num);
	}

	for (int num : arr2) {
		pref2.push_back(pref2.back() + num);
	}

	ll ans = 0;
	if (szof(arr1) >= n) {
		ans = max(ans, pref1[n]);
	}

	for (int i = 1; i <= n && i <= szof(arr2); ++i) {
		int left = n - 1 - (i - 1) * (d + 1);
		if (left < 0) {
			break;
		}
		ans = max(ans, pref1[min(left, szof(arr1))] + pref2[i]);
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
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}