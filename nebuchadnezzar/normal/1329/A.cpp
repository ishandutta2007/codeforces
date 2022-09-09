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
	int n, m;
	cin >> n >> m;
	ll sum = 0;
	vector<int> arr;
	for (int i = 0; i < m; ++i) {
		int l;
		cin >> l;
		arr.push_back(l);
		sum += l;
	}

	if (sum < n) {
		cout << "-1\n";
		return;
	}

	int to = 0;
	vector<int> ans(m);
	for (int i = m - 1; i >= 0; --i) {
		int pos = max(0, to - arr[i] + 1);
		ans[i] = pos;
		to = max(to, pos + arr[i]);
	}

	if (to > n) {
		cout << "-1\n";
		return;
	}
	int shift = n - to;
	for (int i = m - 2; i >= 0; --i) {
		ans[i] = min(ans[i] + shift, ans[i + 1] + arr[i + 1]);
	}

	if (ans[0] + arr[0] < n) {
		cout << "-1\n";
		return;
	}

	for (int pos : ans) {
		cout << pos + 1 << " ";
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
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}