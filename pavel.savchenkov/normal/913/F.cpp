#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>
#include <complex>
#include <bitset>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;

#define ws ws_____________________
#define y1 y1_____________________
#define y0 y0_____________________
#define left left_________________
#define right right_______________
#define next next_________________
#define prev prev_________________
#define hash hash_________________

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define FILE_NAME "a"

int N;
int a, b;

bool read() {
	if  (scanf("%d", &N) < 1) {
		return 0;
	}
	scanf("%d%d", &a, &b);
	return 1;
}

const int MAXN = 2e3 + 10;

namespace double_solver {
	double ans[MAXN];
	double dp[MAXN];
	double p_full[MAXN];
	double f[MAXN][MAXN];
	double pow_p[MAXN];
	double pow_q[MAXN];


	double solve() {
		const double p = a * 1.0 / b;
		const double q = 1 - p;
		pow_p[0] = pow_q[0] = 1;
		for (int i = 1; i < MAXN; ++i) {
			pow_p[i] = pow_p[i - 1] * p;
			pow_q[i] = pow_q[i - 1] * q;
		}

		memset (f, 0, sizeof f);
		for (int n = 0; n <= N; ++n) {
			for (int k = 0; k <= n; ++k) {
				if  (k == 0) {
					f[n][k] = 1;
					continue;
				}

				// first in set
				f[n][k] += f[n - 1][k - 1] * pow_p[n - k];

				// first not in set
				if  (n > k) {
					f[n][k] += f[n - 1][k] * pow_q[k];
				}
			}
		}

		p_full[0] = 0;
		for (int n = 1; n <= N; ++n) {
			double bad = 0;
			for (int k = 1; k < n; ++k) {
				bad += f[n][k] * p_full[k];
			}
			p_full[n] = 1 - bad;

			eprintf("p_full[%d] = %.10f\n", n, p_full[n]);
		}

		memset (dp, 0, sizeof dp);
		memset (ans, 0, sizeof ans);
		ans[0] = 0;
		dp[0] = 0;
		for (int n = 2; n <= N; ++n) {
			dp[n] = 0;
			for (int k = 1; k < n; ++k) {
				dp[n] += f[n][k] * p_full[k] * (ans[k] + dp[n - k]);
			}

			double pairs = n * (n - 1) / 2;
			ans[n] = (dp[n] + pairs) / (1 - p_full[n]);

			dp[n] += f[n][n] * p_full[n] * ans[n];

			eprintf("ans[%d] = %.10f\n", n, ans[n]);
		}

		return ans[N];
	}
};

const int MOD = 998244353;

void add(int& x, int y) {
	((x += y) >= MOD) && (x -= MOD);
}

void sub(int& x, int y) {
	add(x, -y + MOD);
}

int mul(int x, int y) {
	return x * 1ll * y % MOD;
}

int mpow(int a, int p) {
	int res = 1;
	for (; p > 0; p >>= 1, a = mul(a, a)) {
		if  (p & 1) {
			res = mul(res, a);
		}
	}
	return res;
}

int inv(int x) {
	int y = mpow(x, MOD - 2);
	assert(mul(x, y) == 1);
	return y;
}

namespace int_solver {
	int ans[MAXN];
	int dp[MAXN];
	int p_full[MAXN];
	int f[MAXN][MAXN];
	int pow_p[MAXN];
	int pow_q[MAXN];


	double solve() {
		const int p = mul(a, inv(b));
		const int q = (1 - p + MOD) % MOD;
		pow_p[0] = pow_q[0] = 1;
		for (int i = 1; i < MAXN; ++i) {
			pow_p[i] = mul(pow_p[i - 1], p);
			pow_q[i] = mul(pow_q[i - 1], q);
		}

		memset (f, 0, sizeof f);
		for (int n = 0; n <= N; ++n) {
			for (int k = 0; k <= n; ++k) {
				if  (k == 0) {
					f[n][k] = 1;
					continue;
				}

				// first in set
				add(f[n][k], mul(f[n - 1][k - 1], pow_p[n - k]));

				// first not in set
				if  (n > k) {
					add(f[n][k], mul(f[n - 1][k], pow_q[k]));
				}
			}
		}

		p_full[0] = 0;
		for (int n = 1; n <= N; ++n) {
			int bad = 0;
			for (int k = 1; k < n; ++k) {
				add(bad, mul(f[n][k], p_full[k]));
			}
			p_full[n] = 1;
			sub(p_full[n], bad);

			eprintf("p_full[%d] = %d\n", n, p_full[n]);
		}

		memset (dp, 0, sizeof dp);
		memset (ans, 0, sizeof ans);
		ans[0] = 0;
		dp[0] = 0;
		for (int n = 2; n <= N; ++n) {
			dp[n] = 0;
			for (int k = 1; k < n; ++k) {
				int cur = mul(f[n][k], p_full[k]);
				int rec = ans[k];
				add(rec, dp[n - k]);
				cur = mul(cur, rec);
				add(dp[n], cur);
			}

			const int pairs = n * (n - 1) / 2;
			ans[n] = dp[n];
			add(ans[n], pairs);
			const int q_full = (1 - p_full[n] + MOD) % MOD;
			ans[n] = mul(ans[n], inv(q_full));

			add(dp[n], mul(mul(f[n][n], p_full[n]), ans[n]));

			eprintf("ans[%d] = %d\n", n, ans[n]);
		}

		return ans[N];
	}
};

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		int ans = int_solver::solve();

		printf("%d\n", ans);
	}

#ifdef LOCAL
	eprintf("Time: %.10f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}