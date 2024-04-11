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

const ld EPS = 1e-9;

struct pnt {
	ld x, y;

	void read() {
		int a, b;
		scanf("%d%d", &a, &b);
		x = a;
		y = b;
	}

	pnt() {}

	pnt(ld x, ld y) : x(x), y(y) {}

	pnt operator - (const pnt& p) const {
		return pnt(x - p.x, y - p.y);
	}
};

struct line {
	ld a, b, c;

	line(pnt p, pnt q) {
		a = -(p - q).y;
		b = (p - q).x;
		c = -(p.x * a + p.y * b);
		assert(on(p));
		assert(on(q));
	}

	bool on(pnt p) {
		return dist(p) < EPS;
	}

	ld dist(pnt p) const {
		return fabs(a * p.x + b * p.y + c) / sqrt(a * a + b * b);
	}
};

int n;
vector<pnt> ps;

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	ps.resize(n);
	forn(i, n) {
		ps[i].read();
	}
	return 1;
}

int prev(int i) {
	return i ? i - 1 : n - 1;
}

int next(int i) {
	return i == n - 1 ? 0 : i + 1;
}

void solve() {
	ld D = 3e9;
	forn(i, n) {
		line l(ps[prev(i)], ps[next(i)]);
		ld cur = l.dist(ps[i]);
		D = min(D, cur / 2);
	}
	printf("%.15f\n", double(D));
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