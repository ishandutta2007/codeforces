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
#include <numeric>

using namespace std;

#define ws ws_____________________
#define y1 y1_____________________
#define y0 y0_____________________
#define left left_________________
#define right right_______________
#define next next_________________
#define prev prev_________________
#define hash hash_________________

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;

#define FILE_NAME "a"

const int MAXN = 5000 + 10;
const int MOD = 1e9 + 7;
const int A = 26;

void add(int& x, int y) {
	((x += y) >= MOD) && (x -= MOD);
}

int mul(int x, int y) {
	return x * 1ll * y % MOD;
}

int n;
char s[MAXN];

bool read() {
	if  (scanf("%d\n", &n) < 1) {
		return 0;
	}
	scanf("%s", s);
	return 1;
}

int last[A][MAXN];
vii segs;

int fact[MAXN];
int inv_fact[MAXN];

int mpow(int a, int p) {
	int res = 1;
	for (; p > 0; p >>= 1, a = mul(a, a)) {
		if  (p & 1) {
			res = mul(res, a);
		}
	}
	return res;
}

void precalc() {
	segs.clear();
	for (int i = 0, j = 0; i < n; i = j) {
		while (j < n && s[i] == s[j]) {
			++j;
		}
		segs.pb(mp(i, j - 1));
	}

	fact[0] = 1;
	for (int i = 1; i < MAXN; ++i) {
		fact[i] = mul(fact[i - 1], i);
	}

	forn(i, MAXN) {
		inv_fact[i] = mpow(fact[i], MOD - 2);
	}
}

int C(int n, int k) {
	return mul(fact[n], mul(inv_fact[n - k], inv_fact[k]));
}

int CC(int n, int k) {
	return C(n + k - 1, k);
}

int dp[MAXN][MAXN];

int solve() {
	precalc();

	memset (dp, 0, sizeof dp);
	dp[0][0] = 1;
	forn(i, sz(segs)) {
		vi nxt(A, -1);
		for (int j = i; j < sz(segs); ++j) {
			int c = s[segs[j].fst] - 'a';
			if  (nxt[c] == -1) {
				nxt[c] = j;
			}
		}

		int last = i > 0 ? s[segs[i - 1].fst] - 'a' : -1;
		forn(j, n) {
			forn(c, A) {
				if  (c == last) {
					continue;
				}
				if  (nxt[c] == -1) {
					continue;
				}
				add(dp[nxt[c] + 1][j + 1], dp[i][j]);
			}
		}
	}

	int ans = 0;
	for (int cnt = 1; cnt <= n; ++cnt) {
		int cur = 0;
		forn(i, sz(segs) + 1) {
			add(cur, dp[i][cnt]);
		}
		add(ans, mul(cur, CC(n - cnt + 1, cnt - 1)));
	}

	return ans;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		cout << solve() << endl;
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}