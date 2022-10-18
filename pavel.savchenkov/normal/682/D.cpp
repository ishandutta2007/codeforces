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


const int MAXN = 1e3 + 10;
const int MAXK = 12;
const int INF = 1e9;

int dp[2][MAXK][MAXN][MAXN];
char s[MAXN];
char t[MAXN];
int n, m, k;

bool read() {
	if  (scanf("%d%d%d\n", &n, &m, &k) < 3) {
		return false;
	}
	gets(s);
	gets(t);
	return true;
}

void remax(int& x, int y) {
	if  (x < y) {
		x = y;
	}
}

int solve() {
	forn(i, n + 1) forn(j, m + 1) forn(have, k + 1) forn(c, 2) dp[c][have][i][j] = -INF;
	
	// puts(s);
	// puts(t);
	// printf("k = %d\n", k);

	dp[0][0][0][0] = 0;
	forn(have, k + 1) forn(i, n) forn(j, m) forn(eq, 2) {
		int cur_dp = dp[eq][have][i][j];
		if  (cur_dp < 0) {
			continue;
		}

		if  (eq && s[i] == t[j]) {
			remax(dp[eq][have][i + 1][j + 1], cur_dp + 1);
		} 

		if  (s[i] == t[j]) {
			remax(dp[1][have + 1][i + 1][j + 1], cur_dp + 1);
		}

		remax(dp[0][have][i][j + 1], cur_dp);
		remax(dp[0][have][i + 1][j], cur_dp);
	}

	// forn(eq, 2) forn(have, k + 1) forn(i, n + 1) forn(j, m + 1) {
	// 	int cur_dp = dp[eq][have][i][j];
	// 	if  (cur_dp < 0) {
	// 		continue;
	// 	}

	// 	printf("dp[eq=%d][have=%d][i=%d][j=%d] = %d\n", eq, have, i, j, cur_dp);
	// }

	int ans = 0;
	forn(eq, 2) forn(i, n + 1) forn(j, m + 1) remax(ans, dp[eq][k][i][j]);
	return ans;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif


	while (read()) {
		printf("%d\n", solve());
		break;
	}

#ifdef LOCAL
	printf("Time: %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}