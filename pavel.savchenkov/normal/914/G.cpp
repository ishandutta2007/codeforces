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

const ll MOD = 1e9 + 7;
const ll MAX = MOD * MOD;

void add(ll& x, ll y) {
	((x += y) >= MOD) && (x -= MOD);
}

void fast_add(ll& x, ll y) {
	x += y;
	while  (x >= MAX) {
		x -= MAX;
	}
}

ll mul(ll x, ll y) {
	return x * 1ll * y % MOD;
}

const int BITS = 17;
const int Full = (1 << BITS) - 1;

ll cnt[1 << BITS];

bool read() {
	int n;
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	memset (cnt, 0, sizeof cnt);
	forn(i, n) {
		int x;
		scanf("%d", &x);
		++cnt[x];
	}
	return 1;
}

void div2(ll& x) {
	if  (x % 2 == 0) {
		x /= 2;
	} else {
		x += MOD;
		assert(x % 2 == 0);
		x /= 2;
		x %= MOD;
	}
}

void had(vll& a, int l, int r, bool rev) {
	if  (l == r) {
		return;
	}

	// eprintf("l=%d, r=%d\n", l, r);

	const int m = (l + r) / 2;
	const int len = (r - l + 1);
	if  (!rev) {
		had(a, l, m, false);
		had(a, m + 1, r, false);
		forn(k, len / 2) {
			int nk = len / 2 + k;
			ll x = a[l + k];
			ll y = a[l + nk];

			a[l + k] = (x + y) % MOD;
			a[l + nk] = (x - y + MOD) % MOD;

			// tie(a[k], a[nk]) = mp(a[k] + a[nk], a[k] - a[nk]);
		}
	} else {
		forn(k, len / 2) {
			int nk = len / 2 + k;
			ll x = a[l + k];
			ll y = a[l + nk];

			a[l + k] = (x + y) % MOD;
			div2(a[l + k]);

			a[l + nk] = (x - y % MOD + MOD) % MOD;
			div2(a[l + nk]);

			// tie(a[k], a[nk]) = mp((a[k] + a[nk]) / 2, (a[k] - a[nk]) / 2);
		}
		had(a, l, m, true);
		had(a, m + 1, r, true);
	}
}

bool is_pw2(int n) {
	return n > 0 && (n & (n - 1)) == 0;
}

vll had_mult(vll a) {
	// {
	// 	vll ans(sz(a), 0);
	// 	forn(i, sz(a)) {
	// 		if  (!a[i]) {
	// 			continue;
	// 		}
	// 		forn(j, sz(a)) {
	// 			ans[i ^ j] += a[i] * a[j];
	// 		}
	// 	}
	// 	return ans;
	// }

	assert(is_pw2(sz(a)));

	// vll was = a;

	had(a, 0, sz(a) - 1, false);
	forn(i, sz(a)) {
		a[i] %= MOD;
		a[i] = (a[i] * a[i]) % MOD;
	}
	had(a, 0, sz(a) - 1, true);

	// assert(was == a);
	// assert(0);

	return a;
}

ll cntA[1 << BITS];
ll cntB[1 << BITS];
ll cntC[1 << BITS];
ll f[1 << BITS];
ll sumA[1 << BITS];
ll sumB[1 << BITS];
ll sumC[1 << BITS];

void calc_sum(ll coef[1 << BITS], ll sum[1 << BITS]) {
	forn(i, 1 << BITS) {
		sum[i] = 0;
	}
	forn(mask, 1 << BITS) {
		ll cur = (coef[mask] % MOD) * f[mask];
		cur %= MOD;
		if  (!cur) {
			continue;
		}
		// eprintf("mask=%d, cur=%lld\n", mask, cur);
		for (int sub = mask; ; sub = (sub - 1) & mask) {
			sum[sub] += cur;
			if  (!sub) {
				break;
			}
		}
	}
	forn(mask, 1 << BITS) {
		sum[mask] %= MOD;
	}
}

void precalc() {
	f[0] = 0;
	f[1] = 1;
	for (int i = 2; i < (1 << BITS); ++i) {
		f[i] = f[i - 2];
		add(f[i], f[i - 1]);

		// if  (i < 10) {
		// 	eprintf("f[%d] = %d\n", i, int(f[i]));
		// }
	}
}

