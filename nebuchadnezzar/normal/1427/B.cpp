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
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'W') {
			arr.push_back(i);
		}
	}

	k = min(k, n - szof(arr));

	if (szof(arr) == 0) {
		cout << max(0, k * 2 - 1) << "\n";
	} else {
		vector<int> segs;
		for (int i = 0; i + 1 < szof(arr); ++i) {
			if (arr[i + 1] - arr[i] > 1) {
				segs.push_back(arr[i + 1] - arr[i] - 1);
			}
		}

		sort(segs.begin(), segs.end());
		int left = k;
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'W') {
				if (i > 0 && s[i - 1] == 'W') {
					ans += 2;
				} else {
					ans += 1;
				}
			}
		}
		for (int num : segs) {
			if (num <= left) {
				ans += num * 2 + 1;
				left -= num;
			} else {
				break;
			}
		}
		ans += left * 2;

		cout << ans << "\n";
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