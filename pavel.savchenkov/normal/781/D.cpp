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
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;

#define FILE_NAME "a"

const int MAXL = 63;
const int MAXN = 500 + 12;

#define TEST 0

int n, m;
bool type[2][MAXN][MAXN];

bool read() {
#if !TEST
	if  (scanf("%d%d", &n, &m) < 2) {
		return 0;
	}
	memset (type, 0, sizeof type);
	forn(i, m) {
		int a, b, t;
		scanf("%d%d%d", &a, &b, &t);
		--a;
		--b;
		type[t][a][b] = 1;
	}
	return 1;
#else
	n = 500;
	memset (type, 0, sizeof type);
	m = rand() % n;
	forn(i, m) {
		int a = rand() % n;
		int b = rand() % n;
		int t = rand() % 2;
		type[t][a][b] = 1;
	}
	return 1;
#endif
}

bitset<MAXN> dp_start[2][MAXL][MAXN];
bitset<MAXN> dp_end[2][MAXL][MAXN];
ll dp[2][MAXL][MAXN];

const ll INF = 1e18;

ll add(ll x, ll y) {
	return min(x + y, INF + 1);
}

void remax(ll &x, ll y) {
	if  (x < y) {
		x = y;
	}
}

ll solve() {
	forn(sw, 2) forn(l, MAXL) forn(v, MAXN) {
		dp_start[sw][l][v] = bitset<MAXN>();
		dp_end[sw][l][v] = bitset<MAXN>();
	}

	forn(l, MAXL) {
		forn(v, n) forn(u, n) forn(sw, 2) {
			if  (l == 0) {
				if (type[sw][v][u]) {
					dp_start[sw][l][v].set(u);
					dp_end[sw][l][u].set(v);
				}
			} else {
				bool ok = (dp_start[sw][l - 1][v] & dp_end[sw ^ 1][l - 1][u]).count() > 0;
				if  (ok) {
					dp_start[sw][l][v].set(u);
					dp_end[sw][l][u].set(v);
				}
			}
		}
	}

	memset (dp, 0, sizeof dp);
	forn(l, MAXL) {
		forn(v, n) forn(sw, 2) {
			if  (dp_start[sw][l][v].count() > 0) {
				dp[sw][l][v] = add(1ll << l, 0);
				continue;
			}
			forn(l2, l) {
				forn(to, n) {
					if  (dp_start[sw][l2][v][to]) {
						remax(dp[sw][l][v], add(1ll << l2, dp[sw ^ 1][l2][to]));
					}
				}
			}
		}
	}

	ll res = dp[0][MAXL - 1][0];
	if  (res > INF) {
		return -1;
	}
	return res;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	// cout << INF << endl;

	while (read()) {
#if TEST
		double st = (double) clock() / CLOCKS_PER_SEC;
#endif
		printf("%lld\n", solve());

#if TEST
		printf("Time: %.10f\n", (double) clock() / CLOCKS_PER_SEC - st);
#endif	
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}