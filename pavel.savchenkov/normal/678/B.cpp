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


const int MAXN = 2e5 + 10;

const int cnt[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int day[MAXN];

bool vis(int y) {
	return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

void precalc() {
	day[1000] = 3;
	for (int y = 1000; y < MAXN; ++y) {
		int days = 0;
		forn(i, 12) {
			days += cnt[i];
		}
		if  (vis(y)) {
			++days;
		}
		day[y + 1] = (day[y] + days) % 7;
	}
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	precalc();

	int y;
	cin >> y;
	for (int yy = y + 1; yy < MAXN; ++yy) {
		if  (vis(yy) == vis(y) && day[y] == day[yy]) {
			printf("%d\n", yy);
			return 0;
		}
	}

#ifdef LOCAL
	printf("Time: %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}