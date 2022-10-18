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

#define pb push_back
#define f first
#define s second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define foran(i, a, n) for (int i = (int) a; i < (int) n; ++i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define all(C) (C).begin(), (C).end()

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

const double EPS = 1e-9;
const int MAXN = 2000 + 10;
const int MAXLOG = 15;
const int MOD = int(1e9) + 7;

inline void add( int & x, int y ) {
	if  ((x += y) >= MOD)
		x -= MOD;
}

inline int mul( int x, int y ) {
	return x * 1ll * y % MOD;
}

inline int mpow( int a, int p ) {
	int res = 1;
	while (p) {
		if  (p & 1) {
			res = mul(res, a);
		}

		a = mul(a, a);
		p >>= 1;
	}

	return res;
}

inline int inv( int x ) {
	return mpow(x, MOD - 2);
}

int fact[2 * MAXN];
int dp[MAXLOG][MAXN];
int n, k;
int d[MAXLOG];

inline int C( int n, int k ) {
	return mul(fact[n], mul(inv(fact[k]), inv(fact[n - k])));
}

inline int CC( int n, int k ) {
	if  (k == 0)
		return 1;
	return C(n + k - 1, k);
}

void precalc() {
	fact[0] = 1;

	for (int i = 1; i < 2 * MAXN; ++i) {
		fact[i] = mul(fact[i - 1], i);
	}
}

int main() {
	precalc();

	scanf("%d%d", &n, &k);
		
	memset (dp, 0, sizeof dp);
	
	for (int f = 1; f <= n; ++f)
		dp[1][f] = 1;

	for (int i = 1; i < MAXLOG; ++i) {
		for (int last = 1; last <= n; ++last) {
			if  (dp[i][last]) {
				for (int next = last * 2; next <= n; next += last)
					add(dp[i + 1][next], dp[i][last]);
			}
		}
	}

	int ans = 0;
	for (int len = 1; len < MAXLOG && len <= k; ++len) {
		d[len] = 0;
		for (int last = 1; last <= n; ++last)
			add(d[len], dp[len][last]);

		add(ans, mul(CC(len, k - len), d[len]));
	}

	printf("%d\n", ans);
	return 0;
}