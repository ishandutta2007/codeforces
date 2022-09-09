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

const int MOD = 998244353;

void add(int& a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int mult(int a, int b) {
	return (ll) a * b % MOD;
}

int mpow(int a, int b) {
	int ret = 1;
	while (b) {
		if (b & 1) {
			ret = mult(ret, a);
		}
		a = mult(a, a);
		b >>= 1;
	}
	return ret;
}

int inv(int num) {
	return mpow(num, MOD - 2);
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> coef(n);
	for (int i = 0; i < n; ++i) {
		cin >> coef[i];
		coef[i] = coef[i] * 2 - 1;
	}

	vector<int> w(n);

	int sum_pos = 0, sum_neg = 0;

	for (int i = 0; i < n; ++i) {
		cin >> w[i];
		if (coef[i] < 0) {
			sum_neg += w[i];
		} else {
			sum_pos += w[i];
		}
	}

	for (int i = 0; i < n; ++i) {
		vector<vector<vector<int>>> d(m + 1, vector<vector<int>>(m + 1, vector<int>(m + 1)));

		d[0][0][0] = 1;
		for (int j = 0; j < m; ++j) {
			for (int x = 0; x <= j; ++x) {
				for (int y = 0; y <= j; ++y) {
					if (d[j][x][y] == 0) {
						continue;
					}
					int inv_cur_sum = inv(sum_pos + y + sum_neg - (j - y));
					// cerr << j << " " << sum_pos + y + sum_neg - (j - y) << " " << d[j][x][y] << endl;
					if (w[i] + (x + 1) * coef[i] >= 0) {
						int prob = mult(w[i] + x * coef[i], inv_cur_sum);
						add(d[j + 1][x + 1][y + (coef[i] == 1)], mult(d[j][x][y], prob));
					}
					int p = mult(sum_pos + y - (coef[i] == 1 ? (w[i] + x) : 0), inv_cur_sum);
					add(d[j + 1][x][y + 1], mult(d[j][x][y], p));

					p = mult(sum_neg - (j - y) - (coef[i] == -1 ? (w[i] - x) : 0), inv_cur_sum);
					add(d[j + 1][x][y], mult(d[j][x][y], p));
				}
			}
		}
		int ans = 0;
		for (int x = 0; x <= m; ++x) {
			for (int y = 0; y <= m; ++y) {
				// cerr << d[m][x][y] << " ";
				add(ans, mult(d[m][x][y], w[i] + x * coef[i]));
			}
			// cerr << endl;
		}

		cout << ans << "\n";
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