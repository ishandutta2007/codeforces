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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	vector<vector<int>> b(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> b[i][j];
		}
	}

	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < m - 1; ++j) {
			if (a[i][j]) {
				for (int dx = 0; dx < 2; ++dx) {
					for (int dy = 0; dy < 2; ++dy) {
						a[i + dx][j + dy] ^= 1;
					}
				}
			}
			if (b[i][j]) {
				for (int dx = 0; dx < 2; ++dx) {
					for (int dy = 0; dy < 2; ++dy) {
						b[i + dx][j + dy] ^= 1;
					}
				}
			}
		}
	}

	if (a == b) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
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