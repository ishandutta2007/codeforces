// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
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
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }

int dx[5] = {1, 0, -1, 0, 1};
int dy[5] = {0, -1, 0, 1, -1};
int cost[5] = {1, 1, 0, 0, 1};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> field(n, vector<char>(m));
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			field[i][j] = s[j];
		}
	}

	vector<vector<int>> dist(n, vector<int>(m, INF));
	set<pair<int, pii>> st;
	for (int i = 1; i < m; ++i) {
		dist[0][i] = field[0][i] == '.';
		st.insert({dist[0][i], {0, i}});
	}
	for (int i = 0; i < n - 1; ++i) {
		dist[i][m - 1] = field[i][m - 1] == '.';
		st.insert({dist[i][m - 1], {i, m - 1}});
	}
	while (szof(st)) {
		auto p = *st.begin();
		// cerr << p.ff << " " << p.ss.ff << " " << p.ss.ss << endl;
		st.erase(st.begin());
		if (p.ss.ff == n - 1 || p.ss.ss == 0) {
			cout << p.ff << "\n";
			return;
		}
		for (int d = 0; d < 5; ++d) {
			int nx = p.ss.ff + dx[d];
			int ny = p.ss.ss + dy[d];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && !(nx == 0 && ny == 0) && !(nx == n - 1 && ny == m - 1)) {
				// cerr << nx << " " << ny << endl;
				int val = p.ff + cost[d] * (field[nx][ny] == '.');
				if (dist[nx][ny] > val) {
					st.erase({dist[nx][ny], {nx, ny}});
					dist[nx][ny] = val;
					st.insert({dist[nx][ny], {nx, ny}});
				}
			}
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
	// while (!cin.eof()) {
		solve();
	// }
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}