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
const int MAXN = int(1e3) + 10;
const int MAXSUM = int(1e4) + 10;
const int MOD = int(1e9) + 7;

int add( int a, int b ) {
	if  ((a += b) >= MOD)
		a -= MOD;
	return a;
}

int mul( int a, int b ) {
	return a * 1ll * b % MOD;
}

int dp[MAXN][2 * MAXSUM];
int a[MAXN];
int pref_sum[MAXN];
int n;

inline int code( int sum ) {
	return sum + pref_sum[n] + 1;
}

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	scanf("%d", &n);
	pref_sum[0] = 0;
	forn(i, n) {
		scanf("%d", &a[i]);
		pref_sum[i + 1] = pref_sum[i] + a[i];
	}

	memset (dp, 0, sizeof dp);
	dp[0][code(0)] = 1;
	int res = 0;
	forn(i, n + 1) {
		for (int sum = -pref_sum[i + 1]; sum <= pref_sum[i + 1]; sum++) {
			int cur_dp = dp[i][code(sum)];

			if  (cur_dp) {
				dp[i + 1][code(sum + a[i])] = add(dp[i + 1][code(sum + a[i])], cur_dp);
				dp[i + 1][code(sum - a[i])] = add(dp[i + 1][code(sum - a[i])], cur_dp);
			}
		}

		dp[i + 1][code(0)] = add(dp[i + 1][code(0)], 1);

		res = add(res, dp[i][code(0)]);
		res = add(res, -1 + MOD);
	}

	printf("%d\n", res);
	return 0;
}