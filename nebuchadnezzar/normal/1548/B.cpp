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
	vector<ll> arr;
	for (int i = 0; i < n; ++i) {
		ll num;
		cin >> num;
		arr.push_back(num);
	}

	vector<ll> diff;
	for (int i = 0; i < n - 1; ++i) {
		diff.push_back(abs(arr[i + 1] - arr[i]));
	}

	int bp = 1;
	while (1 << bp <= n - 1) {
		++bp;
	}

	vector<vector<ll>> sparse = {diff};
	for (int i = 1; i < bp; ++i) {
		sparse.push_back(vector<ll>(n - (1 << i)));
		for (int j = 0; j + (1 << i) <= n - 1; ++j) {
			sparse[i][j] = __gcd(sparse[i - 1][j], sparse[i - 1][j + (1 << (i - 1))]);
		}
	}

	vector<int> maxp(n + 1);
	for (int i = 2; i <= n; ++i) {
		maxp[i] = maxp[i / 2] + 1;
	}

	auto get_gcd = [&](int l, int r) {
		int p = maxp[r - l];
		return __gcd(sparse[p][l], sparse[p][r - (1 << p)]);
	};

	int ans = 0;

	int r = 0;
	for (int i = 0; i < n - 1; ++i) {
		r = max(r, i);
		while (r < n - 1 && get_gcd(i, r + 1) != 1) {
			++r;
		}
		ans = max(ans, r - i);
	}

	cout << ans + 1 << "\n";
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