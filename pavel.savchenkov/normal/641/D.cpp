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

ld read_ld() {
	double x;
	scanf("%lf", &x);
	return x;
}

const int MAXN = 1e5 + 10;
const ld EPS = 1e-9;

ld mx[MAXN];
ld mn[MAXN];
int n;

ld a[MAXN];
ld b[MAXN];

bool read() {
	if  (scanf("%d", &n) < 1) {
		return false;
	}
	forn(i, n) {
		mx[i] = read_ld();
	}
	forn(i, n) {
		mn[i] = read_ld();
	}
	return true;
}

ld p[MAXN];
ld q[MAXN];

ld my_sqrt(ld x) {
	ld l = 0;
	ld r = x + 1;
	forn(it, 100) {
		ld m = (l + r) * 0.5;
		if  (m * m <= x) {
			l = m;
		} else {
			r = m;
		}
	}
	return l;
}

pair<ld, ld> get(ld x, ld y) {
	// printf("y * y - 4 * x = %.15f\n", double(y * y - 4 * x));
	ld p = (y + my_sqrt(y * y - 4 * x)) * 0.5;
	return mp(p, y - p);
}

void solve() {
	ld sum_mx = 0;
	forn(i, n) {
		sum_mx += mx[i];
		a[i] = sum_mx;
	}

	ld sum_mn = 0;
	ford(i, n) {
		if  (i == 0) {
			break; 
		}
		b[i - 1] = 1.0 - mn[i] - sum_mn + a[i - 1];
		sum_mn += mn[i];
	}

	b[n - 1] = 2.0;

	forn(i, n) {
		ld P, Q;
		tie(P, Q) = get(a[i], b[i]);
		if  (i == 0) {
			p[i] = P;
			q[i] = Q;
			continue;
		}
		if  (P >= p[i - 1] - EPS && Q >= q[i - 1] - EPS) {
			p[i] = P;
			q[i] = Q;
		} else {
			p[i] = Q;
			q[i] = P;
		}
	}

	forn(i, n) {
		ld cur = p[i];
		if  (i) cur -= p[i - 1];
		cur = max(cur, (ld) 0.0);
		printf("%.15f ", (double) cur);
	}
	puts("");
	forn(i, n) {
		ld cur = q[i];
		if  (i) cur -= q[i - 1];
		cur = max(cur, (ld) 0.0);
		printf("%.15f ", (double) cur);
	}
	puts("");
}

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		solve();
	}

	return 0;
}