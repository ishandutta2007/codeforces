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

vector<vector<int>> qwe = {
{8, 9, 1, 13},
{3, 12, 7, 5},
{0, 2, 4, 11},
{6, 10, 15, 14}};

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> matr(n, vector<int>(n));
	int shift = 0;
	for (int i = 0; i < n; i += 4) {
		for (int j = 0; j < n; j += 4) {
			for (int x = 0; x < 4; ++x) {
				for (int y = 0; y < 4; ++y) {
					matr[i + x][j + y] = qwe[x][y] + shift;
				}
			}
			shift += 16;
		}
	}

	set<int> all;

	for (int i = 0; i < n; ++i) {
		int res = 0;
		for (int j = 0; j < n; ++j) {
			res ^= matr[i][j];
		}
		all.insert(res);
		res = 0;
		for (int j = 0; j < n; ++j) {
			res ^= matr[j][i];
		}
		all.insert(res);
	}

	assert(szof(all) == 1);

	for (auto v : matr) {
		for (int num : v) {
			cout << num << " ";
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