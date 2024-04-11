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


const int MAXN = 500 + 10;

bool dp[MAXN][MAXN][MAXN];
int n, k;
int c[MAXN];

bool read() {
	if  (scanf("%d%d", &n, &k) < 2) {
		return false;
	}
	forn(i, n) {
		scanf("%d", &c[i]);
	}
	return true;
}

void solve() {
	memset (dp, 0, sizeof dp);
	dp[0][0][0] = true;
	forn(i, n) forn(K, MAXN) forn(x, K + 1) {
		bool cur_dp = dp[i][K][x];
		if  (!cur_dp) {
			continue;
		}

		// use c[i]
		if  (K + c[i] < MAXN) {
			dp[i + 1][K + c[i]][x] = true;
			dp[i + 1][K + c[i]][x + c[i]] = true;
		}

		// do not use c[i]
		dp[i + 1][K][x] = true;
	}

	vi ans;
	forn(x, MAXN) {
		if  (dp[n][k][x]) {
			ans.pb(x);
		}
	}

	printf("%d\n", sz(ans));
	for (int x : ans) {
		printf("%d ", x);
	}
	puts("");
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		solve();
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}