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


const int MAXN = 18 + 1;

ld dp[MAXN][1 << MAXN];
ld p[MAXN][MAXN];
int n;

ld read_ld() {
	double x;
	scanf("%lf", &x);
	return x;
}

bool read() {
	if  (scanf("%d", &n) < 1) {
		return false;
	}
	forn(i, n) forn(j, n) {
		p[i][j] = read_ld();
	}
	return true;
}

inline bool bit(int mask, int i) {
	return (mask >> i) & 1;
}

ld solve() {
	const int full = (1 << n) - 1;
	memset (dp, 0, sizeof dp);
	
	dp[0][0] = 1.0;
	forn(mask, 1 << n) forn(i, n) {
		if  (bit(mask, i)) {
			continue;
		}

		forn(j, n) {
			if  (bit(mask, j)) {
				int nmask = mask ^ (1 << j);
				dp[i][mask] = max(dp[i][mask], dp[i][nmask] * p[i][j] + dp[j][nmask] * p[j][i]);
			}
		}
	}

	ld ans = 0.0;
	forn(i, n) {
		ans = max(ans, dp[i][full ^ (1 << i)]);
	}
	return ans;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		printf("%.15f\n", (double) solve());
	}

#ifdef LOCAL
	printf("Time: %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}