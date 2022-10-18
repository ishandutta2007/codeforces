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

#define TEST 0

const int MOD = 1e9 + 7;

void add(int& x, int y) {
	((x += y) >= MOD) && (x -= MOD);
}

int mul(int x, int y) {
	return x * 1ll * y % MOD;
}

int mpow(int a, int p) {
	int res = 1;
	for (; p > 0; p >>= 1, a = mul(a, a)) {
		if  (p & 1) {
			res = mul(res, a);
		}
	}
	return res;
}

int inv(int x) {
	int y = mpow(x, MOD - 2);
	assert(mul(x, y) == 1);
	return y;
}

vi X;

bool read() {
#if !TEST
	string s;
	if  (!getline(cin, s)) {
		return 0;
	}
	X.resize(sz(s));
	forn(i, sz(s)) {
		X[i] = s[i] - '0';
	}
#else
	int n = 700;
	X.resize(n);
	forn(i, n) {
		X[i] = rand() % 10;
	}
	if (X[0] == 0) {
		++X[0];
	}
#endif
	return 1;
}

const int MAXN = 700 + 10;
const int A = 10;

int fact[2 * MAXN];
int inv_fact[2 * MAXN];

int binom(int n, int k) {
	if  (n < k || n < 0 || k < 0) {
		return 0;
	}
	return mul(fact[n], mul(inv_fact[n - k], inv_fact[k]));
}

int mem[A][MAXN][MAXN];
int mem_pow[A + 1][MAXN];
int mem_pow_inv[A + 1][MAXN];

void precalc() {
	fact[0] = 1;
	for (int i = 1; i < 2 * MAXN; ++i) {
		fact[i] = mul(fact[i - 1], i);
	}

	forn(i, 2 * MAXN) {
		inv_fact[i] = inv(fact[i]);
	}

	forn(d, A + 1) {
		forn(p, MAXN) {
			mem_pow[d][p] = mpow(d, p);
			if  (d > 0) {
				mem_pow_inv[d][p] = inv(mem_pow[d][p]);
			}
		}
	}

	memset (mem, 0, sizeof mem);
	forn(d, A) {
		forn(r, MAXN) {
			forn(c, MAXN) {
				int cur = binom(r, c);
				if  (cur) {
					cur = mul(cur, mem_pow[d][c]);
					cur = mul(cur, mem_pow_inv[A - d][c]);
				}

				mem[d][r][c] = cur;

				if  (c > 0) {
					add(mem[d][r][c], mem[d][r][c - 1]);
				}
			}
		}
	}
}

int len_num(int x) {
	int len = 0;
	while (x) {
		x /= A;
		++len;
	}
	return max(1, len);
}

int func(int x) {
	vi digs;
	while (x) {
		digs.pb(x % A);
		x /= A;
	}
	sort(all(digs));
	
	int ans = 0;
	forn(i, sz(digs)) {
		ans = ans * A + digs[i];
	}
	return ans;
}

int brut() {
	int x = 0;
	forn(i, sz(X)) {
		x = x * A + X[i];
	}

	int ans = 0;
	forn(i, x + 1) {
		ans += func(i);
	}
	return ans;
}

int calc(const vi& seen) {
	const int len = sz(X);

	int rest_len = len;
	forn(d, A) {
		rest_len -= seen[d];
	}

	// eprintf("len = %d\n", len);
	// eprintf("seen:\n");
	// forn(d, A) {
	// 	eprintf("%d:%d\n", d, seen[d]);
	// }
	// eprintf("\n");

	vi seen_less(A);
	vi seen_not_less(A);
	forn(d, A) {
		forn(nd, d) {
			seen_less[d] += seen[nd];
		}
		for (int nd = d; nd < A; ++nd) {
			seen_not_less[d] += seen[nd];
		}
	}

	int ans = 0;
	forn(pos, len) {
		vi at_least(A);

		forn(d, A) {
			// forn(cnt_less, pos + 1) {
			// 	int actual_cnt_less = cnt_less;
			// 	forn(nd, d) {
			// 		actual_cnt_less -= seen[nd];
			// 	}

			// 	if  (actual_cnt_less < 0) {
			// 		continue;
			// 	}

			// 	int cnt_not_less = len - cnt_less;
			// 	int actual_cnt_not_less = cnt_not_less;
			// 	for (int nd = d; nd < A; ++nd) {
			// 		actual_cnt_not_less -= seen[nd];
			// 	}

			// 	if  (actual_cnt_not_less < 0) {
			// 		continue;
			// 	}

			// 	int coef = binom(rest_len, actual_cnt_less);
			// 	coef = mul(coef, mpow(d, actual_cnt_less));
			// 	coef = mul(coef, mpow(A - d, actual_cnt_not_less));

			// 	add(at_least[d], coef);
			// }	

			{
				const int upper = pos - seen_less[d];
				if  (upper < 0) {
					continue;
				}

				int cur = mem[d][rest_len][upper];
				cur = mul(cur, mem_pow[A - d][len - seen_less[d] - seen_not_less[d]]);
				// cur = mul(cur, mpow(A - d, len - seen_less[d] - seen_not_less[d]));

				// int brut_cur = 0;
				// for (int c = 0; c <= pos - seen_less[d]; ++c) {
				// 	int val = binom(rest_len, c);
				// 	val = mul(val, mpow(d, c));

				// 	int Ad = mpow(A - d, c);
				// 	Ad = inv(Ad);
				// 	val = mul(val, Ad);

				// 	add(brut_cur, val);
				// }
				// brut_cur = mul(brut_cur, mpow(A - d, len - seen_less[d] - seen_not_less[d]));

				add(at_least[d], cur);
			}
		}

		// eprintf("pos=%d, at_least:\n", pos);
		// forn(d, A) {
		// 	eprintf("%d: %d\n", d, at_least[d]);
		// }
		// eprintf("\n");

		// eprintf("pos=%d\n", pos);
		const int pos_coef = mpow(10, len - pos - 1);
		ford(d, A) {
			int cur = at_least[d];
			if  (d + 1 < A) {
				add(cur, -at_least[d + 1] + MOD);
			}

			// eprintf("d=%d, cur=%d\n", d, cur);
			add(ans, mul(pos_coef, mul(d, cur)));
		}
		// eprintf("\n");
	}

	return ans;
}

int solve() {
	vi seen(A);

	int ans = 0;
	forn(i, sz(X)) {
		forn(cur, X[i]) {
			++seen[cur];
			add(ans, calc(seen));
			--seen[cur];
		}
		++seen[X[i]];
	}

	add(ans, calc(seen));

	return ans;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	precalc();

	while (read()) {
		// printf("brut = %d\n", brut());

		printf("%d\n", solve());

		break;
	}

#ifdef LOCAL
	eprintf("Time: %.10f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}