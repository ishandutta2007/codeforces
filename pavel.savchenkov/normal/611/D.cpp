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

using namespace std;

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define next jskdfksdhfjkdsjksdjkgf
#define prev koeuigrihjdkjdfj
#define hash kjfdkljkdhgjdkfhgurehg
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME "a"

const ld EPS = 1e-9;
const int MAXN = 5e3 + 10;
const int MOD = 1e9 + 7;

void add(int& x, int y) {
	((x += y) >= MOD) && (x -= MOD);
}

int mul(int x, int y) {
	return x * 1ll * y % MOD;
}

char s[MAXN];
int n;
int lcp[MAXN][MAXN];

bool read() {
	if  (scanf("%d\n", &n) < 1) {
		return false;
	} 
	gets(s);
	return true;
}

void precalc() {
	ford(i, n + 1) ford(j, n + 1) {
		if  (i >= n || j >= n) {
			lcp[i][j] = 0;
			continue;
		}
		if  (s[i] != s[j]) {
			lcp[i][j] = 0;
			continue;
		}
		lcp[i][j] = 1 + lcp[i + 1][j + 1];
	}
}

// [l, m], [m + 1, r]
bool can(int l, int m, int r) {
	if  (s[l] == '0' || s[m + 1] == '0') return false;
	int l1 = m - l + 1;
	int l2 = r - (m + 1) + 1;
	if  (l1 > l2) return false;
	if  (l1 < l2) return true;
	int L = lcp[l][m + 1];
	if  (L >= l1) return false;
	int pos = L;
	assert(s[l + pos] != s[m + 1 + pos]);
	return s[l + pos] < s[m + 1 + pos];	
}

int dp[MAXN][MAXN];
int sum_dp[MAXN][MAXN];

void precalc_dp(int r) {
	forn(l, r + 1) {
		sum_dp[l][r] = dp[l][r];
		if  (l > 0) {
			add(sum_dp[l][r], sum_dp[l - 1][r]);
		}
	}
}

int get_sum(int l1, int l2, int r) {
	// int A = 0;
	// for (int l = l1; l <= l2; ++l) {
	// 	add(A, dp[l][r]);
	// }
	// return A;
	l1 = max(l1, 0);
	int ans = sum_dp[l2][r];
	if  (l1 > 0) {
		add(ans, -sum_dp[l1 - 1][r] + MOD);
	}
	return ans;
}

int solve() {
	// puts(s);

	memset (dp, 0, sizeof dp);
	forn(r, n) {
		forn(l, r + 1) {
			if  (s[l] == '0') {
				continue;
			}
			if  (l == 0) {
				dp[l][r] = 1;
				continue;
			}
			// p < l <= r
			// (r - l + 1) > ((l - 1) - p + 1)
			// L > l - 1 - p + 1
			// p > l - 1 - L + 1
			// p < l
			// [l - 1 - L + 1 + 1, l - 1]
			int L = r - l + 1;
			int pl = l - 1 - L + 2;
			int pr = l - 1;
			if  (pl <= pr) {
				dp[l][r] = get_sum(pl, pr, l - 1);
			}
			int p = l - 1 - L + 1;
			// if  (l == r && r == n - 1) {
			// 	printf("dp = %d, p = %d\n", dp[l][r], p);
			// }
			if  (0 <= p & p < l && L == (l - 1 - p + 1) && can(p, l - 1, r)) {
				add(dp[l][r], dp[p][l - 1]);
			}
		}
		precalc_dp(r);
	}
	// for (int l = 0; l < n; ++l) {
	// 	printf("dp[%d][%d] = %d\n", l, n - 1, dp[l][n - 1]);
	// }
	return get_sum(0, n - 1, n - 1);
}

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
//	freopen(FILE_NAME ".out", "w", stdout);
#endif
	
	while (read()) {
		precalc();
		printf("%d\n", solve());
	}

	return 0;
}