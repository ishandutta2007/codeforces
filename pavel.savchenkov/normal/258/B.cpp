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
	const int y = mpow(x, MOD - 2);
	assert(mul(x, y) == 1);
	return y;
}

int m;

bool read() {
	if  (scanf("%d", &m) < 1) {
		return 0;
	}
	return 1;
}

const int L = 12;

vi repr(int x) {
	vi res;
	forn(it, L) {
		res.pb(x % 10);
		x /= 10;
	}
	reverse(all(res));
	return res;
}

int calc_A(int n, int k) {
	if  (k > n) {
		return 0;
	}
	int ans = 1;
	forn(i, k) {
		ans = mul(ans, n - i);
	}
	return ans;
}

int calc_C(int n, int k) {
	if  (k > n) {
		return 0;
	}
	if  (n - k < k) {
		return calc_C(n, n - k);
	}
	int ans = 1;
	forn(i, k) {
		ans = mul(ans, n - i);
		ans = mul(ans, inv(i + 1));
	}
	return ans;
}

int solve() {
	vector<vvi> dp(L + 1, vvi(2, vi(L + 1, 0)));

	vi M = repr(m);
	dp[0][0][0] = 1;
	forn(i, sz(M)) forn(ls, 2) forn(cnt, L + 1) {
		const int cur_dp = dp[i][ls][cnt];
		if  (!cur_dp) {
			continue;
		}
		if  (i == sz(M)) {
			continue;
		}
		forn(d, 10) {
			if  (!ls && d > M[i]) {
				continue;
			}
			int nls = ls || d < M[i];
			int ncnt = cnt + (d == 4 || d == 7);
			add(dp[i + 1][nls][ncnt], cur_dp);
		}
	}

	vi cnt_with(L + 1, 0);
	forn(ls, 2) forn(cnt, L + 1) {
		add(cnt_with[cnt], dp[sz(M)][ls][cnt]);
	}
	--cnt_with[0];

	const int C = 7;
	int ans = 0;
	vvi dp2(C, vi(L + 1, 0));
	dp2[0][0] = 1;
	forn(cnt, sz(cnt_with)) {
		int was = 0;
		forn(sum, cnt) {
			add(was, dp2[C - 1][sum]);
		}
		add(ans, mul(cnt_with[cnt], was));

		vvi ndp2(C, vi(L + 1, 0));
		forn(used, C) forn(sum, L + 1) {
			const int cur_dp = dp2[used][sum];
			if  (!cur_dp) {
				continue;
			}
			for (int take = 0; take <= cnt_with[cnt] && used + take < C && sum + take * cnt <= L; ++take) {
				add(ndp2[used + take][sum + take * cnt], mul(cur_dp, mul(calc_C(used + take, take), calc_A(cnt_with[cnt], take))));
			}
		}
		dp2.swap(ndp2);
	}
	return ans;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		cout << solve() << endl;
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}