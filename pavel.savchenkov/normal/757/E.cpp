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

const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
// const int MAX = 300;

void add(int& x, int y) {
	((x += y) >= MOD) && (x -= MOD);
}

int mul(int x, int y) {
	return x * 1ll * y % MOD;
}

int q;

bool read() {
	if  (scanf("%d", &q) < 1) {
		return 0;
	}
	return 1;
}

bool pr[MAXN];
vi repr[MAXN];

int deg(int x, int p) {
	assert(x);
	int d = 0;
	while (x % p == 0) {
		++d;
		x /= p;
	}
	return d;
}

// vi divs[MAX];
// int coef_div[MAX][MAX];

// const int BASE = 20;

// map<int, int> code2;

// int code(const vi& v) {
// 	int b = 1;
// 	int res = 0;
// 	for (int d : v) {
// 		res += b * d;
// 		b *= BASE;
// 	}
// 	int ans = -1;
// 	if  (!code2.count(res)) {
// 		ans = sz(code2);
// 	} else {
// 		ans = code2[res];
// 	}
// 	code2[res] = ans;
// 	return ans;
// }

// void gen_divs(const vi& v, int i, vi& cur, vvi& res) {
// 	if  (i == sz(v)) {
// 		vi tmp = cur;
// 		sort(all(tmp));
// 		res.pb(tmp);
// 		return;
// 	}

// 	for (int deg = 0; deg <= v[i]; ++deg) {
// 		if  (deg) {
// 			cur.pb(deg);
// 		}
// 		gen_divs(v, i + 1, cur, res);
// 		if (deg) {
// 			cur.pop_back();
// 		}
// 	}
// }

// int prec[MAX][MAXN];

int prec2[22][MAXN];

void precalc() {
	forn(i, MAXN) {
		prec2[1][i] = i + 2;
	}
	for (int deg = 2; deg <= 19; ++deg) {
		int sum = 0;
		forn(i, MAXN) {
			add(sum, prec2[deg - 1][i]);
			prec2[deg][i] = sum;
		}
	}

	memset (pr, 1, sizeof pr);
	for (int i = 2; i < MAXN; ++i) {
		if  (pr[i]) {
			for (int j = i + i; j < MAXN; j += i) {
				pr[j] = 0;
			}

			for (int j = i; j < MAXN; j += i) {
				repr[j].pb(deg(j, i));
			}
		}
	}

	// set<vi> S;
	// for (int i = 1; i < MAXN; ++i) {
	// 	sort(all(repr[i]));
	// 	S.insert(repr[i]);
	// }

	// set<int> S2;
	// for (auto x : S) {
	// 	S2.insert(code(x));
	// 	cerr << code(x) << endl;
	// }
	// assert(sz(S2) == sz(S));

	// cerr << sz(S) << endl;
	// for (auto x : S) {
	// 	for (int y : x) {
	// 		cerr << y << " ";
	// 	}
	// 	cerr << endl;
	// }

	// memset (coef_div, 0, sizeof coef_div);

	// // int sum = 0;
	// for (const auto& v : S) {
	// 	vector<vi> res;
	// 	vi cur;
	// 	gen_divs(v, 0, cur, res);

	// 	int V = code(v);
	// 	for (const auto& d : res) {
	// 		int D = code(d);
	// 		divs[V].pb(D);
	// 		++coef_div[V][D];
	// 	}
	// 	sort(all(divs[V]));
	// 	divs[V].resize(unique(all(divs[V])) - divs[V].begin());

	// 	if  (V == 9) {
	// 		printf("SZ = %d\n", sz(v));
	// 	}
	// 	prec[V][0] = 1 << sz(v);
	// 	// sum += sz(divs[V]);
	// }
	// cerr << "sum = " << sum << endl;

	// int N = sz(code2);

	// for (int it = 0; it < 100; ++it) {
	// 	if  (it) {
	// 		forn(i, N) {
	// 			int res = 0;
	// 			for (int j : divs[i]) {
	// 				add(res, mul(coef_div[i][j], prec[j][it - 1]));
	// 			}
	// 			prec[i][it] = res;
	// 		}
	// 	}

	// 	forn(i, N) {
	// 		if  (i == code(repr[3 * 3 * 3])) {
	// 			printf("prec i=%d, it=%d --> %d\n", i, it, prec[i][it]);
	// 			printf("prec2 = %d\n", prec2[3][it]);
	// 		}
	// 	}

	// 	// if  (it % 10000 == 0) {
	// 	// 	cerr << it << endl;
	// 	// }
	// }

	// {
	// 	for (int n = 1; n <= 100; ++n) {
	// 		int brut = 0;
	// 		for (int p = 1; p <= n; ++p) {
	// 			if  (n % p != 0) {
	// 				continue;
	// 			}
	// 			int q = n / p;
	// 			if  (__gcd(p, q) != 1) {
	// 				continue;
	// 			}
	// 			++brut;
	// 		}

	// 		int my = 1 << sz(repr[n]);

	// 		if  (my != brut) {
	// 			puts("FAIL");
	// 			printf("n=%d, my=%d, brut=%d\n", n, my, brut);
	// 			exit(0);
	// 		} else {
	// 			printf("n=%d, my=%d, brut=%d\n", n, my, brut);
	// 		}
	// 	}
	// }

}

void solve() {
	precalc();

	forn(it, q) {
		int r, n;
		scanf("%d%d", &r, &n);

		int ans = 1;
		for (int v : repr[n]) {
			ans = mul(ans, prec2[v][r]);
		}

		printf("%d\n", ans);
	}
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif


	while (read()) {
		solve();

		break;
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}