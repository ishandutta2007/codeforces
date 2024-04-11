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
	vector<string> field;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		field.push_back(s);
		for (int j = 0; j < n; ++j) {
			cnt += s[j] != '.';
		}
	}

	for (int shift = 0; shift < 3; ++shift) {
		int cur_cnt = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				int type = (i + j + shift) % 3;
				if (type == 0) {
					cur_cnt += field[i][j] == 'X';
				} else if (type == 1) {
					cur_cnt += field[i][j] == 'O';
				}
			}
		}

		if (cur_cnt <= cnt / 3) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (field[i][j] != '.') {
						int type = (i + j + shift) % 3;
						if (type == 0) {
							field[i][j] = 'O';
						} else if (type == 1) {
							field[i][j] = 'X';
						}
					}
					cout << field[i][j];
				}
				cout << "\n";
			}
			return;
		}
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