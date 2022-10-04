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
const ll infl = 9012345678901234567;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

typedef long double ld;
typedef complex<ld> point;
const int N = 100000;
point a, b, r, bot[N];
ld d[N], e[N];
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int x, y;
	nii(x, y); a = point(x, y);
	nii(x, y); b = point(x, y);
	nii(x, y); r = point(x, y);
	int n; ni(n);
	F(i, n) {
		nii(x, y); bot[i] = point(x, y);
	}
	if (n == 1) {
		printf("%.15f\n", (double)(min(abs(a - bot[0]), abs(b - bot[0])) + abs(bot[0] - r)));
		return 0;
	}
	ld S = 0;
	F(i, n) S += 2 * abs(bot[i] - r);
	F(i, n) {
		d[i] = abs(bot[i] - r) - abs(bot[i] - a);
		e[i] = abs(bot[i] - r) - abs(bot[i] - b);
	}
	int j = max_element(d, d + n) - d;
	int k = max_element(e, e + n) - e;
	ld ans = S - max(d[j], e[k]);
	x = (j + 1) % n;
	F(i, n) {
		if (i == j)continue;
		if (e[i] > e[x]) x = i;
	}
	ans = min(ans, S - d[j] - e[x]);
	x = (k + 1) % n;
	F(i, n) {
		if (i == j)continue;
		if (d[i] > d[x]) x = i;
	}
	ans = min(ans, S - d[x] - e[k]);
	printf("%.15f\n", (double)ans);
	return 0;
}