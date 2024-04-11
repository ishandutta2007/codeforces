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

int k, pa, pb;

bool read() {
	if  (scanf("%d%d%d", &k, &pa, &pb) < 3) {
		return 0;
	}
	return 1;
}

const int MAXN = 1e3 + 10;

ld solve_old() {
	ld ans = 0;

	static ld dp[MAXN][MAXN];

	const ld prob_a = ld(pa) / (pa + pb);
	const ld prob_b = ld(pb) / (pa + pb);
	memset (dp, 0, sizeof dp);
	dp[1][0] = 1.0;
	for (int a = 1; a <= k; ++a) {
		for (int r = 0; r < k; ++r) {
			const ld cur_dp = dp[a][r];
			
			eprintf("dp[a=%d][r=%d] = %.5f\n", a, r, (double) cur_dp);

			// a
			dp[a + 1][r] += cur_dp * prob_a;

			// b
			if  (r + a >= k) {
				ans += cur_dp * prob_b * (r + a);
				eprintf("ans += (%.10f) * (%d)\n", double(cur_dp * prob_b), r + a);
			} else {
				dp[a][r + a] += cur_dp * prob_b;
			}
		}
	}

	eprintf("ans = %.10f\n", (double) ans);

	for (int r = 0; r < k; ++r) {
		const ld cur_dp = dp[k + 1][r];

		eprintf("a=%d, r=%d, dp=%.10f\n", k + 1, r, (double) cur_dp);

		ld h = r + (k + 1);
		ans += cur_dp * h * prob_b * (1 / (1 - prob_a));
		ans += cur_dp * prob_b * prob_a / (prob_a - 1) / (prob_a - 1);

		// eprintf("")
		// ans += cur_dp * ((r + k + 1) + (prob_b / (1 - prob_a)));

		// ans += cur_dp * (prob_b / (1 - prob_a)) * (r + (k + 1) + 1);

		// {
		// 	forn(i, 1000) {
		// 		ld prob = 1.0;
		// 		forn(j, i) {
		// 			prob *= prob_a;
		// 		}
		// 		prob *= prob_b;
		// 		ans += cur_dp * prob * (r + (k + 1) + i);
		// 	}
		// }
	}

	return ans;
}

const int MOD = 1e9 + 7;

void add(int& x, int y) {
	((x += y) >= MOD) && (x -= MOD);
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

int solve() {
	static int dp[MAXN][MAXN];

	int ans = 0;

	const int prob_a = mul(pa, inv(pa + pb));
	const int prob_b = mul(pb, inv(pa + pb));

	memset (dp, 0, sizeof dp);
	dp[1][0] = 1;
	for (int a = 1; a <= k; ++a) {
		for (int r = 0; r < k; ++r) {
			const int cur_dp = dp[a][r];

			// a
			add(dp[a + 1][r], mul(cur_dp, prob_a));

			// b
			const int coef = mul(cur_dp, prob_b);
			if  (r + a >= k) {
				add(ans, mul(coef, r + a));
			} else {
				add(dp[a][r + a], coef);
			}
		}
	}

	for (int r = 0; r < k; ++r) {
		const int cur_dp = dp[k + 1][r];

		const int h = r + (k + 1);

		// ans += cur_dp * h * prob_b * (1 / (1 - prob_a));
		// ans += cur_dp * prob_b * prob_a / (prob_a - 1) / (prob_a - 1);

		int c1 = cur_dp;
		c1 = mul(c1, h);
		c1 = mul(c1, prob_b);
		c1 = mul(c1, inv((-prob_a + 1 + MOD) % MOD));
		add(ans, c1);

		int c2 = cur_dp;
		c2 = mul(c2, prob_b);
		c2 = mul(c2, prob_a);
		c2 = mul(c2, inv((prob_a - 1 + MOD) % MOD));
		c2 = mul(c2, inv((prob_a - 1 + MOD) % MOD));

		add(ans, c2);
	}

	return ans;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	// {
	// 	ld ans = 0;
	// 	ld res = 0;
	// 	forn(i, 1000) {
	// 		ld cur = 1.0;
	// 		forn(j, i + 1) {
	// 			cur *= 0.5;
	// 		}
	// 		res += cur;
	// 	}
	// 	eprintf("ans = %.10f\n", (double) res);
	// 	return 0;
	// }

	while (read()) {
		// printf("%.10f\n", (double) solve_old());

		printf("%d\n", solve());

	}

#ifdef LOCAL
	eprintf("Time: %.10f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}