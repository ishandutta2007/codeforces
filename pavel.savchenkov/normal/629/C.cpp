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
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector <int> > vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME "a"

const int MOD = 1e9 + 7;
const int MAXN = 2e3 + 10;

void add(int& x, int y) {
	((x += y) >= MOD) && (x -= MOD);
}

int mul(int x, int y) {
	return x * 1ll * y % MOD;
}

int C[MAXN][MAXN];

void precalc() {
	C[0][0] = 1;
	for (int i = 1; i < MAXN; ++i) {
		C[i][0] = 1;
		for (int j = 1; j < MAXN; ++j) {
			C[i][j] = C[i - 1][j];
			add(C[i][j], C[i - 1][j - 1]);
		}
	}
}

int dp[MAXN][MAXN]; // len, sum
int sum_s;
int min_s;
int n, m;

bool read() {
	if  (scanf("%d%d\n", &n, &m) < 2) {
		return false;
	}
	static char s[(int) 1e5 + 10];
	gets(s);
	sum_s = 0;
	min_s = 0;
	forn(i, m) {
		sum_s += s[i] == '(' ? +1 : -1;
		min_s = min(min_s, sum_s);
	}
	return true;
}

int get_cnt(int len, int sum) {
	if  ((len + sum) % 2 != 0) {
		return 0;
	} 
	int x = (len + sum) / 2;
	if  (x < 0 || x > len) return 0;
	return C[len][x];
}

int solve() {
	dp[0][0] = 1;
	forn(i, MAXN - 1) forn(j, MAXN - 1) {
		if  (!dp[i][j]) {
			continue;
		}
		add(dp[i + 1][j + 1], dp[i][j]);
		if  (j > 0) {
			add(dp[i + 1][j - 1], dp[i][j]);
		}
	}

	int ans = 0;
	for (int len_p = 0; len_p <= n - m; ++len_p) {
		for (int sum_p = max(0, -min_s); sum_p <= len_p; ++sum_p) {
			if  (!dp[len_p][sum_p]) {
				continue;
			}
			int len_q = (n - m) - len_p;
			int sum_q = - (sum_p + sum_s);
			int min_q = - sum_p - sum_s;
			int good = get_cnt(len_q, sum_q);
			int bad = get_cnt(len_q, min_q - 2);

			int cnt = good;
			add(cnt, -bad + MOD);

			add(ans, mul(cnt, dp[len_p][sum_p]));
		}
	}
	return ans;
}

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	precalc();

	while (read()) {
		printf("%d\n", solve());
	}

	return 0;
}