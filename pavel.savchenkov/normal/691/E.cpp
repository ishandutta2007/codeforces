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
const int MOD = 1e9 + 7;

int n;
ll k;

void mult(int a[MAXN][MAXN], int b[MAXN][MAXN], int c[MAXN][MAXN]) {
	static int res[MAXN][MAXN];
	forn(i, n) forn(j, n) {
		const ull MAX = 2e18;
		ull sum = 0;
		forn(k, n) {
			sum += a[i][k] * 1ull * b[k][j];
			if  (sum > MAX) {
				sum %= MOD;
			}
		}
		res[i][j] = sum % MOD;
	}
	forn(i, n) forn(j, n) c[i][j] = res[i][j];
}

void mpow(int a[MAXN][MAXN], int res[MAXN][MAXN], ll p) {
	forn(i, n) forn(j, n) {
		res[i][j] = (i == j);
	}
	for (; p > 0; p /= 2, mult(a, a, a)) {
		if  (p & 1) {
			mult(res, a, res);
		}
	}
}

ll a[MAXN];

bool read() {
	if  (scanf("%d", &n) < 1) {
		return false;
	}
	// n = 100;
	// k = 1e18;
	// forn(i, n) {
	// 	a[i] = 0;
	// }
	// return true;

	cin >> k;
	forn(i, n) {
		cin >> a[i];
	}
	return true;
}

int solve() {
	static int coef[MAXN][MAXN];
	forn(i, n) forn(j, n) {
		coef[i][j] = __builtin_popcountll(a[i] ^ a[j]) % 3 == 0;
	}

	static int res[MAXN][MAXN];
	mpow(coef, res, k - 1);

	int ans = 0;
	forn(i, n) forn(j, n) {
		ans += res[i][j];
		if  (ans >= MOD) ans -= MOD;
	}

	return ans;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		printf("%d\n", solve());
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}