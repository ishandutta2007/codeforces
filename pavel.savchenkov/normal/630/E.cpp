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

ull solve(ull x, ull y1, ull y2) {
	if  (x % 2 == 0) {
		assert(y1 % 2 == 0);
		assert(y2 % 2 == 0);
		y1 /= 2;
		y2 /= 2;
		return y2 >= y1 ? y2 - y1 + 1 : 0;
	}
	ull y = y2 - y1 + 1;
	if  (y1 % 2 != 0) ++y1;
	if  (y2 % 2 != 0) --y2;
	y1 /= 2;
	y2 /= 2;
	return y - (y2 >= y1 ? y2 - y1 + 1 : 0);
}

int main() {
#ifdef DEBUG
	// freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	ll x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	// if  (x1 <= 0) {
	// 	ll dx = -x1 + 5;
	// 	if  (dx % 2 != 0) ++dx;
	// 	x1 += dx;
	// 	x2 += dx;
	// }
	// if  (y1 <= 0) {
	// 	ll dy = -y1 + 5;
	// 	if  (dy % 2 != 0) ++dy;
	// 	y1 += dy;
	// 	y2 += dy;
	// }
	cout << ((x2 - x1 + 1) * (y2 - y1 + 1) + 2) / 2 << endl;
	return 0;
	cout << (solve(x1, y1, y2) + solve(x1 + 1, y1, y2)) * 1ull * ((x2 - x1) / 2) + solve(x1, y1, y2) << endl;
	return 0;
}