ll solve() {
	memset (cntA, 0, sizeof cntA);
	memset (cntB, 0, sizeof cntB);
	memset (cntC, 0, sizeof cntC);

	{
		forn(a, 1 << BITS) {
			int na = ~a & Full;
			for (int b = na; ; b = (b - 1) & na) {
				assert((a & b) == 0);
				cntA[a | b] += cnt[a] * cnt[b];
				if (!b) {
					break;
				}
			}
		}
		forn(A, 1 << BITS) {
			cntA[A] %= MOD;
		}
	}

	forn(c, 1<< BITS) {
		cntB[c] = cnt[c];
	}

	{
		vll cur = had_mult(vll(cnt, cnt + (1 << BITS)));
		forn(C, 1 << BITS) {
			cntC[C] = cur[C];
		}
	}

	// eprintf("cntA:\n");
	// forn(mask, 1 << BITS) {
	// 	if  (!cntA[mask]) {
	// 		continue;
	// 	}
	// 	cout << bitset<16>(mask) << " : " << cntA[mask] << endl;
	// }

	// eprintf("cntB:\n");
	// forn(mask, 1 << BITS) {
	// 	if  (!cntB[mask]) {
	// 		continue;
	// 	}
	// 	cout << bitset<16>(mask) << " : " << cntB[mask] << endl;
	// }

	// eprintf("cntC:\n");
	// forn(mask, 1 << BITS) {
	// 	if  (!cntC[mask]) {
	// 		continue;
	// 	}
	// 	cout << bitset<16>(mask) << " : " << cntC[mask] << endl;
	// }

	calc_sum(cntA, sumA);
	calc_sum(cntB, sumB);
	calc_sum(cntC, sumC);

	// eprintf("sumA:\n");
	// forn(mask, 1 << BITS) {
	// 	if  (!sumA[mask]) {
	// 		continue;
	// 	}
	// 	cout << bitset<16>(mask) << " : " << sumA[mask] << endl;
	// }

	// eprintf("sumB:\n");
	// forn(mask, 1 << BITS) {
	// 	if  (!sumB[mask]) {
	// 		continue;
	// 	}
	// 	cout << bitset<16>(mask) << " : " << sumB[mask] << endl;
	// }

	// eprintf("sumC:\n");
	// forn(mask, 1 << BITS) {
	// 	if  (!sumC[mask]) {
	// 		continue;
	// 	}
	// 	cout << bitset<16>(mask) << " : " << sumC[mask] << endl;
	// }

	static ll ans[1 << BITS];
	memset (ans, 0, sizeof ans);
	forn(all, 1 << BITS) {
		ll coef = sumA[all] * sumB[all];
		coef %= MOD;
		coef *= sumC[all];
		coef %= MOD;
		ans[all] = coef;
	}

	// eprintf("ans before:\n");
	// forn(mask, 1 << BITS) {
	// 	if  (!ans[mask]) {
	// 		continue;
	// 	}
	// 	cout << bitset<16>(mask) << " : " << ans[mask] << endl;
	// }

	ford(mask, 1 << BITS) {
		int nmask = ~mask & Full;
		ll bad = 0;
		for (int up = nmask; up; up = (up - 1) & nmask) {
			bad += ans[up | mask];
			while (bad >= MOD) {
				bad -= MOD;
			}
		}
		ans[mask] = (ans[mask] - bad + MOD) % MOD;
	}

	// eprintf("ans after:\n");
	// forn(mask, 1 << BITS) {
	// 	if  (!ans[mask]) {
	// 		continue;
	// 	}
	// 	cout << bitset<16>(mask) << " : " << ans[mask] << endl;
	// }

	ll answer = 0;
	forn(mask, 1 << BITS) {
		if  (!is_pw2(mask)) {
			continue;
		}
		answer += ans[mask];
		answer %= MOD;
	}

	return answer;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	precalc();

	while (read()) {
		cout << solve() << endl;

		break;
	}

#ifdef LOCAL
	eprintf("Time: %.10f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}