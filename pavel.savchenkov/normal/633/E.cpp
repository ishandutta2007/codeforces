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

using namespace std;

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define next jskdfksdhfjkdsjksdjkgf
#define prev koeuigrihjdkjdfj
#define hash kjfdkljkdhgjdkfhgurehg
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector <int> > vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME "a"

const int MAXN = 1e6 + 10;

int mxPow[MAXN];
ld sum_log[MAXN];

void precalc() {
	memset (mxPow, 0, sizeof mxPow);
	for (int i = 0; ; ++i) {
		int p = 1 << i;
		if  (p >= MAXN) {
			break;
		}
		mxPow[p] = 1;
	}

	int p = -1;
	forn(i, MAXN) {
		p += mxPow[i];
		mxPow[i] = p;
	}

	sum_log[0] = 0;
	for (int i = 1; i < MAXN; ++i) {
		sum_log[i] = logl(i) + sum_log[i - 1];
	}
}

struct TableMax {
	vvi t;

	TableMax() {}

	TableMax(const vi& a) {
		int mx = 0;
		while ((1 << mx) <= sz(a)) {
			++mx;
		}
		t.assign(sz(a), vi(mx, 0));
		forn(i, sz(a)) {
			t[i][0] = a[i];
		}
		for (int p = 1; p < mx; ++p) {
			forn(i, sz(a)) {
				t[i][p] = t[i][p - 1];
				int len = (1 << p);
				if  (i + len/2 >= sz(a)) {
					continue;
				}
				t[i][p] = max(t[i][p], t[i + len/2][p - 1]);
			}
		}
	}

	int get_max(int l, int r) {
		int p = mxPow[r - l + 1];
		return max(t[l][p], t[r - (1 << p) + 1][p]);
	}
};

struct TableMin {
	vvi t;

	TableMin() {}

	TableMin(const vi& a) {
		int mx = 0;
		while ((1 << mx) <= sz(a)) {
			++mx;
		}
		t.assign(sz(a), vi(mx, 0));
		forn(i, sz(a)) {
			t[i][0] = a[i];
		}
		for (int p = 1; p < mx; ++p) {
			forn(i, sz(a)) {
				t[i][p] = t[i][p - 1];
				int len = (1 << p);
				if  (i + len/2 >= sz(a)) {
					continue;
				}
				t[i][p] = min(t[i][p], t[i + len/2][p - 1]);
			}
		}
	}

	int get_min(int l, int r) {
		int p = mxPow[r - l + 1];
		return min(t[l][p], t[r - (1 << p) + 1][p]);
	}
};
int n, k;
int v[MAXN];
int c[MAXN];

bool read() {
	if  (scanf("%d%d", &n, &k) < 2) {
		return false;
	}
	forn(i, n) {
		scanf("%d", &v[i]);
	}
	forn(i, n) {
		scanf("%d", &c[i]);
	}
	return true;
}

ld solve() {
	forn(i, n) {
		v[i] *= 100;
	}
	auto tv = TableMax(vi(v, v + n));
	auto tc = TableMin(vi(c, c + n));

	vi vals(n);
	forn(l, n) {
		int L = l - 1;
		int R = n;
		while (L != R - 1) {
			int M = (L + R) / 2;
			int mx_v = tv.get_max(l, M);
			int mn_c = tc.get_min(l, M);
			if  (mx_v <= mn_c) {
				L = M;
			} else {
				R = M;
			}
		}

		vals[l] = min(tv.get_max(l, L), tc.get_min(l, L));
		if  (L + 1 < n) {
			vals[l] = max(vals[l], min(tv.get_max(l, L + 1), tc.get_min(l, L + 1)));
		}

		// printf("val[%d] = %d\n", l, vals[l]);
	}

	sort(all(vals));

	ld ans = 0;
	forn(i, n) {
		int L = n - i - 1;
		if  (L < k - 1) {
			break;
		}
		ld logP = sum_log[L] + sum_log[k] + sum_log[n - k] - sum_log[k - 1] - sum_log[L - k + 1] - sum_log[n];
		ans += exp(logP) * vals[i];
		// printf("prob i=%d = %.15f\n", i, (double) exp(logP));
	}

	return ans;
}

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	precalc();

	while (read()) {
		printf("%.15f\n", (double) solve());
	}

	return 0;
}