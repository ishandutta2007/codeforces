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

struct DSU {
	vi par;

	DSU(int n = 0) {
		par.assign(n, -1);
	}

	int get(int x) {
		return par[x] < 0 ? x : par[x] = get(par[x]);
	}

	bool unite(int x, int y) {
		x = get(x);
		y = get(y);
		if  (x == y) {
			return false;
		}
		if  (-par[x] < -par[y]) {
			swap(x, y);
		}
		par[x] += par[y];
		par[y] = x;
		return true;
	}

	int size(int x) {
		return -par[get(x)];
	}
};

const int MAXN = 1e3 + 10;

DSU dsu;
int n, m;
int a[MAXN][MAXN];
ll k;

bool read() {
	if  (scanf("%d%d%lld", &n, &m, &k) < 3) {
		return false;
	}
	forn(i, n) forn(j, m) {
		scanf("%d", &a[i][j]);
	}
	return true;
}

int code(int i, int j) {
	return i * m + j;
}

const int di[4] = { 1, -1, 0, 0 };
const int dj[4] = { 0, 0, 1, -1 };

bool alive[MAXN][MAXN];

bool on(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m;
}

void dfs(int& sz, int val, int i, int j) {
	if  (alive[i][j] || sz <= 0) {
		return;
	}
	--sz;
	alive[i][j] = true;
	a[i][j] = val;
	forn(k, 4) {
		int ii = i + di[k];
		int jj = j + dj[k];
		if  (on(ii, jj) && !alive[ii][jj] && a[ii][jj] >= val) {
			dfs(sz, val, ii, jj);
		}
	}
}

bool solve() {
	vector<pair<int, pii>> v;
	forn(i, n) forn(j, m) {
		v.pb(mp(a[i][j], mp(i, j)));
	}
	sort(all(v));
	reverse(all(v));

	int I = -1;
	int J = -1;
	DSU dsu(n * m);
	forn(it, sz(v)) {
		int i, j;
		tie(i, j) = v[it].snd;
		int val = v[it].fst;
		alive[i][j] = true;

		forn(k, 4) {
			int ii = i + di[k];
			int jj = j + dj[k];
			if  (on(ii, jj) && alive[ii][jj]) {
				int me = code(i, j);
				int other = code(ii, jj);
				// printf("unite %d %d - %d %d\n", i, j, ii, jj);
				dsu.unite(me, other);
			}
		}

		int sz = dsu.size(code(i, j));
		// printf("sz = %d\n", sz);
		if  (k % val != 0 || k / val > sz) {
			continue;
		}
		I = i;
		J = j;
		break;
	}

	if  (I == -1) {
		return false;
	}

	puts("YES");
	ll need = k / a[I][J];
	memset (alive, false, sizeof alive);
	int sz = need;
	dfs(sz, a[I][J], I, J);
	forn(i, n) forn(j, m) {
		if  (!alive[i][j]) {
			a[i][j] = 0;
		}
	}
	forn(i, n) {
		forn(j, m) {
			printf("%d ", a[i][j]);
		}
		puts("");
	}
	return true;
}

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		if  (!solve()) {
			puts("NO");
		}
	}
	return 0;
}