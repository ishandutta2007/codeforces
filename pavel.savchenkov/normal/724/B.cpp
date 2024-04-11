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
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
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

const int MAXN = 20 + 10;

int n, m;
int a[MAXN][MAXN];

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return false;
	}
	forn(i, n) {
		forn(j, m) {
			scanf("%d", &a[i][j]);
			--a[i][j];
		}
	}
	return true;
}

bool can() {
	forn(i, n) {
		int bad = 0;
		forn(j, m) {
			bad += a[i][j] != j;
		}
		if  (bad > 2) {
			return false;
		}
	}
	return true;
}

bool solve() {
	if  (can()) {
		return true;
	}
	forn(c1, m) forn(c2, c1) {
		forn(i, n) {
			swap(a[i][c1], a[i][c2]);
		}
		if  (can()) {
			return true;
		}
		forn(i, n) {
			swap(a[i][c1], a[i][c2]);
		}
	}
	return false;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		puts(solve() ? "YES" : "NO");
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}