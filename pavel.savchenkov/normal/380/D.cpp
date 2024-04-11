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

using namespace std;

#define pb push_back
#define f first
#define s second
#define mp make_pair 
#define sz(A) ((int)(A).size())
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; i--)
#define foran(i, a, n) for (int i = (int) a; i < (int) n; i++)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgk
#define right yytrwtretywretwreytwreytwr
#define all(A) A.begin(), A.end()

template <typename T>
inline T sqr( T x ) {
	return x * x;
}

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;

const double EPS = 1e-9;
const int MAXN = int(1e5) + 10;
const int MOD = 1000000007;

int add( int a, int b ) {
	if  ((a += b) >= MOD)
		a -= MOD;
	return a;
}

int mul( int a, int b ) {
	return a * 1ll * b % MOD;
}

int mpow( int a, int p ) {
	int res = 1;
	while (p > 0) {
		if  (p & 1)
			res = mul(res, a);

	   	a = mul(a, a);
	   	p /= 2;
	}
	return res;
}

int aim[MAXN];
int num[MAXN];
int place[MAXN];
int sz;
int n;

int fact[MAXN];
int inv_fact[MAXN];

int for_empty( int len ) {
	return mpow(2, max(0, len - 1));
}

int C( int N, int K ) {
	if  (K > N || N < 0 || K < 0)
		return 0;

//	printf("(%d, %d) = %d\n", N, K, mul(fact[N], mul(inv_fact[N - K], inv_fact[K])));

	return mul(fact[N], mul(inv_fact[N - K], inv_fact[K]));
}

int solve( int i, int l, int r ) {
//	printf("i = %d l = %d r = %d\n", i, l, r);

	if  (l < 0 || l >= n || r < 0 || r >= n)
		return 0;

	if  (i == sz) {
		int all = n - num[i - 1];
		int cnt = l;

		return C(all, cnt);
	}

	if  (l <= aim[i] && aim[i] <= r)
		return 0;
		         
	if  (r < aim[i]) {
		int all = num[i] - num[i - 1] - 1;
		int cnt = aim[i] - r - 1;
		int can = aim[i] - (r - l + 1);

		if  (all > can)
			return 0;

		return mul(C(all, cnt), solve(i + 1, l - (all - cnt), aim[i]));
	} else {
		assert(l > aim[i]);

		int all = num[i] - num[i - 1] - 1;
		int cnt = l - aim[i] - 1;
		int can = n - aim[i] - 1 - (r - l + 1);

		if  (all > can)
			return 0;

		return mul(C(all, cnt), solve(i + 1, aim[i], r + (all - cnt)));
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	fact[0] = inv_fact[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		fact[i] = mul(fact[i - 1], i);
		inv_fact[i] = mpow(fact[i], MOD - 2);
	}

	memset (place, -1, sizeof place);

	scanf("%d", &n);
	forn(i, n) {
		int a;
		scanf("%d", &a);

		if  (a) {
			place[a - 1] = i;
		}
	}

	sz = 0;
	forn(i, n)
		if  (place[i] != -1) {
			aim[sz] = place[i];
			num[sz++] = i + 1;
		}

//	forn(i, sz) {
//		printf("i = %d aim = %d num = %d\n", i, aim[i], num[i]);
//	}

	if  (sz == 0) {
		printf("%d\n", for_empty(n));
		return 0;
	}
	      
	int ans = 0;

	int cnt = num[0] - 1;

	if  (cnt <= aim[0]) {
		ans = add(ans, mul(for_empty(cnt), solve(1, aim[0] - cnt, aim[0])));
	}

	if  (cnt <= n - aim[0] - 1 && cnt > 0) {
		ans = add(ans, mul(for_empty(cnt), solve(1, aim[0], aim[0] + cnt)));	
	}

	printf("%d\n", ans);	
	return 0;
}