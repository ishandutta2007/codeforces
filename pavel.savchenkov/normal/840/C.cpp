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
const int MOD2 = 1e9 + 9;

void add(int& x, int y, int m) {
	((x += y) >= m) && (x -= m);
}

int mul(int x, int y, int m) {
	return x * 1ll * y % m;
}

int mpow(int a, int p, int m) {
	int res = 1;
	for (; p > 0; p >>= 1, a = mul(a, a, m)) {
		if  (p & 1) {
			res = mul(res, a, m);
		}
	}
	return res;
}

int inv(int x, int m) {
	int y = mpow(x, m - 2, m);
	assert(mul(x, y, m) == 1);
	return y;
}

int n;
vi a;

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	a.resize(n);
	forn(i, n) {
		scanf("%d", &a[i]);
	}
	return 1;
}

pii repr(int x) {
	vii ps;
	for (int y = 2; y * y <= x; ++y) {
		if  (x % y == 0) {
			int a = 1;
			x /= y;
			while (x % y == 0) {
				++a;
				x /= y;
			}
			ps.pb(mp(y, a));
		}
	}
	if  (x > 1) {
		ps.pb(mp(x, 1));
	}

	pii hs(1, 1);
	for (const auto& p : ps) {
		if  (p.snd & 1) {
			hs.fst = mul(hs.fst, p.fst, MOD);
			hs.snd = mul(hs.snd, p.fst, MOD2);
		}
	}
	return hs;
}

const int MAXN = 300 + 10;

int fact[2 * MAXN];
int inv_fact[2 * MAXN];
int mem_pow[MAXN][MAXN];
int D[MAXN][MAXN];

int binom(int n, int k) {
	if  (n < k) {
		return 0;
	}
	return mul(fact[n], mul(inv_fact[n - k], inv_fact[k], MOD), MOD);
}

int binom2(int n, int k) {
	return binom(n + k - 1, k);
}

void precalc() {
	fact[0] = 1;
	for (int i = 1; i < 2 * MAXN; ++i) {
		fact[i] = mul(fact[i - 1], i, MOD);
	}

	forn(i, 2 * MAXN) {
		inv_fact[i] = inv(fact[i], MOD);
	}

	forn(i, MAXN) {
		forn(j, MAXN) {
			mem_pow[i][j] = mpow(i, j, MOD);
		}
	}

	for (int c = 1; c < MAXN; ++c) {
		for (int b = 1; b <= c; ++b) {
			D[c][b] = mul(fact[c], binom(c - 1, b - 1), MOD);

			if  (c <= 3) {
				eprintf("D[c=%d][b=%d] = %d\n", c, b, D[c][b]);
			}
		}
	}
}

int solve() {
	map<pii, int> cnt;
	for (auto x : a) {
		++cnt[repr(x)];
	}

	vi cs;
	for (const auto& it : cnt) {
		cs.pb(it.snd);
	}

	sort(all(cs));

	// for (const auto& c : cs) {
	// 	eprintf("c = %d\n", c);
	// }

	int have = 0;
	vi dp(1, 1);
	for (const auto& c : cs) {
		const int places = have + 1;
		vi ndp(have + c + 1, 0);
		forn(eq, sz(dp)) {
			const int coef = dp[eq];
			if  (!coef) {
				continue;
			}
			for (int blocks = 0; blocks <= c; ++blocks) {
				for (int in_eq = 0; in_eq <= blocks && in_eq <= eq; ++in_eq) {
					int cur = coef;
					cur = mul(cur, D[c][blocks], MOD);
					cur = mul(cur, binom(eq, in_eq), MOD);
					cur = mul(cur, binom(places - eq, blocks - in_eq), MOD);
					add(ndp[(eq - in_eq) + (c - 1 - blocks + 1)], cur, MOD);
				}
			}
		}

		have += c;
		dp.swap(ndp);

		// forn(i, sz(dp)) {
		// 	eprintf("dp[%d] = %d\n", i, dp[i]);
		// }
		// eprintf("---\n");
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