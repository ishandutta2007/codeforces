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
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME ""

const ld EPS = 1e-9;
const int MAXN = 1e5 + 10;

int n, k;
int x1[MAXN];
int y1[MAXN];
int x2[MAXN];
int y2[MAXN];

bool read() {
	if  (scanf("%d%d", &n, &k) < 2) {
		return false;
	}
	forn(i, n) {
		scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
	}
	return true;
}

int getx(int i) {
	return x1[i] + x2[i];
}

int gety(int i) {
	return y1[i] + y2[i];
}

vi by_x;
vi by_y;
ll best = 2e18;
bool alive[MAXN];

void rec(int lx, int rx, int ly, int ry, int have) {
	while (!alive[by_x[lx]]) ++lx;
	while (!alive[by_x[rx]]) --rx;
	while (!alive[by_y[ly]]) ++ly;
	while (!alive[by_y[ry]]) --ry;
	assert(lx <= rx);
	assert(ly <= ry);
	if  (have == 0) {
		//cout << by_x[lx] << " " << by_x[rx] << " " << by_y[ly] << " " << by_y[ry] << endl;
		int len_x = ceil(getx(by_x[rx]) * 0.5 - getx(by_x[lx]) * 0.5);
		int len_y = ceil(gety(by_y[ry]) * 0.5 - gety(by_y[ly]) * 0.5);
		best = min(best, max(len_x, 1) * 1ll * max(len_y, 1));
		return;
	}

	alive[by_x[lx]] = false;
	rec(lx, rx, ly, ry, have - 1);
	alive[by_x[lx]] = true;

	alive[by_x[rx]] = false;
	rec(lx, rx, ly, ry, have - 1);
	alive[by_x[rx]] = true;

	alive[by_y[ly]] = false;
	rec(lx, rx, ly, ry, have - 1);
	alive[by_y[ly]] = true;

	alive[by_y[ry]] = false;
	rec(lx, rx, ly, ry, have - 1);
	alive[by_y[ry]] = true;
}

ll solve() {
	by_x.clear();
	by_y.clear();
	forn(i, n) {
		by_x.pb(i);
		by_y.pb(i);
		alive[i] = true;
	}

	sort(all(by_x), [&](int i, int j) { return getx(i) < getx(j); });
	sort(all(by_y), [&](int i, int j) { return gety(i) < gety(j); });

	/*
	forn(i, n) cout << by_x[i] << " ";
	cout << endl;
	forn(i, n) cout << by_y[i] << " ";
	cout << endl;
	*/

	best = 2e18;
	rec(0, sz(by_x) - 1, 0, sz(by_y) - 1, k);
	return best;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif
 
 	while (read()) {
 		cout << solve() << endl;
 	//	break;
 	} 
  	return 0;
}