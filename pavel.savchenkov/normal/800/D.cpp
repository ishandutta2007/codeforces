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

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;

void add(int& x, int y) {
	((x += y) >= MOD) && (x -= MOD);
}

int mul(int x, int y) {
	assert(0 <= x && x < MOD);
	assert(0 <= y && y < MOD);
	return x * 1ll * y % MOD;
}

int n;
int cnt[MAXN];

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	memset (cnt, 0, sizeof cnt);
	forn(i, n) {
		int a;
		scanf("%d", &a);
		++cnt[a];
	}
	return 1;
}

vi repr[MAXN];
int pow2[MAXN];
ll pow10[10];

int len_num(int x) {
	// printf("x=%d --> %d\n", x, sz(repr[x]));
	return sz(repr[x]);
}

void precalc() {
	forn(i, MAXN) {
		int x = i;
		forn(it, 6) {
			repr[i].pb(x % 10);
			x /= 10;
		}
	}

	pow2[0] = 1;
	for (int i = 1; i < MAXN; ++i) {
		pow2[i] = mul(2, pow2[i - 1]);
	}

	pow10[0] = 1;
	for (int i = 1; i < 10; ++i) {
		pow10[i] = pow10[i - 1] * 10;
	}
}

int pop(int mask) {
	return __builtin_popcount(mask);
}

bool bit(int mask, int i) {
	return (mask & (1 << i));
}

int sum_up[MAXN];
int sum_sq_up[MAXN];
int all_ans[MAXN];
int ans[MAXN];
int cnt_up[MAXN];

void calc() {
	const int len = 6;
	ford(x, 1e6) {
		sum_up[x] = mul(x, cnt[x]);
		sum_sq_up[x] = mul(mul(x, x), cnt[x]);
		cnt_up[x] = cnt[x];
		forn(mask, 1 << len) {
			if  (!mask) {
				continue;
			}
			int nx = x;
			bool bad = 0;
			forn(i, len) {
				if  (bit(mask, i)) {
					if  (repr[x][i] == 9) {
						bad = 1;
						break;
					}
					nx += pow10[i];
				}
			}
			if  (bad) {
				continue;
			}
			assert(nx < 1e6);
			int sign = pop(mask) & 1;
			add(sum_up[x], sign ? sum_up[nx] : -sum_up[nx] + MOD);
			add(sum_sq_up[x], sign ? sum_sq_up[nx] : -sum_sq_up[nx] + MOD);
			add(cnt_up[x], sign ? cnt_up[nx] : -cnt_up[nx] + MOD);
		}


		all_ans[x] = 0;
		if  (cnt_up[x]) {
			add(all_ans[x], mul(sum_sq_up[x], pow2[cnt_up[x] - 1]));
			if  (cnt_up[x] >= 2) {
				int sq = mul(sum_up[x], sum_up[x]);
				add(sq, -sum_sq_up[x] + MOD);
				add(all_ans[x], mul(sq, pow2[cnt_up[x] - 2]));
			}
		}

		int X = 0;
		forn(mask, 1 << len) {
			if  (!mask) {
				continue;
			}
			int nx = x;
			bool bad = 0;
			forn(i, len) {
				if  (bit(mask, i)) {
					if  (repr[x][i] == 9) {
						bad = 1;
						break;
					}
					nx += pow10[i];
				}
			}
			if  (bad) {
				continue;
			}
			assert(nx < 1e6);
			int sign = pop(mask) & 1;
			add(X, sign ? all_ans[nx] : -all_ans[nx] + MOD);
		}

		ans[x] = all_ans[x];
		add(ans[x], -X + MOD);

		// if  (ans[x]) {
		// 	printf("x=%d, ans=%d, G=%lld,  sum_up=%d, sum_sq_up=%d, all_ans=%d, cnt_up=%d\n", x, ans[x], x * 1ll * ans[x], sum_up[x], sum_sq_up[x], all_ans[x], cnt_up[x]);
		// }
	}
}

void solve() {
	calc();

	ull res = 0;
	forn(x, 1e6) {
		ull G = x * 1ull * ans[x];
		res ^= G;
	}

	cout << res << endl;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	precalc();

	while (read()) {
		solve();
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}