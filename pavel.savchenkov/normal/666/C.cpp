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


const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;
const int A = 26;

void add(int& x, int y) {
	((x += y) >= MOD) && (x -= MOD);
}

int mul(int x, int y) {
	return x * 1ll * y % MOD;
}

int mpow(int a, int p) {
	int res = 1;
	for (; p > 0; p >>= 1, a = mul(a, a)) {
		if  (p & 1) {
			res = mul(res, a);
		}
	}
	return res;
}

int inv(int x) {
	int i = mpow(x, MOD - 2);
	assert(mul(x, i) == 1);
	return i;
}

int fact[MAXN];
int inv_fact[MAXN];
int mem_pow[2][MAXN];

void precalc() {
	fact[0] = 1;
	for (int i = 1; i < MAXN; ++i) {
		fact[i] = mul(i, fact[i - 1]);
	}
	forn(i, MAXN) {
		inv_fact[i] = inv(fact[i]);
	}

	forn(it, 2) {
		int c = it == 0 ? A - 1 : A;
		mem_pow[it][0] = 1;
		for (int i = 1; i < MAXN; ++i) {
			mem_pow[it][i] = mul(mem_pow[it][i - 1], c);
		}
	}
}

int C(int n, int k) {
	if  (k > n) return 0;
	return mul(fact[n], mul(inv_fact[n - k], inv_fact[k])); 
}

const int K = 600;

int mem_ans[K][MAXN];
map<int, int> id;

void calc(int* ans, int m) {
	forn(i, m) ans[i] = 0;
	for (int n = m; n < MAXN; ++n) {
		ans[n] = ans[n - 1];
		ans[n] = mul(ans[n], A);
		add(ans[n], mul(C(n - 1, m - 1), mem_pow[0][(n - 1) - (m - 1)]));
		// printf("ans[n=%d][m=%d] = %d\n", n, m, ans[n]);
	}
}

int get(int n, int m) {
	assert(id.count(m));
	int i = id[m];
	return mem_ans[i][n];
}

char s[MAXN];

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	precalc();

	int T;
	scanf("%d\n", &T);
	gets(s);
	int m = strlen(s);
	id[m] = 0;
	calc(mem_ans[0], m);
	forn(it, T) {
		int t;
		scanf("%d\n", &t);
		if  (t == 1) {
			gets(s);
			m = strlen(s);
			if  (id.count(m)) {
				continue;
			}
			int i = sz(id);
			id[m] = i;
			calc(mem_ans[i], m);
		} else {
			int n;
			scanf("%d\n", &n);
			printf("%d\n", get(n, m));
		}
	}

	return 0;
}