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


const int MAXN = 400 + 10;
const int INF = 1e9;
const ld EPS = 1e-10;

int g[MAXN][MAXN];
int n, m;

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return false;
	}
	forn(i, n) forn(j, n) g[i][j] = INF * (i != j);
	forn(i, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		g[a][b] = g[b][a] = 1;
	} 
	return true;
}

vi with_d[MAXN][MAXN];
ld prob_to[MAXN];
ld max_prob[MAXN];

ld solve() {
	forn(k, n) forn(i, n) forn(j, n) g[i][j] = min(g[i][k] + g[k][j], g[i][j]);

	forn(a, n) forn(b, n) {
		with_d[a][g[a][b]].pb(b);
	}

	ld ans = 0;
	forn(a, n) {
		ld cur = 0.0;
		forn(d, n) {
			if  (with_d[a][d].empty()) {
				continue;
			}

			memset (prob_to, 0, sizeof prob_to);
			for (int e : with_d[a][d]) {
				int deg = 0;
				forn(c, n) {
					if  (g[e][c] == 1) {
						++deg;
					}
				}
				forn(c, n) {
					if  (g[e][c] == 1) {
						prob_to[c] += (1.0 / sz(with_d[a][d])) * (1.0 / deg);
					}
				}
			}

			ld coef = (ld) sz(with_d[a][d]) / n;
			ld ans1 = 1.0 / sz(with_d[a][d]);
			ld ans2 = 0;
			forn(b, n) {
				ld cur_b = 0;
				for (int dd = max(0, d - 1); dd <= min(n - 1, d + 1); ++dd) {
					for (int c : with_d[a][dd]) {
						int D = g[b][c];
						cur_b -= max_prob[D];
						max_prob[D] = max(max_prob[g[b][c]], prob_to[c]);
						cur_b += max_prob[D];
					}
				}
				ans2 = max(ans2, cur_b);

				for (int dd = max(0, d - 1); dd <= min(n - 1, d + 1); ++dd) {
					for (int c : with_d[a][dd]) {
						int D = g[b][c];
						max_prob[D] = 0;
					}
				}
			}

			cur += coef * max(ans1, ans2);
		}

		ans = max(ans, cur);
	}

	return ans;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		printf("%.10f\n", (double) solve());
	}

#ifdef LOCAL
	printf("Time: %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}