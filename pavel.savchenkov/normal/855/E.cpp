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

int q;

bool read() {
	if  (scanf("%d", &q) < 1) {
		return 0;
	}
	return 1;
}

const int MAXB = 11;
const int MAXLEN = 80;

ll dp[MAXB + 1][MAXLEN][1 << MAXB];

void precalc() {
	memset (dp, 0, sizeof dp);
	for (int b = 2; b <= 10; ++b) {
		dp[b][0][0] = 1;

		forn(len, MAXLEN - 1) {
			forn(mask, 1 << b) {
				const ll cur_dp = dp[b][len][mask];
				if  (!cur_dp) {
					continue;
				}

				forn(nxt, b) {
					const int nmask = mask ^ (1 << nxt);
					dp[b][len + 1][nmask] += cur_dp;
				}
			}
		}
	}
}

ll ask(int b, ll r) {
	if  (r <= 0) {
		return 0;
	}

	++r;

	vi rr;
	ll tmp = r;
	while (tmp) {
		rr.pb(tmp % b);
		tmp /= b;
	}
	assert(!rr.empty());

	reverse(all(rr));

	ll ans = 0;
	int mask = 0;
	forn(i, sz(rr)) {
		forn(who, rr[i]) {
			if  (i == 0 && who == 0) {
				continue;
			}
			int cur_mask = mask ^ (1 << who);
			ans += dp[b][sz(rr) - i - 1][cur_mask];
		}
		mask ^= 1 << rr[i];
	}

	for (int i = 1; i < sz(rr); ++i) {
		for (int who = 1; who < b; ++who) {
			ans += dp[b][sz(rr) - i - 1][1 << who];
		}
	}

	// eprintf("r = %lld, b = %d, ans = %lld\n", r, b, ans);
	// eprintf("rr:\n");
	// forn(i, sz(rr)) {
	// 	eprintf("%d ", rr[i]);
	// }
	// eprintf("\n");

	return ans;
}

ll ask(int b, ll l, ll r) {
	return ask(b, r) - ask(b, l - 1);
}

void solve() {
	forn(it, q) {
		int b;
		ll l, r;
		scanf("%d%lld%lld", &b, &l, &r);

		printf("%lld\n", ask(b, l, r));
	}
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	precalc();

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