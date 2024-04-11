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
	vector<vector<int>> matr(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> matr[i][j];
			--matr[i][j];
		}
	}
	string s;
	cin >> s;
	vector<int> order = {0, 1, 2}; // x, y, p
	vector<int> change = {0, 0, 0}; // x, y, p
	for (char c : s) {
		if (c == 'R') {
			change[order[1]]++;
		} else if (c == 'L') {
			change[order[1]]--;
		} else if (c == 'D') {
			change[order[0]]++;
		} else if (c == 'U') {
			change[order[0]]--;
		} else if (c == 'I') {
			swap(order[1], order[2]);
		} else if (c == 'C') {
			swap(order[0], order[2]);
		} else {
			assert(false);
		}
	}

	vector<vector<int>> outp(n, vector<int>(n));
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < n; ++y) {
			int p = matr[x][y];
			vector<int> tmp = {((x + change[0]) % n + n) % n, ((y + change[1]) % n + n) % n, ((p + change[2]) % n + n) % n};
			int nx = tmp[order[0]];
			int ny = tmp[order[1]];
			int np = tmp[order[2]];
			outp[nx][ny] = np;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << outp[i][j] + 1 << " ";
		}
		cout << "\n";
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
	cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}