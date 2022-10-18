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


const int MAXN = 1e5 + 10;

struct Point {
	int x, y;

	void read() {
		scanf("%d%d", &x, &y);
	}

	double dist(const Point& p) const {
		return sqrt((x - p.x) * 1ll * (x - p.x) + (y - p.y) * 1ll * (y - p.y));
	}
};

Point p[MAXN];
Point a, b, t;
int n;
double sum;

pii calc_mn(const Point& q) {
	int mn1 = -1;
	double Mn1 = 1e20;
	int mn2 = -1;
	double Mn2 = 1e20;
	forn(i, n) {
		double cur = sum - (2 * p[i].dist(t)) + q.dist(p[i]) + p[i].dist(t);
		if  (cur < Mn1) {
			Mn2 = Mn1;
			mn2 = mn1;
			Mn1 = cur;
			mn1 = i;
		} else if  (cur < Mn2) {
			Mn2 = cur;
			mn2 = i;
		}
	}
	return mp(mn1, mn2);
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	a.read();
	b.read();
	t.read();

	scanf("%d", &n);

	forn(i, n) {
		p[i].read();
	}

	if  (n == 1) {
		printf("%.10f\n", min(a.dist(p[0]) + p[0].dist(t), b.dist(p[0]) + p[0].dist(t)));
		return 0;
	}

	sum = 0;
	forn(i, n) {
		sum += 2 * p[i].dist(t);
	}

	int mn1_a = -1;
	int mn2_a = -1;
	tie(mn1_a, mn2_a) = calc_mn(a);

	int mn1_b = -1;
	int mn2_b = -1;
	tie(mn1_b, mn2_b) = calc_mn(b);

	double ans = 1e20;

	forn(i, n) {
		double cur = sum - 2 * p[i].dist(t);
		cur += a.dist(p[i]) + p[i].dist(t);
		ans = min(ans, cur);
		int j = mn1_b;
		if  (j == i) {
			j = mn2_b;
		}
		cur -= 2 * p[j].dist(t);
		cur += b.dist(p[j]) + p[j].dist(t);
		// printf("a to %d, b to %d, cur = %.10f\n", i, j, cur);
		ans = min(ans, cur);
	}

	forn(i, n) {
		double cur = sum - 2 * p[i].dist(t);
		cur += b.dist(p[i]) + p[i].dist(t);
		ans = min(ans, cur);
	}
	
	printf("%.10f\n", ans);


	return 0;
}