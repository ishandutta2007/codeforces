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

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const ll infll = 9000000000000000000LL;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

char buf[101010];
int dp[101010];
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	scanf("%s", buf + 1);
	int n = strlen(buf + 1);
	dp[0] = 0;
	int cnt = 0;
	FF(i, n) {
		cnt += (buf[i] == '#');
		dp[i] = dp[i - 1] + ((buf[i] == '(') ? 1 : -1);
		if (dp[i] < 0) {
			puts("-1"); return 0;
		}
	}
	int ans = inf;
	for (int i = n; i; i--) {
		ans = min(ans, dp[i]);
		if (buf[i] == '#') {
			break;
		}
	}
	if (dp[n] != ans) {
		puts("-1"); return 0;
	}
	F(i, cnt - 1) puts("1");
	printf("%d\n", ans + 1);
	

	return 0;
}