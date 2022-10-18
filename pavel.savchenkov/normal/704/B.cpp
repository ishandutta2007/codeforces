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

#define ws ws_____________________
#define y1 y1_____________________
#define y0 y0_____________________
#define left left_________________
#define right right_______________
#define next next_________________
#define prev prev_________________
#define hash hash_________________

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
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


const int MAXN = 5e3 + 10;
const int K = 2;
const ll INF = 1e18;

ll dp[2][MAXN][2 * K + 1];
int x[MAXN];
int a[MAXN];
int b[MAXN];
int c[MAXN];
int d[MAXN];
int n, s, e;

bool read() {
	if  (scanf("%d%d%d", &n, &s, &e) < 3) {
		return false;
	}
	--s;
	--e;
	forn(i, n) {
		scanf("%d", &x[i]);
	}
	forn(i, n) {
		scanf("%d", &a[i]);
	}
	forn(i, n) {
		scanf("%d", &b[i]);
	}
	forn(i, n) {
		scanf("%d", &c[i]);
	}
	forn(i, n) {
		scanf("%d", &d[i]);
	}
	return true;
}

int C;

void upd(int i, int l, int r, ll ndp) {
	if  (l == 0 && r == 0 && i < n) {
		return;
	}
	assert(0 <= l);
	assert(0 <= r);
	int diff = r - l;
	if  (-K <= diff && diff <= K && ndp < dp[C ^ 1][l][K + diff]) {
		dp[C ^ 1][l][K + diff] = ndp;
	}
}

ll solve() {
	C = 0;
	forn(i, 2) forn(l, n + 1) forn(diff, 2 * K + 1) dp[i][l][diff] = INF;

	dp[C][0][K + 0] = 0;
	forn(i, n) {
		forn(l, i + 1) for (int diff = -K; diff <= K; ++diff) {
			ll cur_dp = dp[C][l][K + diff];
			if  (cur_dp >= INF) {
				continue;
			}

			int r = l + diff;
			assert(0 <= r);

			// printf("dp[%d][%d][%d] = %lld\n", i, l, r, cur_dp);

			if  (i == s) {
				if  (r > 0) {
					int nl = l;
					int nr = r - 1;
					upd(i + 1, nl, nr, cur_dp + c[i] + x[i]); 
				}

				{
					int nl = l + 1;
					int nr = r;
					upd(i + 1, nl, nr, cur_dp + d[i] - x[i]);
				}

				continue;
			}

			if  (i == e) {
				{
					int nl = l;
					int nr = r + 1;
					upd(i + 1, nl, nr, cur_dp + b[i] - x[i]);
				}

				if  (l > 0) {
					int nl = l - 1;
					int nr = r;
					upd(i + 1, nl, nr, cur_dp + a[i] + x[i]);
				}
			
				continue;
			}

			{
				if  (r > 0) {
					int nl = l;
					int nr = r;
					upd(i + 1, nl, nr, cur_dp + b[i] + c[i]);
				}
			}

			{
				if  (l > 0) {
					int nl = l;
					int nr = r;
					upd(i + 1, nl, nr, cur_dp + a[i] + d[i]);
				}
			}

			{
				if  (l > 0 && r > 0) {
					int nl = l - 1;
					int nr = r - 1;
					upd(i + 1, nl, nr, cur_dp + a[i] + c[i] + 2ll * x[i]);
				}
			}

			{
				int nl = l + 1;
				int nr = r + 1;
				upd(i + 1, nl, nr, cur_dp + b[i] + d[i] - 2ll * x[i]);
			}
		}

		forn(l, n + 1) forn(diff, 2 * K + 1) dp[C][l][diff] = INF;
		C ^= 1;
	}

	// restore(n, 0, 0);

	return dp[C][0][K + 0];
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
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}