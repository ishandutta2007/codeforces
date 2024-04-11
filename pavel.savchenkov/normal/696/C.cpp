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


const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;

void add(int& x, int y) {
	((x += y) >= MOD) && (x -= MOD);
}

int mult(int x, int y) {
	return x * 1ll * y % MOD;
}

void mult(int a[2][2], int b[2][2], int c[2][2]) {
	static int res[2][2];
	forn(i, 2) forn(j, 2) {
		res[i][j] = 0;
		forn(k, 2) {
			add(res[i][j], mult(a[i][k], b[k][j]));
		}
	}
	forn(i, 2) forn(j, 2) c[i][j] = res[i][j];
}

int mpow(int a, ll p) {
	int res = 1;
	for (; p > 0; p /= 2, a = mult(a, a)) {
		if  (p & 1) {
			res = mult(res, a);
		}
	}
	return res;
}

void mpow(int a[2][2], int res[2][2], ll p) {
	static int c[2][2];
	forn(i, 2) forn(j, 2) c[i][j] = (i == j);
	for (; p > 0; mult(a, a, a), p /= 2) {
		if  (p & 1) {
			mult(c, a, c);
		}
	}
	forn(i, 2) forn(j, 2) res[i][j] = c[i][j];
}

int inv(int x) {
	int y = mpow(x, MOD - 2);
	assert(mult(x, y) == 1);
	return y;
}

vll vals;

bool read() {
	int k;
	if  (scanf("%d", &k) < 1) {
		return false;
	}
	vals.resize(k);
	forn(i, k) {
		scanf("%lld", &vals[i]);
	}
	return true;
}

void solve() {
	static int c[2][2];
	c[0][1] = 2;
	c[1][0] = 1;
	c[0][0] = 1;

	for (auto p : vals) {
		mpow(c, c, p);
	}

	// forn(i, 2) {
	// 	forn(j, 2) {
	// 		printf("%d ", c[i][j]);
	// 	}
	// 	puts("");
	// }
	// puts("");

	int good = c[1][1];
	good = mult(good, inv(2));

	int all = 2;
	for (auto p : vals) {
		all = mpow(all, p);
	}
	all = mult(all, inv(2));

	printf("%d/%d\n", good, all);
}

// int a[2][2];
// int cur[2][2];

// int get(int x, int p) {
// 	int cnt = 0;
// 	while (x % p == 0 && x > 0) {
// 		++cnt;
// 		x /= p;
// 	}
// 	return cnt;
// }

// void print() {
// 	forn(i, 2) {
// 		forn(j, 2) {
// 			printf("%d ", cur[i][j]);
// 		}
// 		puts("");
// 	}
// 	printf("PW2 = %d\n", get(cur[1][1], 2));
// 	puts("");
// }

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		solve();
	}

	// memset (a, 0, sizeof a);
	// a[0][1] = 2;
	// a[1][0] = 1;
	// a[0][0] = 1;
	// forn(i, 2) forn(j, 2) cur[i][j] = i == j;

	// forn(it, 20) {
	// 	printf("pw = %d\n", it);
	// 	print();
	// 	mult(cur, a, cur);
	// }


#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}