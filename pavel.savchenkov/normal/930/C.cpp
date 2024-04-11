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

int n, m;
vii segs;

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	scanf("%d", &m);
	segs.clear();
	forn(i, n) {
		int l, r;
		scanf("%d%d", &l, &r);
		--l;
		--r;
		segs.pb(mp(l, r));
	}
	return 1;
}

const int INF = 1e9;

vi calc_dp(const vi& a) {
	vi ans_dp(sz(a));

	vi dp(sz(a) + 1, INF);
	dp[0] = -INF;
	forn(i, sz(a)) {
		int pos = upper_bound(all(dp), a[i]) - dp.begin();
		--pos;
		assert(pos >= 0);
		assert(pos < sz(a));
		dp[pos + 1] = min(dp[pos + 1], a[i]);

		ans_dp[i] = pos + 1;
	}

	return ans_dp;
}

void solve() {
	assert(n > 1);

	vi cnt(m + 1);
	for (const auto& seg : segs) {
		int l, r;
		tie(l, r) = seg;
		++cnt[l];
		--cnt[r + 1];
	}
	int s = 0;
	forn(i, m + 1) {
		s += cnt[i];
		cnt[i] = s;
	}
	cnt.pop_back();

	forn(i, m) {
		eprintf("%d ", cnt[i]);
	}
	eprintf("\n");

	vi dp0 = calc_dp(cnt);

	reverse(all(cnt));
	vi dp1 = calc_dp(cnt);
	reverse(all(cnt));
	reverse(all(dp1));

	eprintf("dp0:\n");
	forn(i, sz(dp0)) {
		eprintf("%d ", dp0[i]);
	}
	eprintf("\n");

	eprintf("dp1:\n");
	forn(i, sz(dp0)) {
		eprintf("%d ", dp1[i]);
	}
	eprintf("\n");

	int ans = 1;
	forn(i, m) {
		int cur = dp0[i] + dp1[i] - 1;
		ans = max(ans, cur);
	}
	printf("%d\n", ans);

	eprintf("\n");
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		solve();
	}

#ifdef LOCAL
	eprintf("Time: %.10f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}