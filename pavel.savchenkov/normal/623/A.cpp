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

const int MAXN = 500 + 10;

bool g[MAXN][MAXN];
int n, m;
int col[MAXN];
bool alive[MAXN];
vi G[MAXN];

void precalc() {

}

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return false;
	}
	memset (g, false, sizeof g);
	forn(i, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		g[a][b] = g[b][a] = true;
	}
	return true;
}

bool dfs(int v) {
	for (int to : G[v]) {
		assert(alive[to]);
		if  (col[to] == -1) {
			col[to] = col[v] ^ 1;
			if  (!dfs(to)) {
				return false;
			}
		} else if  (col[to] != (col[v] ^ 1)) {
			return false;
		}
	}
	return true;
}

bool solve() {
	memset (alive, false, sizeof alive);
	forn(i, n) {
		forn(j, n) {
			if  (i == j) {
				continue;
			}
			if  (!g[i][j]) {
				G[i].pb(j);
				alive[i] = true;
			}
		}
	}

	memset (col, -1, sizeof col);
	forn(i, n) {
		if  (alive[i] && col[i] == -1) {
			col[i] = 0;
			if  (!dfs(i)) {
				return false;
			}
		}
	}

	static char s[MAXN];
	forn(i, n) {
		if  (col[i] == -1) {
			s[i] = 'b';
		} else if  (col[i] == 1) {
			s[i] = 'c';
		} else {
			s[i] = 'a';
		}
	}
	forn(i, n) forn(j, n) {
		if  (i == j) {
			continue;
		}
		bool need = abs(s[i] - s[j]) <= 1;
		if  (need != g[i][j]) return false;
	}
	puts("Yes");
	s[n] = 0;
	puts(s);
	return true;
}

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif
	
	while (read()) {
		if  (!solve()) {
			puts("No");
		}
	}

	return 0;
}