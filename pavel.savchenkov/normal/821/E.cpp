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

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define FILE_NAME "a"

const int MOD = 1e9 + 7;

void add(int& x, int y) {
	((x += y) >= MOD) && (x -= MOD);
}

int mul(int x, int y) {
	return x * 1ll * y % MOD;
}

int n;
ll k;
vll a;
vll b;
vi c;

bool read() {
	if  (scanf("%d%lld", &n, &k) < 2) {
		return 0;
	}
	a.resize(n);
	b.resize(n);
	c.resize(n);
	forn(i, n) {
		scanf("%lld%lld%d", &a[i], &b[i], &c[i]);
	}
	b.back() = k;
	return 1;
}

struct Matr {
	vvi a;

	Matr(int n = 0) {
		a.assign(n, vi(n, 0));
	}

	Matr& operator *= (const Matr& other) {
		const int n = sz(a);
		vvi c(n, vi(n, 0));
		forn(i, n) forn(j, n) {
			const ull MAX = MOD * 1ull * MOD;
			ull ans = 0;
			forn(k, n) {
				ans += a[i][k] * 1ull * other.a[k][j];
				while (ans >= MAX) {
					ans -= MAX;
				}
			}
			c[i][j] = ans % MOD;
		}
		a.swap(c);
		return *this;
	}
};

const int MAXC = 15;
Matr trans[MAXC + 1];

void precalc() {
	for (int c = 0; c <= MAXC; ++c) {
		Matr cur(MAXC + 1);
		for (int i = 0; i <= c; ++i) {
			cur.a[i][i] = 1;
			if  (i > 0) {
				cur.a[i][i - 1] = 1;
			}
			if  (i + 1 <= c) {
				cur.a[i][i + 1] = 1;
			}
		}
		trans[c] = cur;
	}
}

Matr mpow(Matr a, ll p) {
	Matr res(sz(a.a));
	forn(i, sz(a.a)) {
		res.a[i][i] = 1;
	}
	for (; p > 0; a *= a, p >>= 1) {
		if  (p & 1) {
			res *= a;
		}
	}
	return res;
}

int solve() {
	vi dp(MAXC + 1, 0);
	dp[0] = 1;
	forn(i, n) {
		Matr matr = mpow(trans[c[i]], b[i] - a[i]);
		int bound = c[i];
		if  (i + 1 < n) {
			bound = min(bound, c[i + 1]);
		}

		vi ndp(MAXC + 1, 0);
		for (int j = 0; j <= bound; ++j) {
			int& ans = ndp[j];
			for (int z = 0; z <= MAXC; ++z) {
				add(ans, mul(dp[z], matr.a[j][z]));
			}
		}

		dp.swap(ndp);
	}

	return dp[0];
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	precalc();

	while (read()) {
		printf("%d\n", solve());
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}