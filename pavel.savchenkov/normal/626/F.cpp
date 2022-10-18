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

const int MAXN = 200 + 10;
const int MOD = 1e9 + 7;
const int MAXK = 1e3 + 10;

void add(int& x, int y) {
	((x += y) >= MOD) && (x -= MOD);
}

int mul(int x, int y) {
	return x * 1ll * y % MOD;
}

int a[MAXN];
int n, k;
int dp[MAXN][MAXN][MAXK];

bool read() {
	if  (scanf("%d%d", &n, &k) < 2) {
		return false;
	}
	forn(i, n) {
		scanf("%d", &a[i]);
	}
	return true;
}

int solve() {
	sort(a, a + n);
	ford(i, n) {
		a[i] -= a[0];
	}

	// forn(i, n) {
	// 	cout << a[i] << endl;
	// }

	memset (dp, 0, sizeof dp);
	dp[n - 1][1][0] = 1;
	dp[n - 1][0][0] = 1;
	ford(i, n - 1) forn(j, n + 1) forn(bal, k + 1) {
		int d = dp[i + 1][j][bal];
		if  (!d) {
			continue;
		}
		// printf("dp[%d][%d][%d] = %d\n", i + 1, j, bal, d);

		int b = bal + a[i + 1] * j;

		if  (b - a[i] * j > k) {
			continue;
		}

		// nothing
		add(dp[i][j][b - a[i] * j], d);

		// only -
		if  (j > 0) {
			add(dp[i][j - 1][(b - a[i]) - a[i] * (j - 1)], mul(d, j));
		}

		// only +
		add(dp[i][j + 1][b - a[i] * j], d);

		// - +
		if  (j > 0) {
			add(dp[i][j][b - a[i] * j], mul(j, d));
		}
	}

	int ans = 0;
	forn(b, k + 1) {
		add(ans, dp[0][0][b]);
	}

	return ans;
}

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		printf("%d\n", solve());
	}

	return 0;
}