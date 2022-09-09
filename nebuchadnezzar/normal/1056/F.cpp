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
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
mt19937 tw(9450189);
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }


void solve() {
	int n;
	cin >> n;
	double C, T;
	cin >> C >> T;
	vector<pii> tasks;
	for (int i = 0; i < n; ++i) {
		int a, p;
		cin >> a >> p;
		tasks.push_back({a, p});
	}
	sort(tasks.begin(), tasks.end());
	reverse(tasks.begin(), tasks.end());

	vector<vector<double>> dp(n + 1, vector<double>(n * 10 + 1, 1e100));
	vector<vector<bool>> can(n + 1, vector<bool>(n * 10 + 1));
	dp[0][0] = 0;
	can[0][0] = true;

	vector<double> pows;
	for (int i = 0; i <= n; ++i) {
		pows.push_back(pow(0.9, i));
	}

	int s = 0;
	int cnt = 0;
	for (pii p : tasks) {
		for (int i = cnt; i >= 0; --i) {
			for (int j = 0; j <= s; ++j) {
				if (!can[i][j]) {
					continue;
				}
				double val = dp[i][j] + 10 + p.ff / pows[i + 1];
				if (val < dp[i + 1][j + p.ss]) {
					dp[i + 1][j + p.ss] = val;
					can[i + 1][j + p.ss] = true;
				}
			}
		}
		s += p.ss;
		++cnt;
	}

	int ans = 0;

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= i * 10; ++j) {
			if (!can[i][j]) {
				continue;
			}
			
			double t = dp[i][j];
			double sert = i * 10;
			double c1 = t - sert;
			/*
			// double d = (4 * C * C) - 4 * C * C * (1 - C * c1);
			double x = 0;
			// if (d < 0) {
			// 	x = 0;
			// } else {
				// assert(d >= 0);
				// x = (-(2 * C) + sqrt(d)) / (2 * C * C);
				x = (sqrt(C * c1) - 1) / C;
				x = max(x, 0.0);
			// }
			// assert(x >= 0);
			double best = 1 / (1 + x * C) * c1 + x;
			if (best + sert <= T || t <= T) {
				// cerr << dp[i][j] << " " << best << endl;
				// cerr << x << " " << best + sert << endl;
				// cerr << 1 / (1 + 4 * C) * c1 + 4 + sert << endl;
				ans = max(ans, j);
			}
			*/
			double best = c1;
			double l = 0, r = T;
			for (int q = 0; q < 130; ++q) {
				double mid1 = (l * 2 + r) / 3, mid2 = (l + r * 2) / 3;
				double val1 = 1 / (1 + mid1 * C) * c1 + mid1;
				double val2 = 1 / (1 + mid2 * C) * c1 + mid2;
				best = min(best, min(val1, val2));
				if (val1 < val2) {
					r = mid2;
				} else {
					l = mid1;
				}
			}

			// cerr << i << " " << j << " " << best + sert << endl;

			if (best + sert <= T) {
				ans = max(ans, j);
			}
		}
	}

	cout << ans << "\n";
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