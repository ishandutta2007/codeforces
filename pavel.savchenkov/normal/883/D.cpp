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

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define FILE_NAME "a"

const int MAXN = 1e6 + 10;

int n;
char s[MAXN];

bool read() {
	if  (scanf("%d\n", &n) < 1) {
		return 0;
	}
	scanf("%s\n", s);
	return 1;
}

bool solve1() {
	int cnt = 0;
	int any = -1;
	forn(i, n) {
		if  (s[i] == 'P') {
			any = i;
			++cnt;
		}
	}

	assert(cnt >= 1);

	if  (cnt > 1) {
		return 0;
	}

	int l = n;
	int cntl = 0;
	int r = -1;
	int cntr = 0;
	forn(i, n) {
		if  (s[i] == '*') {
			l = min(l, i);
			r = max(r, i);
			if  (i < any) {
				++cntl;
			} else {
				assert(i > any);
				++cntr;
			}
		}
	}

	if  (cntl == cntr) {
		printf("%d %d\n", cntl, min(any - l, r - any));
	} else if  (cntl > cntr) {
		printf("%d %d\n", cntl, any - l);
	} else {
		printf("%d %d\n", cntr, r - any);
	}
	return 1;
}

int prev[MAXN];
int next[MAXN];
int dp[MAXN];

bool get_to_left(int i, int D) {
	assert(s[i] == 'P');
	assert(prev[i] != -1);

	int l = i - D;
	if  (l <= 0) {
		return 1;
	}

	int nxt = next[l];
	if  (s[l] == 'P') {
		nxt = l;
	}
	if  (nxt == prev[i]) {
		return dp[l];
	} else {
		assert(nxt < prev[i]);
		return dp[nxt + 1];
	}
}

bool can(int D) {
	memset (dp, 0, sizeof dp);

	dp[0] = 1;
	forn(i, n) {
		if  (s[i] == '.') {
			dp[i + 1] = dp[i];
			continue;
		}

		if  (s[i] == 'P') {
			int l = max(0, i - D);
			int nxt = next[l];
			if  (s[l] == 'P') {
				nxt = l;
			}
			if  (nxt < i) {
				dp[i + 1] |= dp[nxt + 1];
			} else {
				dp[i + 1] |= dp[l];
			}
			continue;
		}

		assert(s[i] == '*');
		for (int l = prev[i], it = 0; it < 8 && l != -1 && l + D >= i; ++it, l = prev[l]) {
			if  (next[l] < i) {
				dp[i + 1] |= get_to_left(next[l], D);
			} else {
				dp[i + 1] |= dp[l];
			}
		}
	}

	// forn(i, n + 1) {
	// 	eprintf("i=%d, dp=%d\n", i, dp[i]);
	// }

	return dp[n];
}

void solve() {
	if  (solve1()) {
		return;
	}

	int last = -1;
	forn(i, n) {
		prev[i] = last;
		if  (s[i] == 'P') {
			last = i;
		}
	}

	last = n;
	ford(i, n) {
		next[i] = last;
		if  (s[i] == 'P') {
			last = i;
		}
	}

	// can(3);
	// return;

	int L = -1;
	int R = n + 1;
	while (L != R - 1) {
		int M = (L + R) >> 1;
		if  (can(M)) {
			R = M;
		} else {
			L = M;
		}
	}

	int cnt = 0;
	forn(i, n) {
		cnt += (s[i] == '*');
	}
	printf("%d %d\n", cnt, R);
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		solve();
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}