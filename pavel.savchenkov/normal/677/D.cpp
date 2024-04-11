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


const int MAXN = 300 + 10;
const ll INF = 1e15;

int a[MAXN][MAXN];
int n, m, p;
ll dp[MAXN][MAXN];

bool read() {
	if  (scanf("%d%d%d", &n, &m, &p) < 3) {
		return false;
	}
	forn(i, n) forn(j, m) {
		scanf("%d", &a[i][j]);
		--a[i][j];
	}
	// n = 300;
	// m = 300;
	// forn(i, n) forn(j, m) {
	// 	a[i][j] = i * m + j;
	// }
	// p = a[n - 1][m - 1] + 1;
	return true;
}

int dist(int x, int y, int x1, int y1) {
	return abs(x - x1) + abs(y - y1);
}

int who_row[MAXN];
vi cols[MAXN * MAXN];

ll solve() {
	// forn(i, n) {
	// 	forn(j, m) {
	// 		cout << a[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << "p = " << p << endl;

	forn(i, n) forn(j, m) {
		dp[i][j] = INF;
	}

	forn(i, n) forn(j, m) {
		cols[a[i][j]].pb(j);
	}

	forn(x, p) {
		sort(all(cols[x]));
		cols[x].resize(unique(all(cols[x])) - cols[x].begin());
	}

	forn(i, n) forn(j, m) {
		if  (a[i][j] == 0) {
			dp[i][j] = dist(i, j, 0, 0);
		}
	}

	ll ans = 0;
	for (int c = 1; c < p; ++c) {
		memset (who_row, -1, sizeof who_row);
		vi cls;
		cls.resize(sz(cols[c - 1]) + sz(cols[c]));
		merge(all(cols[c - 1]), all(cols[c]), cls.begin());

		for (int j : cls) {
			forn(i, n) {
				if  (a[i][j] == c - 1) {
					if  (who_row[i] == -1 || dp[i][who_row[i]] + abs(j - who_row[i]) > dp[i][j]) {
						who_row[i] = j;
					}
				}
			}
			forn(i, n) {
				if  (a[i][j] == c) {
					forn(i1, n) {
						int j1 = who_row[i1];
						if  (j1 == -1) {
							continue;
						}
						dp[i][j] = min(dp[i][j], dp[i1][j1] + dist(i, j, i1, j1));
					}
					ans = dp[i][j];
				}
			}
		}

		reverse(all(cls));
		memset (who_row, -1, sizeof who_row);
		for (int j : cls) {
			forn(i, n) {
				if  (a[i][j] == c - 1) {
					if  (who_row[i] == -1 || dp[i][who_row[i]] + abs(j - who_row[i]) > dp[i][j]) {
						who_row[i] = j;
					}
				}
			}
			forn(i, n) {
				if  (a[i][j] == c) {
					forn(i1, n) {
						int j1 = who_row[i1];
						if  (j1 == -1) {
							continue;
						}
						dp[i][j] = min(dp[i][j], dp[i1][j1] + dist(i, j, i1, j1));
					}
					ans = dp[i][j];
				}
			}
		}
	}
	return ans;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif


	while (read()) {
		cout << solve() << endl;
	}

#ifdef LOCAL
	printf("Time: %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}