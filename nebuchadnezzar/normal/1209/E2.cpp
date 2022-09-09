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

const int P = 15;

int bit_ind[1 << P];

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> matr(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int num;
			cin >> num;
			matr[i][j] = num;
		}
	}
	vector<pii> columns;
	for (int i = 0; i < m; ++i) {
		int maxv = 0;
		for (int j = 0; j < n; ++j) {
			maxv = max(maxv, matr[j][i]);
		}
		columns.push_back({maxv, i});
	}
	sort(columns.rbegin(), columns.rend());
	columns.resize(min(n, m));

	vector<int> dp(1 << n, -INF);
	dp[0] = 0;

	vector<int> next(1 << n);
	vector<int> cost(1 << n);
	vector<int> tmp_arr(n);
	vector<int> mask_sum(1 << n);

	for (auto q : columns) {
		fill(cost.begin(), cost.end(), 0);
		for (int i = 0; i < n; ++i) {
			tmp_arr[i] = matr[i][q.ss];
		}
		for (int i = 0; i < n; ++i) {
			for (int mask = 1; mask < 1 << n; ++mask) {
				int any = mask & (-mask);
				mask_sum[mask] = mask_sum[mask ^ any] + tmp_arr[bit_ind[any]];
				cost[mask] = max(cost[mask], mask_sum[mask]);
			}
			rotate(tmp_arr.begin(), tmp_arr.begin() + 1, tmp_arr.end());
		}
		copy(dp.begin(), dp.end(), next.begin());
		for (int mask = 0; mask < 1 << n; ++mask) {
			for (int submask = mask; submask; submask = (submask - 1) & mask) {
				next[mask] = max(next[mask], dp[mask ^ submask] + cost[submask]);
			}
		}
		swap(next, dp);
	}

	cout << dp[(1 << n) - 1] << "\n";
}


int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < P; ++i) {
		bit_ind[1 << i] = i;
	}

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