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
const int MAXN = 500 + 10;

struct Matr {
	int a[MAXN][MAXN];
	int s[MAXN][MAXN];
	int n, m;

	Matr() {}

	Matr(int n, int m) : n(n), m(m) {
		memset (a, 0, sizeof a);
	}

	int* operator[](int i) {
		return a[i];
	}

	void precalc() {
		memset (s, 0, sizeof s);
		forn(i, n) {
			forn(j, m) {
				s[i + 1][j + 1] = s[i + 1][j] + s[i][j + 1] - s[i][j] + a[i][j];
			}
		}
	}

	int get_sum(int i, int j) {
		return s[i + 1][j + 1];
	}

	int get_sum(int i1, int i2, int j1, int j2) {
		if  (i1 > i2 || j1 > j2) return 0;
		return get_sum(i2, j2) - get_sum(i2, j1 - 1) - get_sum(i1 - 1, j2) + get_sum(i1 - 1, j1 - 1);
	}
};

char a[MAXN][MAXN];
int n, m;

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
//	freopen(FILE_NAME ".out", "w", stdout);
#endif

	scanf("%d%d\n", &n, &m);
	forn(i, n) {
		gets(a[i]);
	}

	Matr ver(n, m);
	Matr gor(n, m);

	forn(i, n - 1) forn(j, m) {
		if  (a[i][j] == '.' && a[i + 1][j] == '.') {
			++ver[i][j];
		}
	}
	ver.precalc();

	forn(i, n) forn(j, m - 1) {
		if  (a[i][j] == '.' && a[i][j + 1] == '.') {
			++gor[i][j];
		}
	}
	gor.precalc();

	int q;
	scanf("%d", &q);
	forn(it, q) {
		int i1, j1, i2, j2;
		scanf("%d%d%d%d", &i1, &j1, &i2, &j2);
		--i1;
		--j1;
		--i2;
		--j2;
		int ans = ver.get_sum(i1, i2 - 1, j1, j2) + gor.get_sum(i1, i2, j1, j2 - 1);
		printf("%d\n", ans);
	}

	return 0;
}