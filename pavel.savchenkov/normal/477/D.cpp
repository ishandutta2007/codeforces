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
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define all(C) begin(C), end(C)

#define debug(x) cerr << #x" = " << x << '\n';

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
const int MAXN = 5e3 + 5;
const int MOD = int(1e9 + 7);
const int INF = int(1e9);

void add(int& x, int y) {
	if  ((x += y) >= MOD)
		x -= MOD;
}

int mul(int x, int y) {
	return x * 1ll * y % MOD;
}

bool a[MAXN];
int dp[MAXN][MAXN];
int z[MAXN][MAXN];
int n;
char buf[MAXN];
int cnt[MAXN];

// a[i ... i + len - 1] > a[i + len .. i + len + len - 1]
bool smaller(int i, int len) {
	int Z = z[i][i + len];
	if  (Z >= len) {
		return false;
	}
	return a[i + Z] > a[i + len + Z];
}

int main() {
	gets(buf);
	n = strlen(buf);
	forn(i, n) {
		a[i] = buf[i] == '1';
	}

	memset (z, 0, sizeof z);
	for (int start = 0; start < n; ++start) {
		int l = start;
		int r = l - 1;
		z[start][start] = 0;
		for (int i = start + 1; i < n; ++i) {
			if  (l <= i && i <= r) {
				z[start][i] = min(r - i + 1, z[start][start + (i - l)]);
			}

			while (i + z[start][i] < n && a[i + z[start][i]] == a[start + z[start][i]]) ++z[start][i];

			if  (i + z[start][i] - 1 > r) {
				l = i;
				r = i + z[start][i] - 1;
			}
		}	
	}

	// dp[i][len] -- [0 .. i] -> [0 ... ] + ... + [i ... i + len - 1]

	// calc how many
	memset (dp, 0, sizeof dp);
	// i == 0
	dp[0][1] = 1;

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int cur_dp = dp[i][0];
		for (int len = 1; i + len - 1 < n; ++len) {
			add(cur_dp, dp[i][len]);

			if  (i + len - 1 == n - 1) {
				add(ans, cur_dp);
			}

			if  (!cur_dp || !a[i + len]) {
				continue;
			}

			if  (!smaller(i, len)) {
				add(dp[i + len][len], cur_dp);
			} else {
				add(dp[i + len][len + 1], cur_dp);
			}
		}	
	}

	printf("%d\n", ans);

	// calc min
	int pw2 = 1;
	cnt[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; --i) {
		pw2 = mul(pw2, 2);
		cnt[i] = cnt[i + 1];
		if  (a[i]) {
			add(cnt[i], pw2);
		}
	}

	forn(i, n + 1) {
		forn(len, n + 1) {
			dp[i][len] = INF;
		}
   	}
   	dp[0][1] = 1;

	ans = INF;
	int min_len = INF;
	for (int i = 0; i < n; ++i) {
		int cur_dp = dp[i][0];
		for (int len = 1; i + len - 1 < n; ++len) {
			cur_dp = min(cur_dp, dp[i][len]);

			if  (cur_dp >= INF) {
				continue;
			}

			if  (i + len - 1 == n - 1) {
				if  (len > 25) {
					int cur_ans = cur_dp;
					add(cur_ans, cnt[i]);
					if  (len < min_len) {
						ans = cur_ans;
						min_len = len;
					}
				} else {
					if  (min_len > 25) {
						ans = cur_dp + cnt[i];
						min_len = len;
					} else {
						if  (cur_dp + cnt[i] < ans) {
							ans = cur_dp + cnt[i];
							min_len = len;
						}
					}
				}
			}

			if  (!a[i + len]) {
				continue;
			}

			if  (!smaller(i, len)) {
				dp[i + len][len] = min(dp[i + len][len], cur_dp + 1);
			} else {
				dp[i + len][len + 1] = min(dp[i + len][len + 1], cur_dp + 1);
			}
		}	
	}

	printf("%d\n", ans);
	return 0;
}