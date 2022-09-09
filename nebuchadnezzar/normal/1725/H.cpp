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
	vector<vector<int>> by_rem(3);
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		by_rem[num % 3].push_back(i);
	}

	for (int mask1 = 0; mask1 < 1 << 3; ++mask1) {
		for (int mask2 = mask1; mask2 < 1 << 3; ++mask2) {
			set<int> have;
			for (int i = 0; i < 3; ++i) {
				if (!(mask1 & (1 << i))) {
					continue;
				}
				for (int j = 0; j < 3; ++j) {
					if (mask2 & (1 << j)) {
						have.insert(((i + j) * (j + i) + i * j) % 3);
					}
				}
			}

			if (szof(have) == 3) {
				continue;
			}

			int z = 0;
			while (have.count(z)) {
				++z;
			}

			bool fail = false;
			vector<int> part1, part2;
			vector<int> comm;
			for (int i = 0; i < 3; ++i) {
				if (!szof(by_rem[i])) {
					continue;
				}
				if (!(mask1 & (1 << i)) && !(mask2 & (1 << i))) {
					fail = true;
					break;
				}

				if (!(mask1 & (1 << i))) {
					part2.insert(part2.end(), by_rem[i].begin(), by_rem[i].end());
				} else if (!(mask2 & (1 << i))) {
					part1.insert(part1.end(), by_rem[i].begin(), by_rem[i].end());
				} else {
					comm.insert(comm.end(), by_rem[i].begin(), by_rem[i].end());
				}
			}

			if (fail || szof(part1) > n / 2 || szof(part2) > n / 2) {
				continue;
			}

			while (szof(part1) < n / 2) {
				part1.push_back(comm.back());
				comm.pop_back();
			}

			while (szof(comm)) {
				part2.push_back(comm.back());
				comm.pop_back();
			}

			cout << z << "\n";
			vector<int> ans(n);
			for (int pos : part2) {
				ans[pos] = 1;
			}

			for (int num : ans) {
				cout << num;
			}
			cout << "\n";
			return;
		}
	}
	cout << "-1\n";
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