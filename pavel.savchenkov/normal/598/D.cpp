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

#define FILE_NAME "a"

const ld EPS = 1e-9;
const int MAXN = 1e3 + 10;

const int di[4] = { 1, 0, -1, 0 };
const int dj[4] = { 0, 1, 0, -1 };

int n, m, k;
int cnt[MAXN * MAXN];
char a[MAXN][MAXN];
int comp[MAXN][MAXN];

bool on(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m;
}

void dfs(int i, int j) {
	forn(z, 4) {
		int ni = i + di[z];
		int nj = j + dj[z];
		if  (on(ni, nj) && comp[ni][nj] == -1 && a[ni][nj] == '.') {
			comp[ni][nj] = comp[i][j];
			dfs(ni, nj);
		}
	}
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
//	freopen(FILE_NAME ".out", "w", stdout);
#endif

	scanf("%d%d%d\n", &n, &m, &k);
	forn(i, n) {
		gets(a[i]);
	}   

	int c = 0;
	memset (comp, -1, sizeof comp);
	forn(i, n) forn(j, m) {
		if  (a[i][j] == '.' && comp[i][j] == -1) {
			comp[i][j] = c++;
			dfs(i, j);
		}
	}

	forn(i, n) forn(j, m) {
		if  (a[i][j] != '.') {
			continue;
		}
		forn(z, 4) {
			int ni = i + di[z], nj = j + dj[z];
			if  (on(ni, nj) && a[ni][nj] != '.') {
				++cnt[comp[i][j]];
			}
		}
	}

	forn(t, k) {
		int i, j;
		scanf("%d%d", &i, &j);
		--i;
		--j;
		printf("%d\n", cnt[comp[i][j]]);
	}
	return 0;
}