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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> field(n, vector<int>(m));
	vector<vector<int>> pref(n + 1, vector<int>(m + 1));
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			field[i][j] = s[j] == 'X';
			pref[i + 1][j + 1] = pref[i + 1][j] + pref[i][j + 1] - pref[i][j] + field[i][j];
		}
	}

	auto get_sum = [&](int l1, int l2, int r1, int r2) {
		return pref[l2][r2] - pref[l2][r1] - pref[l1][r2] + pref[l1][r1];
	};

	vector<vector<int>> covered(n + 1, vector<int>(m + 1));
	int l = 0, r = min(n, m) + 5;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		int side = 1 + mid * 2;
		for (int i = 0; i <= n; ++i) {
			fill(covered[i].begin(), covered[i].end(), 0);
		}
		for (int i = 0; i + side <= n; ++i) {
			for (int j = 0; j + side <= m; ++j) {
				if (get_sum(i, i + side, j, j + side) == side * side) {
					covered[i][j]++;
					covered[i + side][j]--;
					covered[i][j + side]--;
					covered[i + side][j + side]++;
				}
			}
		}

		bool fl = true;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (i) {
					covered[i][j] += covered[i - 1][j];
				}
				if (j) {
					covered[i][j] += covered[i][j - 1];
				}
				if (i && j) {
					covered[i][j] -= covered[i - 1][j - 1];
				}
				if (field[i][j] && !covered[i][j]) {
					fl = false;
					break;
				}
			}
			if (!fl) {
				break;
			}
		}

		if (fl) {
			l = mid;
		} else {
			r = mid;
		}
	}

	cout << l << "\n";
	int side = 1 + l * 2;
	vector<string> ans(n, string(m, '.'));
	for (int i = 0; i + side <= n; ++i) {
		for (int j = 0; j + side <= m; ++j) {
			if (get_sum(i, i + side, j, j + side) == side * side) {
				ans[i + l][j + l] = 'X';
			}
		}
	}
	for (auto& s : ans) {
		cout << s << "\n";
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