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
	vector<int> arr(4);
	for (int i = 0; i < 4; ++i) {
		cin >> arr[i];
	}
	for (int beg = 0; beg < 4; ++beg) {
		for (int end = beg; end < 4; ++end) {
			auto mem = arr;
			vector<int> rem(4);
			if (beg == end) {
				int any = beg == 0 ? 1 : beg - 1;
				arr[any]++;
				rem[any]++;
			} else {
				for (int i = beg + 1; i < end; ++i) {
					++arr[i];
					++rem[i];
				}
			}
			// for (int num : arr) {
			// 	cerr << num << " ";
			// }
			// cerr << endl;
			int x = arr[0] * 2;
			int y = arr[1] * 2 - x;
			int z = arr[3] * 2;
			// cerr << x << " " << y << " " << z << endl;
			if (x < 0 || y < 0 || z < 0) {
				arr = mem;
				continue;
			}
			if (arr[2] * 2 - z != y) {
				arr = mem;
				continue;
			}
			if (x && z && !y) {
				arr = mem;
				continue;
			}
			vector<int> order;
			for (int i = 0; i < x / 2; ++i) {
				order.push_back(0);
				order.push_back(1);
			}
			for (int i = 0; i < y / 2; ++i) {
				order.push_back(2);
				order.push_back(1);
			}
			if (y) {
				order.pop_back();
			}
			for (int i = 0; i < z / 2; ++i) {
				order.push_back(3);
				order.push_back(2);
			}
			if (y) {
				order.push_back(1);
			}
			int l = accumulate(rem.begin(), rem.end(), 0);
			// cerr << beg << " " << end << " " << l << endl;
			// for (int num : order) {
			// 	cerr << num << " ";
			// }
			// cerr << endl;
			// for (int num : rem) {
			// 	cerr << num << " ";
			// }
			// cerr << endl;
			bool found = false;
			for (int i = 0; i < szof(order); ++i) {
				vector<int> cur(4);
				for (int j = 0; j < l; ++j) {
					cur[order[(i + j) % szof(order)]]++;
				}
				if (cur == rem) {
					rotate(order.begin(), order.begin() + (i + l) % szof(order), order.end());
					order.resize(szof(order) - l);
					found = true;
					break;
				}
			}
			assert(found);
			cout << "YES\n";
			for (int num : order) {
				cout << num << " ";
			}
			cout << "\n";
			vector<int> cnt(4);
			for (int num : order) {
				++cnt[num];
			}
			assert(cnt == mem);
			for (int i = 0; i < szof(order) - 1; ++i) {
				assert(abs(order[i] - order[i + 1]) == 1);
			}
			return;
		}
	}
	cout << "NO\n";
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