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

const int MAXN = 8e3 + 10;
const int INF = 1e9;

int n;
char s[MAXN];

bool read() {
	scanf("%s\n", s);
	n = int(strlen(s));
	return 1;
}

int p[MAXN];

void calc(char* s, int n) {
	p[0] = 0;
	for (int i = 1; i < n; ++i) {
		int j = p[i - 1];
		while (j > 0 && s[i] != s[j]) {
			j = p[j - 1];
		}
		if  (s[i] == s[j]) {
			++j;
		}
		p[i] = j;
	}
}

int dp[MAXN];

int len_num[MAXN];

void precalc() {
	len_num[0] = 1;
	for (int i = 1; i < MAXN; ++i) {
		int ans = 0;
		int x = i;
		while (x) {
			++ans;
			x /= 10;
		}
		len_num[i] = ans;
	}
}

int solve() {
	forn(i, n + 1) {
		dp[i] = INF;
	}
	forn(i, n) {
		calc(s + i, n - i);

		const int was = i ? dp[i - 1] : 0;
		for (int j = i; j < n; ++j) {
			const int suff = p[j - i];
			const int len = j - i + 1;
			const int pref = len - suff;
			assert(pref > 0);
			int cnt = 1;
			if  (len % pref == 0) {
				cnt = len / pref;
			}
			dp[j] = min(dp[j], was + len_num[cnt] + (len / cnt));
			// eprintf("remin dp[j=%d], i=%d, cnt=%d, len=%d, len_num=%d := %d\n", j, i, cnt, len, len_num[cnt], was + len_num[cnt] + (len / cnt));
		}
	}
	return dp[n - 1];
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	precalc();

	while (read()) {
		printf("%d\n", solve());

		break;
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}