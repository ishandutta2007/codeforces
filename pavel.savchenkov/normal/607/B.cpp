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
const int MAXN = 500 + 10;
const int INF = 1e9;

int c[MAXN];
int n;

bool read() {
	if  (scanf("%d", &n) < 1) {
		return false;
	}
	forn(i, n) {
		scanf("%d", &c[i]);
	}
	return true;
}

int dp[MAXN][MAXN];

int solve() {
	for (int len = 1; len <= n; ++len) {
		forn(l, n) {
			int r = l + len - 1;
			if  (r >= n) {
				break;
			}
			if  (len == 1) {
				dp[l][r] = 1;
				continue;
			}
			dp[l][r] = INF;
			if  (c[l] == c[r]) {
				if  (len == 2) {
					dp[l][r] = 1;
				} else {
					dp[l][r] = min(dp[l][r], dp[l + 1][r - 1]);
				}
			}
			for (int ll = l + 1; ll <= r; ++ll) {
				dp[l][r] = min(dp[l][r], dp[l][ll - 1] + dp[ll][r]);
			}
			for (int rr = r - 1; rr >= l; --rr) {
				dp[l][r] = min(dp[l][r], dp[l][rr] + dp[rr + 1][r]);
			}
		}
	}
	return dp[0][n - 1];
}

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
//	freopen(FILE_NAME ".out", "w", stdout);
#endif
	
	while (read()) {
		printf("%d\n", solve());
	}
	return 0;
}