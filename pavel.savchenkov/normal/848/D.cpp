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

const int MOD = 1e9 + 7;

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

const int MAXN = 50 + 10;

int mem_inv[MAXN];

int inv(int x) {
	int& y = mem_inv[x];
	if  (y) {
		return y;
	}
	y = mpow(x, MOD - 2);
	assert(mul(x, y) == 1);
	return y;
}

int n, m;

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return 0;
	}
	n += 2;
	return 1;
}

int dp2[MAXN][MAXN];
int dp[MAXN][MAXN];
int dp_big[MAXN][MAXN][MAXN][MAXN];

int binom(int n, int k) {
	assert(k);
	add(n, k - 1);
	int ans = 1;
	forn(i, k) {
		int cur_n = n;
		sub(cur_n, i);
		ans = mul(ans, cur_n);
		ans = mul(ans, inv(i + 1));
	}
	return ans;
}

int calc_dp(int, int);
int calc_dp2(int, int);
int calc_dp_big(int, int, int, int);

int calc_dp2(int n, int m) {
	if  (n < 3) {
		return 0;
	}

	// printf("dp2: n=%d, m=%d\n", n, m);

	int& mem = dp2[n][m];

	if  (mem != -1) {
		return mem;
	}

	int ans = 0;
	for (int n_left = 2; n_left < n; ++n_left) {
		const int n_right = n - n_left + 1;

		// min on left
		for (int m_right = m; m_right < MAXN; ++m_right) {
			add(ans, mul(calc_dp(n_left, m), calc_dp(n_right, m_right)));
		}

		// min on right
		for (int m_left = m + 1; m_left < MAXN; ++m_left) {
			add(ans, mul(calc_dp(n_left, m_left), calc_dp(n_right, m)));
		}
	}

	return (mem = ans);
}

int calc_dp_big(int n, int m, int n1, int m1) {
	// printf("dp_big: n=%d, m=%d, n1=%d, m1=%d\n", n, m, n1, m1);

	if  (n < 2) {
		return 0;
	}

	if  (n == 2) {
		return (m == 0);
	}

	if  (m <= 0 || n1 < 3) {
		return 0;
	}

	assert(m1 >= 0);

	int& mem = dp_big[n][m][n1][m1];

	if  (mem != -1) {
		return mem;
	}

	int new_n1 = n1;
	int new_m1 = m1 - 1;
	if  (new_m1 == -1) {
		new_n1--;
		new_m1 = MAXN - 1;
	}

	int ans = 0;
	for (int cnt = 0; (n1 - 2) * cnt + 2 <= n && m1 * cnt <= m; ++cnt) {
		int cur = cnt ? binom(calc_dp2(n1, m1), cnt) : 1;
		int will = calc_dp_big(n - (n1 - 2) * cnt, m - m1 * cnt, new_n1, new_m1);
		add(ans, mul(cur, will));
	}

	return (mem = ans);
}

int calc_dp(int n, int m) {
	int& mem = dp[n][m];

	// printf("dp: n=%d, m=%d\n", n, m);

	if  (mem != -1) {
		return mem;
	}

	int ans = calc_dp_big(n, m - 1, MAXN - 1, MAXN - 1);
	return (mem = ans);
}

int solve() {
	memset (dp2, -1, sizeof dp2);
	memset (dp, -1, sizeof dp);
	memset (dp_big, -1, sizeof dp_big);

	// forn(i, n + 1) forn(j, m + 1) {
	// 	int ans = calc_dp(i, j);
	// 	printf("dp[n=%d][m=%d] = %d\n", i, j, ans);
	// }

	// forn(i, n + 1) forn(j, m + 1) {
	// 	int ans = calc_dp2(i, j);
	// 	printf("dp2[n=%d][m=%d] = %d\n", i, j, ans);
	// }

	// forn(i, n + 1) forn(j, m + 1) {
	// 	forn(ii, MAXN) forn(jj, m + 1) {
	// 		int ans = calc_dp_big(i, j, ii, jj);
	// 		if  (ans) {
	// 			printf("dp_big: n=%d, m=%d, n1=%d, m1=%d -> %d\n", i, j, ii, jj, ans);
	// 		}
	// 	}
	// }

	return calc_dp(n, m);
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		printf("%d\n", solve());
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}