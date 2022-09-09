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

const int MAXN = 1e5 + 5;

int max_eq(vector<int>& arr) {
	sort(arr.begin(), arr.end());
	int ret = 0;
	int from = 0;
	for (int i = 0; i <= szof(arr); ++i) {
		if (i == szof(arr) || arr[i] != arr[i - 1]) {
			ret = max(ret, i - from);
			from = i;
		}
	}
	return ret;
}

void solve() {
	int n;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	const int K1 = 300;

	int ans = min(n, 2);

	vector<int> cnt;
	for (int k = -K1; k <= K1; ++k) {
		cnt.clear();
		for (int i = 0; i < n; ++i) {
			int b = arr[i] - k * i;
			cnt.push_back(b);
		}
		// for (auto p : cnt) {
		// 	ans = max(ans, p.ss);
		// }
		ans = max(ans, max_eq(cnt));
	}

	const int L1 = MAXN / K1 + 2;

	for (int i = 0; i < n; ++i) {
		cnt.clear();
		for (int j = i + 1; j < n && j < i + L1; ++j) {
			int tmp = arr[j] - arr[i];
			if (tmp % (j - i) == 0) {
				tmp /= (j - i);
				if (abs(tmp) > K1) {
					// cnt[tmp]++;
					cnt.push_back(tmp);
				}
			}
		}
		// for (auto p : cnt) {
		// 	ans = max(ans, p.ss + 1);
		// }

		ans = max(ans, max_eq(cnt) + 1);
	}

	cout << n - ans << "\n";
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