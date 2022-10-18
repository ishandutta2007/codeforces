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

using namespace std;

#define PB push_back
#define F first
#define S second
#define MP make_pair 
#define SZ(C) ((int) (C).size())
#define FORN(i, n) for (int i = 0; i < (int) n; ++i)
#define FORD(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define ALL(C) begin(C), end(C)

#define DEBUG(x) cerr << #x" = " << x << '\n';

template <typename T>
inline T sqr( T x ) {
	return x * x;
}

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;
typedef vector <vector<pii> > vvii;

const double EPS = 1e-9;
const int MAXB = 20;
const int MAXN = 1 << MAXB;
const int MOD = int(1e9 + 7);

inline void add( int& x, int y ) {
	if  ((x += y) >= MOD) {
		x -= MOD;
	}
}

inline int mul( int x, int y ) {
	return x * 1ll * y % MOD;
}

int mpow( int a, int p ) {
	int res = 1;

	for (; p; p >>= 1, a = mul(a, a)) {
		if  (p & 1) {
			res = mul(res, a);
		}
	}

	return res;
}

inline bool bit( int x, int b ) {
	return (x >> b) & 1;
}

int f[MAXB + 5][MAXN + 5]; // f[k][x] -- #{ a_1 | a_1 & x_1 == x_1 && a_2 == x_2 }
int cnt[MAXN + 5];
int n;

int main() {
	scanf("%d", &n);

	FORN(i, n) {
		int a;
		scanf("%d", &a);
		++cnt[a];
	}

	FORN(x, MAXN) {
		f[0][x] = cnt[x];
	}

	for (int k = 1; k <= MAXB; ++k) {
		FORN(x, MAXN) {
			f[k][x] = f[k - 1][x];

			if  (!bit(x, k - 1)) {
				add(f[k][x], f[k - 1][x ^ (1 << (k - 1))]);		
			}	
		}
	}

	// cnt[x] -- how many subsets with &{a_i} >= x
	FORN(x, MAXN) {
		cnt[x] = mpow(2, f[MAXB][x]);
	}

	int ans = 0;
	FORN(x, MAXN) {
		if  (!x) {
			continue;
		}

		if  (__builtin_popcount(x) & 1) {
			add(ans, cnt[x]);
		} else {
			add(ans, -cnt[x] + MOD);
		}
	}

	int res = 0;
	add(res, mpow(2, n));
	add(res, -ans + MOD);

	printf("%d\n", res);
	return 0;
}