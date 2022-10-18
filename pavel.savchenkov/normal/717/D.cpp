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

const int MAXN = 1e5 + 10;

struct matr {
	vector<vector<ld>> a;

	matr(int n = 0) {
		a.assign(n, vector<ld>(n, 0));
	}
};

matr operator * (const matr& x, const matr& y) {
	const int n = sz(x.a);
	matr res(n);
	assert(sz(x.a) == n);
	assert(sz(y.a) == n);
	forn(i, n) forn(j, n) {
		forn(k, n) { 
			res.a[i][j] += x.a[i][k] * y.a[k][j];
		}
	}
	return res;
}

matr mpow(matr a, int p) {
	const int n = sz(a.a);
	matr res(n);
	forn(i, n) res.a[i][i] = 1.0;
	for (; p > 0; p >>= 1, a = a * a) {
		if  (p & 1) {
			res = res * a;
		}
	}
	return res;
}

ld p[MAXN];
int n, x;

bool read() {
	if  (scanf("%d%d", &n, &x) < 2) {
		return false;
	}
	forn(i, x + 1) {
		double pp;
		scanf("%lf", &pp);
		p[i] = pp;
	}
	return true;
}

ld solve() {
	// x = 100;
	// n = (int) 1e9;
	
	int b = 0;
	while ((1 << b) <= x) ++b;
	matr t(1 << b);
	forn(was, 1 << b) forn(val, x + 1) {
		assert((val ^ was) < sz(t.a));
		t.a[val ^ was][was] += p[val];
	}
	t = mpow(t, n);
	return 1.0 - t.a[0][0];
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
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}