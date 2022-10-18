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

const int MAXC = 2e8;

struct Point {
	int x, y;

	Point() {}

	bool read() {
		return scanf("%d%d", &x, &y) >= 2;
	}

	bool operator < (const Point& p) const {
		return x < p.x;
	}
};

template <typename T>
void remax(T& x, const T& y) {
	if  (y > x)
		x = y;
}

template <typename T>
void remin(T& x, const T& y) {
	if  (y < x)
		x = y;
}

bool can(ll d, const vector<Point>& ps, const vi& pref_min, const vi& pref_max, const vi& suff_min, const vi& suff_max) {
	const int n = sz(ps);
	for (int l = 0, r = 0; l < n && ps[l].x <= 0; ++l) {
		while (r < n && (ps[r].x - ps[l].x) * 1ll * (ps[r].x - ps[l].x) <= d && abs(ps[r].x) <= abs(ps[l].x)) {
			++r;
		}
		while (r > l + 1 && abs(ps[r - 1].x) > abs(ps[l].x)) {
			--r;
		}

		if  (r - l == n) {
			return true;
		}

		int max_y = max(pref_max[l], suff_max[r]);
		int min_y = min(pref_min[l], suff_min[r]);
		if  ((max_y - min_y) * 1ll * (max_y - min_y) > d) {
			continue;
		}
		max_y = max(abs(max_y), abs(min_y));
		if  (ps[l].x * 1ll * ps[l].x + max_y * 1ll * max_y > d) {
			continue;
		}
		return true;
	}
	return false;
}

ll solve1(vector<Point> ps) {
	const int n = sz(ps);
	sort(all(ps));
	
	vi pref_min(n + 1, MAXC);
	vi pref_max(n + 1, -MAXC);
	forn(i, n) {
		remin(pref_min[i + 1], min(pref_min[i], ps[i].y));
		remax(pref_max[i + 1], max(pref_max[i], ps[i].y));
	}

	vi suff_min(n + 1, MAXC);
	vi suff_max(n + 1, -MAXC);
	ford(i, n) {
		remin(suff_min[i], min(suff_min[i + 1], ps[i].y));
		remax(suff_max[i], max(suff_max[i + 1], ps[i].y));
	}

	ll L = -1;
	ll R = MAXC * 1ll * MAXC;
	while (L != R - 1) {
		ll M = (L + R) / 2;
		if  (can(M, ps, pref_min, pref_max, suff_min, suff_max)) {
			R = M;
		} else {
			L = M;
		}
	}
	return R;
}

ll solve(vector<Point> ps) {
	ll ans = solve1(ps);
	for (auto& p : ps) p.x = -p.x;
	ans = min(ans, solve1(ps));
	
	forn(it, 2) {
		int max_x = -MAXC;
		int min_x = MAXC;
		for (const auto& p : ps) {
			remax(max_x, p.x);
			remin(min_x, p.x);
		}
		remin(ans, (max_x - min_x) * 1ll * (max_x - min_x));
	
		for (auto& p : ps) {
			swap(p.x, p.y);
		}
	}

	return ans;
}

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	vector<Point> ps(n);
	forn(i, n) {
		assert(ps[i].read());
	}
	printf("%lld\n", solve(ps));

	return 0;
}