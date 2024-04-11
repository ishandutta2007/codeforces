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


void solve() {
	int r, c, k;
	cin >> r >> c >> k;
	vector<vector<int>> field(r, vector<int>(c));
	int cnt = 0;
	for (int i = 0; i < r; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < c; ++j) {
			field[i][j] = s[j] == 'R';
			cnt += field[i][j];
		}
	}

	int x = 0, y = 0;
	vector<vector<int>> outp(r, vector<int>(c));
	for (int i = 0; i < k; ++i) {
		int cur = (cnt + i) / k;
		while (cur || (x < r && i == k - 1)) {
			outp[x][y] = i;
			cur -= field[x][y];
			if (x % 2 == 0) {
				++y;
				if (y == c) {
					y = c - 1;
					++x;
				}
			} else {
				--y;
				if (y == -1) {
					y = 0;
					++x;
				}
			}
		}
	}
	string lets = "";
	for (int i = 0; i < 26; ++i) {
		lets += (char) ('a' + i);
		lets += (char) ('A' + i);
		if (i < 10) {
			lets += (char) ('0' + i);
		}
	}
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cout << lets[outp[i][j]];
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
	cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}