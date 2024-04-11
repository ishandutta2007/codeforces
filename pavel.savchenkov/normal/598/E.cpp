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
const int INF = 1e9;

int dp[31][31][51];

void precalc() {
	for (int n = 1; n <= 30; ++n) {
		for (int m = 1; m <= 30; ++m) {
			for (int k = 0; k <= 50; ++k) {
				if  (n * m == k || k == 0) {
					dp[n][m][k] = 0;
					continue;
				}
				dp[n][m][k] = INF;
				if  (n * m < k) {
					continue;
				}
				for (int nn = 1; nn * 2 <= n; ++nn) {
					for (int l = 0; l <= k; ++l) {
						dp[n][m][k] = min(dp[n][m][k], dp[nn][m][l] + dp[n - nn][m][k - l] + m * m);
					}
				}
				for (int mm = 1; mm * 2 <= m; ++mm) {
					for (int l = 0; l <= k; ++l) {
						dp[n][m][k] = min(dp[n][m][k], dp[n][mm][l] + dp[n][m - mm][k - l] + n * n);
					}
				}
			}
		}
	}
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
//	freopen(FILE_NAME ".out", "w", stdout);
#endif
  
  	precalc();

  	int t;
  	cin >> t;
  	forn(i, t) {
  		int n, m, k;
  		scanf("%d%d%d", &n, &m, &k);
  		printf("%d\n", dp[n][m][k]);
  	}
	return 0;
}