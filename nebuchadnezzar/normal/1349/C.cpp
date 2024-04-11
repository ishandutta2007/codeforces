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

const int MAXN = 1005;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void solve() {
	int n, m, t;
	cin >> n >> m >> t;
	vector<vector<int>> field(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			field[i][j] = s[j] - '0';
		}
	}

	vector<vector<bool>> bad(n, vector<bool>(m, true));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int d = 0; d < 4; ++d) {
				int nx = i + dx[d];
				int ny = j + dy[d];
				if (0 <= nx && nx < n && 0 <= ny && ny < m && field[nx][ny] == field[i][j]) {
					bad[i][j] = false;
					break;
				}
			}
		}
	}

	queue<pii> qu;
	vector<vector<ll>> dist(n, vector<ll>(m, INFL));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!bad[i][j]) {
				dist[i][j] = 0;
				qu.push({i, j});
			}
		}
	}

	while (szof(qu)) {
		auto [x, y] = qu.front();
		qu.pop();
		for (int d = 0; d < 4; ++d) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && dist[nx][ny] > dist[x][y] + 1) {
				dist[nx][ny] = dist[x][y] + 1;
				qu.push({nx, ny});
			}
		}
	}

	for (int i = 0; i < t; ++i) {
		int x, y;
		ll p;
		cin >> x >> y >> p;
		--x; --y;
		if (dist[x][y] >= p) {
			cout << field[x][y] << "\n";
		} else {
			cout << (field[x][y] ^ ((p - dist[x][y]) & 1)) << "\n";
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
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}