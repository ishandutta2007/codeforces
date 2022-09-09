// Created by Nikolay Budin

#ifdef LOCAL
#  define _GLIBCXX_DEBUG
#else
#  define cerr __get_ce
#endif
#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())

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


void solve() {
	int n;
	cin >> n;
	vector<vector<int>> field(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < n; ++j) {
			field[i][j] = s[j] == '#';
		}
	}

	vector<vector<vector<vector<int>>>> mem(n + 1, vector<vector<vector<int>>>(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, -1))));

	function<int(int, int, int, int)> rec = [&](int x1, int y1, int x2, int y2) {
		if (x1 == x2 || y1 == y2) {
			return 0;
		}
		if (mem[x1][y1][x2][y2] != -1) {
			return mem[x1][y1][x2][y2];
		}

		auto& val = mem[x1][y1][x2][y2];

		val = max(x2 - x1, y2 - y1);

		if (x2 - x1 > y2 - y1) {
			for (int x = x1; x < x2; ++x) {
				bool ok = true;
				for (int y = y1; y < y2; ++y) {
					if (field[x][y]) {
						ok = false;
						break;
					}
				}
				if (ok) {
					val = min(val, rec(x1, y1, x, y2) + rec(x + 1, y1, x2, y2));
				}
			}
		} else {
			for (int y = y1; y < y2; ++y) {
				bool ok = true;
				for (int x = x1; x < x2; ++x) {
					if (field[x][y]) {
						ok = false;
						break;
					}
				}
				if (ok) {
					val = min(val, rec(x1, y1, x2, y) + rec(x1, y + 1, x2, y2));
				}
			}
		}

		return val;
	};

	cout << rec(0, 0, n, n) << "\n";
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