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
	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	int ans = INF;
	gp_hash_table<int, vector<int>> have;
	vector<int> ones;
	for (int bit_pos = 0; bit_pos < 30; ++bit_pos) {
		int val = 0;
		have.clear();
		have[0].push_back(0);
		ones.clear();
		for (int i = 0; i < n; ++i) {
			val ^= arr[i] >> bit_pos;
			if ((arr[i] >> bit_pos) & 1) {
				ones.push_back(i);
			}
			if (szof(ones) && have.find(val ^ 1) != have.end()) {
				int before = -1;
				if (ones.back() < i) {
					before = i;
				} else if (szof(ones) >= 3) {
					before = ones[szof(ones) - 2];
				}
				auto& v = have[val ^ 1];
				auto it = v.end();
				while (it != v.begin()) {
					auto it2 = it;
					--it2;
					if (*it2 >= before) {
						it = it2;
					} else {
						break;
					}
				}
				if (it != v.begin()) {
					--it;
					ans = min(ans, i - *it + 1);

					if (ans <= 20) {
						for (int i = 0; i < n; ++i) {
							int val1 = 0;
							for (int j = i; j < n && j < i + 21; ++j) {
								val1 ^= arr[j];
								int val2 = 0;
								for (int k = j + 1; k < n && k < i + 22; ++k) {
									val2 ^= arr[k];
									if (val1 > val2) {
										ans = min(ans, k - i + 1 - 2);
									}
								}
							}
						}

						cout << ans << "\n";
						return;
					}
				}
			}
			auto& v = have[val];
			if (!szof(v) || (szof(ones) && v.back() <= ones.back())) {
				v.push_back(i + 1);
			} else {
				v.back() = i + 1;
			}
		}
	}

	if (ans == INF) {
		cout << "-1\n";
	} else {
		cout << ans - 2 << "\n";
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
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}