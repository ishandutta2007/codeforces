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

const int MAXN = 70;

ull dp[MAXN][4][MAXN];

int main() {
#ifdef DEBUG
	// freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	int n;
	cin >> n;

	memset (dp, 0, sizeof dp);
	forn(i, 4) {
		dp[1][i][1] = 1;
	}

	ull ans = 0;
	for (int i = 1; i <= 2 * n - 2; ++i) {
		forn(c, 4) {
			forn(have, n + 1) {
				// same
				if  (have < n) {
					dp[i + 1][c][have + 1] += dp[i][c][have];
				}

				// diff
				forn(cc, 4) {
					if  (cc != c) {
						dp[i + 1][cc][1] += dp[i][c][have];
					}
				}
			}
			int rest = (2 * n - 2) - i;
			assert(rest >= 0);
			ans += dp[i][c][n] * (rest > 0 ? (3ull * (1ull << ((rest - 1) * 2))) : 1);
		}
	}

	cout << ans << endl;
	return 0;
}