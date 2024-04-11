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

int get_med(auto itl, auto itr) {
	static int arr[3];
	int len = 0;
	while (itl != itr) {
		arr[len] = *itl;
		++itl;
		++len;
	}
	sort(arr, arr + len);
	return arr[(len - 1) / 2];
}

int n, k;

bool is_better(int new_val, int old_val) {
	if (old_val < k) {
		return new_val >= k;
	}
	if (old_val > k) {
		return new_val == k;
	}
	return false;
}

void solve() {
	cin >> n >> k;
	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	function<void(int, int, int)> set_val = [&](int l, int r, int val) {
		// cerr << "set val " << l << " " << r << " " << val << endl;
		fill(arr.begin() + l, arr.begin() + r, val);
		for (int len = 2; len <= 3; ++len) {
			for (int st = max(0, l - len + 1); st + len <= n && st < r; ++st) {
				int new_val = get_med(arr.begin() + st, arr.begin() + st + len);
				bool fl_better = false, fl_worse = false;
				for (int i = st; i < st + len; ++i) {
					fl_better |= is_better(new_val, arr[i]);
					fl_worse |= is_better(arr[i], new_val);
				}
				if (!fl_worse && fl_better) {
					set_val(st, st + len, new_val);
				}
			}
		}
	};

	for (int len = 2; len <= 3; ++len) {
		for (int st = 0; st + len <= n; ++st) {
			int new_val = get_med(arr.begin() + st, arr.begin() + st + len);
			bool fl_better = false, fl_worse = false;
			for (int i = st; i < st + len; ++i) {
				fl_better |= is_better(new_val, arr[i]);
				fl_worse |= is_better(arr[i], new_val);
			}
			if (!fl_worse && fl_better) {
				set_val(st, st + len, new_val);
			}
		}
	}

	if (*min_element(arr.begin(), arr.end()) != k || *max_element(arr.begin(), arr.end()) != k) {
		cout << "no\n";
	} else {
		cout << "yes\n";
	}
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