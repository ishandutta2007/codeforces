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

const int MAXN = 2e5 + 10;
const int MOD = 1e9 + 7;

void add(int& x, int y, int mod) {
	((x += y) >= mod) && (x -= mod);
}

int mul(int x, int y, int mod) {
	return x * 1ll * y % mod;
}

int mpow(int a, int p, int mod) {
	int res = 1;
	for (; p > 0; p /= 2, a = mul(a, a, mod))
		if  (p & 1)
			res = mul(res, a, MOD);
	return res;
}

int deg[MAXN];
int m;
int pref_ways[MAXN];
int suff_ways[MAXN];

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
//	freopen(FILE_NAME ".out", "w", stdout);
#endif

	scanf("%d", &m);
	forn(i, m) {
		int p;
		scanf("%d", &p);
		++deg[p];
	}	

	forn(p, MAXN) {
		pref_ways[p] = deg[p] + 1;
		if  (p > 0) {
			pref_ways[p] = mul(pref_ways[p - 1], pref_ways[p], MOD - 1);
		}
	}

	ford(p, MAXN) {
		suff_ways[p] = deg[p] + 1;
		if  (p + 1 < MAXN) {
			suff_ways[p] = mul(suff_ways[p + 1], suff_ways[p], MOD - 1);
		}
	}

	int ans = 1;
	forn(p, MAXN) {
		if  (!deg[p]) {
			continue;
		}
		int cur_ways = mul(pref_ways[p - 1], suff_ways[p + 1], MOD - 1);

		int P = p;
		for (int i = 1; i <= deg[p]; ++i, P = mul(P, p, MOD)) {
			ans = mul(ans, mpow(P, cur_ways, MOD), MOD);
		}
	}

	printf("%d\n", ans);

	return 0;
}