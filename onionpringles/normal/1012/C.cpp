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

#ifndef __GNUG__
int __builtin_popcount(int n) {
	int x = 0;
	while (n)n -= n&(-n), x++;
	return x;
}
#endif

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 998244353;
const int inf = 2012345678;
const ll infl = 9012345678901234567;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

int dp[2510][5010],dpm[2510][5010];
int a[5010];
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n; ni(n);
	F(i, n)ni(a[i]);
	a[n] = -100;
	for (int k = 1; k <= (n + 1) / 2; k++)for (int i = 0; i <= n;i++) dp[k][i] = inf;
	for (int k = 1; k <= (n + 1) / 2; k++) {
		for (int i = k + k - 1; i <= n; i++) {
			int x = (a[i - 1] > a[i]) ? 0 : (a[i] - a[i - 1] + 1);
			if (k > 1) {
				int x = (a[i - 1] > a[i]) ? 0 : (a[i] - a[i - 1] + 1);
				x += dp[k - 1][i - 2];
				int cr = a[i - 2];
				if (a[i - 2] >= a[i - 3])cr = a[i - 3] - 1;
				x += (cr < a[i - 1]) ? 0 : (cr - a[i - 1] + 1);
				dp[k][i] = x;
				if (i == k + k - 1)continue;
			}
			if (i >= 2)x += (a[i - 2] < a[i - 1]) ? 0 : (a[i - 2] - a[i - 1] + 1);
			if (k > 1) x += dpm[k - 1][i - 3];
			dp[k][i] = min(dp[k][i], x);
		}
		dpm[k][0] = inf;
		for (int i = 1; i <= n; i++) {
			dpm[k][i] = min(dpm[k][i - 1], dp[k][i]);
		}
		printf("%d ", dpm[k][n]);
	}
	puts("");
}