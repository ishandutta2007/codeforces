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
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;

#define FILE_NAME "a"

const int MAXN = 2e3 + 10;

int n, m;
bitset<MAXN> a[MAXN];
vii p;

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return 0;
	}
	p.resize(m);
	forn(i, m) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x;
		--y;
		p[i] = mp(x, y);
		a[y].set(x);
	}
	return 1;
}

bitset<MAXN> repr[MAXN];

void solve() {
	forn(i, n) {
		repr[i].set(i);
	}

	// forn(i, n) {
	// 	cout << a[i] << endl;
	// }

	forn(row, n) {
		int col = row;
		for (int i = row + 1; i < n; ++i) {
			if  (a[i][col] && !a[row][col]) {
				a[row] ^= a[i];
				repr[row] ^= repr[i];
				break;
			}
		}
		// cout << "a = " << a[row] << endl;
		// printf("row=%d\n", row);
		assert(a[row][col]);
		forn(i, n) {
			if  (i == row || !a[i][col]) {
				continue;
			}
			a[i] ^= a[row];
			repr[i] ^= repr[row];
		}
	}

	// forn(i, n) {
	// 	cout << repr[i] << endl;
	// }

	forn(i, sz(p)) {
		int x, y;
		tie(x, y) = p[i];
		if  (repr[x][y]) {
			puts("NO");
		} else {
			puts("YES");
		}
	}
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