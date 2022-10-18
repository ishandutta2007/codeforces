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

struct DSU {
	vi par;
	vi mx;

	DSU(int n = 0) {
		par.assign(n, -1);
		mx.resize(n);
		forn(i, n) {
			mx[i] = i;
		}
	}

	int get(int x) {
		return par[x] < 0 ? x : par[x] = get(par[x]);
	}

	void merge(int x, int y) {
		x = get(x);
		y = get(y);
		if  (x == y) {
			return;
		}
		if  (-par[x] < -par[y]) {
			swap(x, y);
		}
		par[x] += par[y];
		par[y] = x;
		mx[x] = max(mx[x], mx[y]);
	}

	int get_max(int x) {
		return mx[get(x)];
	}
};

DSU dsu1, dsu2;
int n, q;

bool read() {
	if  (scanf("%d%d", &n, &q) < 2) {
		return false;
	}
	return true;
}

void solve() {
	dsu1 = DSU(n);
	dsu2 = DSU(n);
	forn(it, q) {
		int t;
		scanf("%d", &t);
		if  (t == 1) {
			int x, y;
			scanf("%d%d", &x, &y);
			--x;
			--y;
			dsu1.merge(x, y);
		} else if  (t == 2) {
			int x, y;
			scanf("%d%d", &x, &y);
			--x;
			--y;
			assert(x <= y);
			while (dsu2.get_max(x) < y) {
				int nxt = dsu2.get_max(x) + 1;
				dsu2.merge(x, nxt);
				dsu1.merge(x, nxt);
				x = dsu2.get(x);
			}
		} else {
			assert(t == 3);
			int x, y;
			scanf("%d%d", &x, &y);
			--x;
			--y;
			puts(dsu1.get(x) == dsu1.get(y) ? "YES" : "NO");
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

	return 0;
}