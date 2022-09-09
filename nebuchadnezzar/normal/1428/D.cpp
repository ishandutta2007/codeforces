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

	vector<pii> cells;
	int row = n - 1;
	set<int> have;
	vector<bool> incoming(n);
	for (int i = n - 1; i >= 0; --i) {
		if (arr[i] == 1) {
			have.insert(i);
		} else if (arr[i] == 2) {
			if (!szof(have)) {
				cout << "-1\n";
				return;
			}
			int prev = *have.begin();
			have.erase(have.begin());
			cells.push_back({row, i});
			cells.push_back({row, prev});
			--row;
			incoming[prev] = true;
		}
	}

	have.clear();
	for (int i = n - 1; i >= 0; --i) {
		if (arr[i] == 3) {
			if (!szof(have)) {
				cout << "-1\n";
				return;
			}
			int prev = *have.begin();
			have.erase(have.begin());
			cells.push_back({row, i});
			cells.push_back({row, prev});
			--row;
		} else if (arr[i] == 1 && !incoming[i]) {
			cells.push_back({row, i});
			--row;
		}
		if (arr[i] && !incoming[i]) {
			have.insert(i);
		}
	}

	cout << szof(cells) << "\n";
	for (auto p : cells) {
		cout << p.ff + 1 << " " << p.ss + 1 << "\n";
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