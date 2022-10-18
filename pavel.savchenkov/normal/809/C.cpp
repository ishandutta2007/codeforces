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

#define TEST 0

const int MOD = 1e9 + 7;

void add(int& x, int y) {
	((x += y) >= MOD) && (x -= MOD);
}

int mul(int x, int y) {
	return x * 1ll * y % MOD;
}


int q;

bool read() {
#if !TEST
	if  (scanf("%d", &q) < 1) {
		return 0;
	}
#else
	q = 1;
#endif

	return 1;
}

const int LEN = 32;

vi repr(int num) {
	vi res;
	forn(it, LEN) {
		res.pb(num % 2);
		num /= 2;
	}
	reverse(all(res));
	return res;
}

int brut_solve(int x1, int y1, int x2, int y2, int k) {
	int ans = 0;
	for (int x = x1; x <= x2; ++x) {
		for (int y = y1; y <= y2; ++y) {
			int val = ((x - 1) ^ (y - 1)) + 1;
			if  (val <= k) {
				add(ans, val);
			}
		}
	}
	return ans;
}

int brut_ask(int x, int y, int lim) {
	--x;
	--y;

	if (x < 0 || y < 0) {
		return 0;
	}

	int res = 0;
	forn(i, x + 1) forn(j, y + 1) {
		int val = i ^ j;
		if  (val <= lim) {
			add(res, val + 1);
		}
	}
	return res;
}

int ask(int x, int y, int lim) {
	--x;
	--y;
	--lim;

	if (x < 0 || y < 0) {
		return 0;
	}

	vector<vvi> sum(2, vvi(2, vi(2, 0)));
	vector<vvi> cnt(2, vvi(2, vi(2, 0)));
	cnt[0][0][0] = 1;

	auto X = repr(x);
	auto Y = repr(y);
	auto LIM = repr(lim);

	forn(pos, LEN) {
		vector<vvi> new_sum(2, vvi(2, vi(2, 0)));
		vector<vvi> new_cnt(2, vvi(2, vi(2, 0)));
	
		forn(lx, 2) forn(ly, 2) forn(lk, 2) {

#define OLD [lx][ly][lk]

			if  (!cnt OLD && !sum OLD) {
				continue;
			}

			// if  (cnt OLD) {
			// 	printf("cnt %d %d %d -> %d\n", lx, ly, lk, cnt OLD);
			// }

			forn(dx, 2) forn(dy, 2) {
				int dk = dx ^ dy;

				if  (!lx && dx > X[pos]) {
					continue;
				}
				if  (!ly && dy > Y[pos]) {
					continue;
				}
				if  (!lk && dk > LIM[pos]) {
					continue;
				}

				int new_lx = lx || dx < X[pos];
				int new_ly = ly || dy < Y[pos];
				int new_lk = lk || dk < LIM[pos];

#define NEW [new_lx][new_ly][new_lk]

				add(new_cnt NEW, cnt OLD);

				int nsum = sum OLD;
				int pw2 = 1 << (LEN - 1 - pos);
				add(nsum, mul((cnt OLD), mul(dk, pw2)));

				add(new_sum NEW, nsum);
#undef NEW
			}

#undef OLD

		}
	
		sum.swap(new_sum);
		cnt.swap(new_cnt);
	}

	int ans = 0;
	forn(lx, 2) forn(ly, 2) forn(lk, 2) {
		add(ans, sum[lx][ly][lk]);
		add(ans, cnt[lx][ly][lk]);
	}

	// printf("x=%d, y=%d, lim=%d --> %d\n", x, y, lim, ans);

	return ans;
}

void solve() {
	forn(it, q) {
		int x1, y1, x2, y2;
		int k;

#if !TEST
		scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &k);
#else
		x1 = 1 + rand() % 4;
		x2 = 1 + rand() % 4;
		if  (x1 > x2) {
			swap(x1, x2);
		}	

		y1 = 1 + rand() % 4;
		y2 = 1 + rand() % 4;
		if  (y1 > y2) {
			swap(y1, y2);
		}
		k = rand() % int(1e9);
#endif

		int ans = ask(x2, y2, k);
		add(ans, -ask(x1 - 1, y2, k) + MOD);
		add(ans, -ask(x2, y1 - 1, k) + MOD);
		add(ans, ask(x1 - 1, y1 - 1, k));

		// int ans = brut_ask(x2, y2, k);
		// add(ans, -brut_ask(x1 - 1, y2, k) + MOD);
		// add(ans, -brut_ask(x2, y1 - 1, k) + MOD);
		// add(ans, brut_ask(x1 - 1, y1 - 1, k));

#if TEST
		int br = brut_solve(x1, y1, x2, y2, k);
		if  (ans != br) {
			printf("ans=%d, br=%d\n", ans, br);
			printf("x1=%d, y1=%d, x2=%d, y2=%d\n", x1, y1, x2, y2);
			exit(0);
		} else {
			printf("OK %d %d\n", ans, br);
		}
#else
		printf("%d\n", ans);
#endif

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

		// break;
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}