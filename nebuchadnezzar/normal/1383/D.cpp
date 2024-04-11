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

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> field(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> field[i][j];
			--field[i][j];
		}
	}

	set<int> rows_max, columns_max;
	for (int i = 0; i < n; ++i) {
		rows_max.insert(*max_element(field[i].begin(), field[i].end()));
	}
	for (int i = 0; i < m; ++i) {
		int val = -1;
		for (int j = 0; j < n; ++j) {
			val = max(val, field[j][i]);
		}
		columns_max.insert(val);
	}

	set<int> common;
	for (int num : rows_max) {
		if (columns_max.count(num)) {
			common.insert(num);
		}
	}
	vector<vector<int>> outp(n, vector<int>(m, -1));
	int cnt = 0;
	for (int num : common) {
		outp[cnt][cnt] = num;
		++cnt;
		columns_max.erase(num);
		rows_max.erase(num);
	}
	--cnt;
	int cnt2 = n - 1;
	for (int num : rows_max) {
		outp[cnt2][cnt] = num;
		--cnt2;
	}
	cnt2 = m - 1;
	for (int num : columns_max) {
		outp[cnt][cnt2] = num;
		--cnt2;
	}

	vector<bool> used(n * m);
	set<pair<int, pii>> have;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (outp[i][j] != -1) {
				used[outp[i][j]] = true;
				continue;
			}
			int bound = INF;
			int cnt = 0;
			for (int d = 0; d < 4; ++d) {
				int nx = i + dx[d];
				int ny = j + dy[d];
				if (0 <= nx && nx < n && 0 <= ny && ny < m && outp[nx][ny] != -1) {
					++cnt;
					bound = min(bound, outp[nx][ny] - 1);
				}
			}
			if (cnt >= 2) {
				assert(cnt == 2);
				have.insert({bound, {i, j}});
			}
		}
	}

	for (int i = n * m - 1; i >= 0; --i) {
		if (used[i]) {
			continue;
		}
		if (!szof(have) || (--have.end())->ff < i) {
			assert(false);
		}
		auto [x, y] = (--have.end())->ss;
		have.erase(--have.end());
		outp[x][y] = i;
		for (int d0 = 0; d0 < 4; ++d0) {
			int cx = x + dx[d0];
			int cy = y + dy[d0];
			if (cx < 0 || cx >= n || cy < 0 || cy >= m || outp[cx][cy] != -1) {
				continue;
			}
			int bound = INF;
			int cnt = 0;
			for (int d = 0; d < 4; ++d) {
				int nx = cx + dx[d];
				int ny = cy + dy[d];
				if (0 <= nx && nx < n && 0 <= ny && ny < m && outp[nx][ny] != -1) {
					++cnt;
					bound = min(bound, outp[nx][ny] - 1);
				}
			}
			if (cnt >= 2) {
				assert(cnt == 2);
				have.insert({bound, {cx, cy}});
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << outp[i][j] + 1 << " ";
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