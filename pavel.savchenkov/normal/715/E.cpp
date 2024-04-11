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

const int MAXN = 250 + 10;
const int MOD = 998244353;

void add(int& x, int y) {
	((x += y) >= MOD) && (x -= MOD);
}

int mul(int x, int y) {
	return x * 1ll * y % MOD;
}

int n;
int p[MAXN];
int q[MAXN];

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	forn(i, n) {
		scanf("%d", &p[i]);
		--p[i];
	}
	forn(i, n) {
		scanf("%d", &q[i]);
		--q[i];
	}
	return 1;
}

int to[MAXN];
int from[MAXN];

bool used[MAXN];
bool was_from[MAXN];
bool was_to[MAXN];

vi solve_4(const vi& cnt) {
	vi who;
	forn(i, sz(cnt)) {
		forn(j, cnt[i]) {
			who.pb(i);
		}
	}

	const int N = sz(who);
	int cnt_from = 0;
	int cnt_to = 0;
	vvi dp(N + 1, vi(N + 1, 0)); // (bad_edges, cycles)
	dp[0][0] = 1; 
	forn(i, sz(who)) {
		int t = who[i];
		vvi ndp(N + 1, vi(N + 1, 0));

		forn(bad, N + 1) forn(cycles, N + 1) {
			int cur_dp = dp[bad][cycles];
			if  (!cur_dp) {
				continue;
			}
			// printf("i=%d, bad=%d, cycles=%d -> %d\n", i, bad, cycles, cur_dp);

			int TO = cnt_to - bad; 
			assert(TO >= 0);
			int FROM = cnt_from - bad;
			assert(FROM >= 0);
			int OK = i - TO - FROM - bad;
			assert(OK >= 0);
			if  (t == 3) {
				// to bad
				add(ndp[bad + 1][cycles], mul(cur_dp, bad));

				// to TO
				add(ndp[bad + 1][cycles], mul(cur_dp, TO));

				// to FROM
				add(ndp[bad + 1][cycles], mul(cur_dp, FROM));

				// alone
				add(ndp[bad + 1][cycles + 1], cur_dp);
			} else if (t == 2) {
				// to bad
				add(ndp[bad][cycles], mul(cur_dp, bad));

				// to TO
				add(ndp[bad][cycles], mul(cur_dp, TO));

				// to FROM
				add(ndp[bad + 1][cycles], mul(cur_dp, FROM));

				// alone
				add(ndp[bad][cycles + 1], cur_dp);
			} else if  (t == 1) {
				// to bad
				add(ndp[bad][cycles], mul(cur_dp, bad));

				// to TO
				add(ndp[bad + 1][cycles], mul(cur_dp, TO));

				// to FROM
				add(ndp[bad][cycles], mul(cur_dp, FROM));

				// alone
				add(ndp[bad][cycles + 1], cur_dp);		
			} else {
				assert(t == 0);

				// to bad
				if  (bad) {
					add(ndp[bad - 1][cycles], mul(cur_dp, bad));
				}

				// to TO
				add(ndp[bad][cycles], mul(cur_dp, TO));

				// to FROM
				add(ndp[bad][cycles], mul(cur_dp, FROM));

				// alone
				add(ndp[bad][cycles + 1], cur_dp);					
			}

			// to OK
			add(ndp[bad][cycles], mul(cur_dp, OK));
		}

		dp.swap(ndp);
		if  (t == 3) {
			++cnt_from;
			++cnt_to;
		}
		if  (t == 2) {
			++cnt_to;
		}
		if  (t == 1) {
			++cnt_from;
		}
	}

	// forn(bad, N + 1) forn(c, N + 1) {
	// 	if  (dp[bad][c]) {
	// 		printf("i=end, bad=%d, cycles=%d -> %d\n", bad, c, dp[bad][c]);
	// 	}
	// }

	return dp[0];
}

vi solve_cycles() {
	memset (to, -1, sizeof to);
	memset (from, -1, sizeof from);
	memset (was_from, 0, sizeof was_from);
	memset (was_to, 0, sizeof was_to);
	forn(i, n) {
		if  (p[i] != -1 && q[i] != -1) {
			to[p[i]] = q[i];
			from[q[i]] = p[i];
		}
		if  (p[i] != -1) {
			was_to[p[i]] = 1;
		}
		if  (q[i] != -1) {
			was_from[q[i]] = 1;
		}
	}

	// forn(i, n) {
	// 	printf("i=%d, to=%d, from=%d\n", i, to[i], from[i]);
	// }

	memset (used, 0, sizeof used);
	int full = 0;
	forn(i, n) {
		if  (!used[i] && to[i] != -1) {
			int j = to[i];
			int last = -1;
			while (j != -1 && j != i) {
				last = j;
				j = to[j];
			}
			j = last;
			if  (to[j] == -1) {
				continue;
			}
			j = i;
			while (!used[j]) {
				used[j] = 1;
				j = to[j];
			}
			++full;
		}
	}

	vi cnt(4, 0);
	forn(i, n) {
		if  (!used[i] && from[i] == -1) {
			// printf("i=%d\n", i);
			int j = i;
			int last = -1;
			while (j != -1) {
				used[j] = 1;
				last = j;
				j = to[j];
				assert(j != i);
			}
			j = last;
			if  (!was_from[i] && !was_to[j]) {
				++cnt[0];
			} else if  (was_from[i] && was_to[j]) {
				++cnt[3];
			} else if  (was_from[i]) {
				++cnt[1];
			} else {
				++cnt[2];
			}
		}
	}

	// printf("cnt:\n");
	// forn(i, sz(cnt)) {
	// 	printf("cnt[%d] = %d\n", i, cnt[i]);
	// }

	vi res = solve_4(cnt);
	vi ans(n + 1, 0);
	forn(i, sz(res)) {
		if  (res[i]) {
			ans[full + i] = res[i];
		} 
	}

	int coef = 1;
	int ptr = 1;
	forn(i, n) {
		if  (p[i] == -1 && q[i] == -1) {
			coef = mul(coef, ptr);
			++ptr;
		}
	}

	for (int& val : ans) {
		val = mul(val, coef);
	}
	return ans;
}

void solve() {
	vi res = solve_cycles();
	forn(x, n) {
		printf("%d ", res[n - x]);
	}
	puts("");
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
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}