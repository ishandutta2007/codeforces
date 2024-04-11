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


const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;

void add(int& x, int y) {
	((x += y) >= MOD) && (x -= MOD);
}

int mul(int x, int y) {
	return x * 1ll * y % MOD;
}

int k, p;

bool read() {
	if  (scanf("%d%d", &p, &k) < 2) {
		return false;
	}
	return true;
}

int mpow(int a, int z) {
	int res = 1;
	for (; z > 0; a = mul(a, a), z >>= 1) {
		if  (z & 1) {
			res = mul(res, a);
		}
	}
	return res;
}

struct DSU {
	vi par;

	DSU(int n = 0) {
		par.assign(n, -1);
	}

	int get(int x) {
		return par[x] < 0 ? x : par[x] = get(par[x]);
	}

	void union_set(int x, int y) {
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
	}
};

int solve() {
	if  (k == 0) {
		return mpow(p, p - 1);
	}

	if  (k == 1) {
		return mpow(p, p);
	}

	DSU dsu(p);
	forn(x, p) {
		dsu.union_set(x, x * 1ll * k % p);
	}

	int comps = -1;
	forn(x, p) {
		if  (dsu.get(x) == x) {
			++comps;
		}
	}

	// printf("comps = %d\n", comps);
	return mpow(p, comps);
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		printf("%d\n", solve());
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}