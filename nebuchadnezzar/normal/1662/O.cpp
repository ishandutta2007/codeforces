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

const int A = 360, R = 21;

void solve() {
	vector<vector<int>> rad_walls(R, vector<int>(A));
	vector<vector<int>> circ_walls(R, vector<int>(A));
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		char type;
		cin >> type;
		if (type == 'C') {
			int r, a1, a2;
			cin >> r >> a1 >> a2;
			while (a1 != a2) {
				circ_walls[r][a1] = 1;
				a1 = (a1 + 1) % A;
			}
		} else {
			int r1, r2, a;
			cin >> r1 >> r2 >> a;
			for (int r = r1; r < r2; ++r) {
				rad_walls[r][a] = 1;
			}
		}
	}
	vector<vector<int>> used(R, vector<int>(A));
	function<void(int, int)> dfs = [&](int x, int y) {
		used[x][y] = true;
		if (x > 0 && !circ_walls[x][y] && !used[x - 1][y]) {
			dfs(x - 1, y);
		}
		if (x + 1 < R && !circ_walls[x + 1][y] && !used[x + 1][y]) {
			dfs(x + 1, y);
		}
		int ny = (y - 1 + A) % A;
		if (!rad_walls[x][y] && !used[x][ny]) {
			dfs(x, ny);
		}
		ny = (y + 1) % A;
		if (!rad_walls[x][ny] && !used[x][ny]) {
			dfs(x, ny);
		}
	};

	dfs(0, 0);

	if (used[R - 1][0]) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
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