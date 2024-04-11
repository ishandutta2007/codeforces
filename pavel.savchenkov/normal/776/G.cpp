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


int q;

bool read() {
	if  (scanf("%d", &q) < 1) {
		return 0;
	}
	return 1;
}

int get_dig(char c) {
	if  ('0' <= c && c <= '9') {
		return c - '0';
	}
	if  ('a' <= c && c <= 'f') {
		return c - 'a' + 10;
	}
	return -1;
}

ull read_num() {
	string res;
	char c;
	while (1) {
		c = getchar();
		// printf("c = %c\n", c);
		int d = get_dig(c);
		if  (d == -1) {
			if  (!res.empty()) {
				break;
			}
			continue;
		}
		res += c;
	}

	// printf("res = %s\n", res.data());

	ull coef = 1;
	ull ans = 0;
	ford(i, sz(res)) {
		int d = get_dig(res[i]);
		ans += coef * d;
		coef *= 16;
	}
	return ans;
}

bool bit(int x, int i) {
	return (x >> i) & 1;
}

ull dp[20][2][2][2];

ull solve(ull r) {
	if  (!r) {
		return 0;
	}
	
	ull old = r;
	vi R;
	forn(it, 16) {
		R.pb(r % 16);
		r /= 16;
	}
	reverse(all(R));
	r = old;

	// forn(i, 16) {
	// 	ford(it, 4) {
	// 		printf("%d", bit(R[i], it));
	// 	}
	// 	printf(" ");
	// }
	// puts("");

	ull ans = 0;
	for (int hb = 1; hb < 16; ++hb) {
		memset (dp, 0, sizeof dp);
		dp[0][0][0][0] = 1;
		forn(i, 16) forn(was16, 2) forn(was2, 2) forn(ls, 2) {
			ll cur_dp = dp[i][was16][was2][ls];
			if  (!cur_dp) {
				continue;
			}
			// printf("i=%d, was16=%d, was2=%d, ls=%d -> %lld\n", i, was16, was2, ls, cur_dp);
			forn(d, 16) {
				if  (d > hb) {
					continue;
				}
				if  (!ls && d > R[i]) {
					continue;
				}
				int nwas16 = was16 || d == hb;
				int nwas2 = was2;
				if  (hb / 4 == 15 - i && bit(d, hb % 4)) {
					nwas2 = 1;
				}
				int nls = ls || d < R[i];
				dp[i + 1][nwas16][nwas2][nls] += cur_dp;
			}
		}

		ull cur = 0;
		cur += dp[16][1][1][0];
		cur += dp[16][1][1][1];

		// printf("hb=%d, cur=%lld\n", hb, cur);

		ans += cur;
	}

	// printf("r=%lld, ans=%lld\n", r, ans);
	return ans;
}

void solve() {
	forn(it, q) {
		ull l, r;
		l = read_num();
		r = read_num();

		ull ans = solve(r);
		if  (l > 0) {
			ans -= solve(l - 1);
		}
		printf("%llu\n", ans);

		// break;
	}
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