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
const int MAXN = int(1e5) + 10;
const int MOD = 1000000007;

inline int add( int a, int b ) {
    if  ((a += b) >= MOD)
    	a -= MOD;
	return a;
}

inline int mul( int a, int b ) {
	return a * 1ll * b % MOD;
}

inline int mpow( int a, int p ) {
	int res = 1;
	for (; p > 0; p >>= 1, a = mul(a, a))
		if  (p & 1) {
			res = mul(res, a);	
		}
	return res;
}


vi divisors[MAXN];
int fact[MAXN];
int inv_fact[MAXN];
int ans[MAXN];

void precalc() {
	for (int i = 2; i < MAXN; ++i)
		for (int j = i; j < MAXN; j += i)
			divisors[j].pb(i);

	fact[0] = inv_fact[0] = 1;
	for (int i = 1; i < MAXN; ++i) {
		fact[i] = mul(fact[i - 1], i);
		inv_fact[i] = mpow(fact[i], MOD - 2);
	}
}

inline int C( int n, int k ) {
	if  (k > n || n < 0) {
		return 0;
	}

	return mul(fact[n], mul(inv_fact[n - k], inv_fact[k]));
}

inline int calc( int sum, int bins ) {
	return C(sum - 1, bins - 1);	
}

int main() {	
	precalc();

	int q;
	scanf("%d", &q);

	while (q --> 0) {
		int n, f;
		scanf("%d%d", &n, &f);

		forn(i, sz(divisors[n])) {
			int gcd = divisors[n][i];

			int cur = calc(n / gcd, f);

			ans[gcd] = cur;
		}

		int res = 0;
		ford(i, sz(divisors[n])) {
			int gcd = divisors[n][i];
			
			forn(j, sz(divisors[gcd]) - 1) {
				int d = divisors[gcd][j];

				ans[d] = add(ans[d], -ans[gcd] + MOD);
			}

			res = add(res, ans[gcd]);
		}
		
		int all = calc(n, f);
		printf("%d\n", add(all, -res + MOD));
	}

	return 0;
}