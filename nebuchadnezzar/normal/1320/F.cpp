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

vector<tuple<int, int, int>> dirs = {
	{1, 0, 0},
	{-1, 0, 0},
	{0, 1, 0},
	{0, -1, 0},
	{0, 0, 1},
	{0, 0, -1}
};

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	auto on_field = [&](int x, int y, int z) {
		return 0 <= x && x < n && 0 <= y && y < m && 0 <= z && z < k;
	};
	vector<vector<vector<bool>>> empty(n, vector<vector<bool>>(m, vector<bool>(k)));
	vector<vector<vector<vector<pii>>>> dirs_info(n, vector<vector<vector<pii>>>(m, vector<vector<pii>>(k)));

	function<void(int, int, int, int, int)> push_dir_color = [&](int x, int y, int z, int dir, int col) {
		if (!on_field(x, y, z)) {
			cout << "-1\n";
			exit(0);
		}
		if (empty[x][y][z]) {
			auto [dx, dy, dz] = dirs[dir];
			push_dir_color(x + dx, y + dy, z + dz, dir, col);
			return;
		}
		dirs_info[x][y][z].push_back({dir, col});
		if (dirs_info[x][y][z][0].ss != col) {
			empty[x][y][z] = true;
			dirs_info[x][y][z].push_back({dir, col});
			for (auto p : dirs_info[x][y][z]) {
				push_dir_color(x, y, z, p.ff, p.ss);
			}
			dirs_info[x][y][z].clear();
		}
	};

	auto set_empty = [&](int x, int y, int z, int dir) {
		while (on_field(x, y, z)) {
			empty[x][y][z] = true;
			for (auto p : dirs_info[x][y][z]) {
				push_dir_color(x, y, z, p.ff, p.ss);
			}
			dirs_info[x][y][z].clear();
			auto [dx, dy, dz] = dirs[dir];
			x += dx; y += dy; z += dz;
		}
	};

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < k; ++j) {
			int num;
			cin >> num;
			if (num == 0) {
				set_empty(0, i, j, 0);
			} else {
				push_dir_color(0, i, j, 0, num);
			}
		}
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < k; ++j) {
			int num;
			cin >> num;
			if (num == 0) {
				set_empty(n - 1, i, j, 1);
			} else {
				push_dir_color(n - 1, i, j, 1, num);
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			int num;
			cin >> num;
			if (num == 0) {
				set_empty(i, 0, j, 2);
			} else {
				push_dir_color(i, 0, j, 2, num);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			int num;
			cin >> num;
			if (num == 0) {
				set_empty(i, m - 1, j, 3);
			} else {
				push_dir_color(i, m - 1, j, 3, num);
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int num;
			cin >> num;
			if (num == 0) {
				set_empty(i, j, 0, 4);
			} else {
				push_dir_color(i, j, 0, 4, num);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int num;
			cin >> num;
			if (num == 0) {
				set_empty(i, j, k - 1, 5);
			} else {
				push_dir_color(i, j, k - 1, 5, num);
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int q = 0; q < k; ++q) {
				if (szof(dirs_info[i][j][q])) {
					cout << dirs_info[i][j][q][0].ss << " ";
				} else {
					cout << "0 ";
				}
 			}
 			cout << "\n";
		}
		cout << "\n";
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