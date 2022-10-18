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

const int MAXN = 1e3 + 10;

int x[MAXN];
int y[MAXN];
int n;

bool read() {
	if  (scanf("%d", &n) < 1) {
		return false;
	}
	forn(i, n + 1) {
		scanf("%d%d", &x[i], &y[i]);
	}
	return true;
}

int dir(int i) {
	if  (x[i] == x[i + 1]) {
		if  (y[i + 1] < y[i]) {
			return 0;
		}
		return 2;
	}
	if  (x[i + 1] > x[i]) {
		return 1;
	}
	return 3;
}

int solve() {
	int ans = 0;
	forn(i, n) {
		int d0 = dir(i);
		int d1 = dir(i + 1);
		// printf("%d\n", d0);
		if  ((d0 + 1) % 4 == d1) {
			++ans;
		}
	}
	return ans;
}

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		printf("%d\n", solve());
	}
	return 0;
}