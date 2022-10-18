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

struct Point {
	int x, y;

	void read() {
		scanf("%d%d", &x, &y);
	}

	bool operator < (const Point& p) const {
		if  (x != p.x) return x < p.x;
		return y < p.y;
	}

	bool operator == (const Point& p) const {
		return x == p.x && y == p.y;
	}
};

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	vector<Point> p(n);
	forn(i, n) {
		p[i].read();
	}

	sort(all(p));

	map<int, int> X;
	map<int, int> Y;
	int l = 0;
	ll ans = 0;
	while (l < n) {
		int r = l;
		while (r < n && p[r] == p[l]) ++r;
		// printf("[%d, %d)\n", l, r);
		int cnt = r - l;
		ans += X[p[l].x] * 1ll * cnt;
		ans += Y[p[l].y] * 1ll * cnt;
		ans += cnt * 1ll * (cnt - 1) / 2;
		X[p[l].x] += cnt;
		Y[p[l].y] += cnt;
		l = r;
	}

	// forn(i, n) for (int j = i + 1; j < n; ++j) {
	// 	int dx = p[i].x - p[j].x;
	// 	int dy = p[i].y - p[j].y;
	// 	if  (abs(dx) + abs(dy) == round(sqrt(dx * dx + dy * dy))) {
	// 		printf("%d %d - %d %d\n", p[i].x, p[i].y, p[j].x, p[j].y);
	// 	}
	// }

	cout << ans << '\n';

	return 0;
}