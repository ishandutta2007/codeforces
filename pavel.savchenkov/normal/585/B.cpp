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


const int MAXN = 100 + 10;

string s[3];
int n, k;

bool read() {
	if  (scanf("%d%d\n", &n, &k) < 2) {
		return false;
	}
	forn(i, 3) {
		getline(cin, s[i]);
	}
	return true;
}

bool dp[MAXN][3];

bool free(int i, int j, int t) {
	if  (j + t < sz(s[i]) && s[i][j + t] != '.' && s[i][j + t] != 's') {
		return false;
	}
	return true;
}

bool solve() {
	memset (dp, false, sizeof dp);
	forn(i, 3) {
		if  (s[i][0] == 's') {
			dp[0][i] = true;
		}
	}

	forn(t, n + 1) forn(i, 3) {
		if  (!dp[t][i]) {
			continue;
		}

		assert(free(i, t, t * 2));

		// printf("dp[t=%d][i=%d]\n", t, i);

		if  (t == n - 1) {
			return true;
		}

		forn(ni, 3) {
			if  (abs(i - ni) > 1) {
				continue;
			}
			if  (!free(i, t + 1, t * 2)) {
				continue;
			}
			if  (free(ni, t + 1, t * 2) && t + 1 == n - 1) {
				return true;
			}
			if  (free(ni, t + 1, t * 2) && free(ni, t + 1, t * 2 + 1) && free(ni, t + 1, t * 2 + 2)) {
				dp[t + 1][ni] = true;
			}
		}
	}
	return false;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	int T;
	scanf("%d\n", &T);
	while (T --> 0) {
		assert(read());
		puts(solve() ? "YES" : "NO");
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}