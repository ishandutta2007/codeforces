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

const int MAXN = 1e6 + 10;

int n, k;
int p[MAXN];

bool read() {
	// n = 1e6;
	// k = 1e6 - 100;
	// forn(i, n) {
	// 	if  (i & 1) {
	// 		p[i] = (i + 1) % n;
	// 	} else {
	// 		p[i] = (i - 1 + n) % n; 
	// 	}
	// }
	// return 1;

	if  (scanf("%d%d", &n, &k) < 2) {
		return 0;
	}
	forn(i, n) {
		scanf("%d", &p[i]);
		--p[i];
	}
	return 1;
}

bool used[MAXN];
bool dp[2][MAXN];

void solve() {
	vi lens;
	memset (used, 0, sizeof used);
	forn(i, n) {
		if  (!used[i]) {
			int cur = 1;
			int j = p[i];
			while (j != i) {
				++cur;
				used[j] = 1;
				j = p[j];
			}
			lens.pb(cur);
		}
	}

	memset (dp, 0, sizeof dp);
	vi cnt(n + 1, 0);
	for (int len : lens) {
		++cnt[len];
	}
	int c = 0;
	dp[c][0] = 1;
	int pref = 0;
	for (int len = 1; len <= n; ++len) {
		int Cnt = cnt[len];
		if  (!Cnt) {
			continue;
		}	
		Cnt *= len;
		pref += Cnt;
		forn(shift, len) {
			int sum = 0;
			for (int i = shift; i <= pref; i += len) {
				dp[c ^ 1][i] = sum > 0 || dp[c][i];
				sum += dp[c][i];
				if  (i - Cnt >= 0) {
					sum -= dp[c][i - Cnt];
				}
			}
		}
		memset (dp[c], 0, sizeof dp[c]);
		c ^= 1;
	}

	if  (dp[c][k]) {
		printf("%d ", k);
	} else {
		printf("%d ", k + 1);
	}

	int mx = 0;
	for (int len : lens) {
		if  (len % 2 == 0) {
			int use = min(k, len / 2);
			mx += use * 2;
			k -= use;
		}
	}
	for (int len : lens) {
		if  (len % 2 == 1) {
			int use = min(k, len / 2);
			mx += use * 2;
			k -= use;
		}
	}
	for (int len : lens) {
		if  (len % 2 == 1 && k > 0) {
			--k;
			++mx;
		}
	}
	printf("%d\n", mx);
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	// FFT::precalc();

	while (read()) {
		solve();

		break;
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}