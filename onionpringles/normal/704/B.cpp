#pragma warning(disable:4996)

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <complex>
#include <iterator>
#include <random>
#include <time.h>
#include <tuple>
#include <functional>
#include <list>
#include <limits.h>
#define mp make_pair
#define ni(x) scanf("%d", &(x))
#define nii(x,y) scanf("%d%d",&(x),&(y))
#define mul(x,y) ((ll)(x)*(y)%mod)
#define mtp make_tuple
#define F(i,n) for(int i = 0; i < (n); i++)
#define FF(i,n) for(int i = 1; i <= (n); i++)
#define FE(i,n) for(int i = 0; i <= (n); i++)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const ll infl = 9012345678901234567;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

const int N = 5010;
ll dp[N][N];
int x[N], a[N], b[N], c[N], d[N];
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n, s, e; ni(n); nii(s, e);
	FF(i, n)ni(x[i]);
	FF(i, n)ni(a[i]);
	FF(i, n)ni(b[i]);
	FF(i, n)ni(c[i]);
	FF(i, n)ni(d[i]);
	FE(i, n)FE(j, n)dp[i][j] = infl;
	dp[0][0] = 0;
	int es = 0, ee = 0;
	FF(i, n - 1) {
		if (i == s)es++;
		if (i == e)ee++;
		int j = 1;
		if (es || ee) j = 0;
		for (; j <= i - es - ee;j++) {
			if (i == s) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + x[i] + c[i]);
				dp[i][j] = min(dp[i][j], dp[i - 1][j] - x[i] + d[i]);
			}
			else if (i == e) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + x[i] + a[i]);
				dp[i][j] = min(dp[i][j], dp[i - 1][j] - x[i] + b[i]);
			}
			else {
				dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + 2 * x[i] + a[i] + c[i]);
				if (j + ee > 0)dp[i][j] = min(dp[i][j], dp[i - 1][j] + b[i] + c[i]);
				if (j + es > 0)dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i] + d[i]);
				if (j > 0)dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + b[i] + d[i] - 2 * x[i]);
			}
		}
	}
	ll ans;
	if (n == s)ans = dp[n - 1][0] + x[n] + c[n];
	else if (n == e)ans = dp[n - 1][0] + x[n] + a[n];
	else ans = dp[n - 1][0] + 2 * x[n] + c[n] + a[n];
	printf("%I64d\n", ans);
	return 0;
}