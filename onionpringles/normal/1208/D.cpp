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
#include <array>
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
const int mod = 1000000007;
const int inf = 2012345678;
const ll infl = 9012345678901234567;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

const int B = 1 << 18;

pair<ll, int> tr[B << 1]; ll mi[B << 1];

void upd(int l, int r, ll v, int nd = 1,int ndl = 0,int ndr = B - 1) {
	if (l > ndr || ndl > r)return;
	else if (l <= ndl&&ndr <= r) {
		tr[nd].first += v;
		mi[nd] += v;
	}
	else {
		int mid = ndl + ndr >> 1;
		upd(l, r, v, nd << 1, ndl, mid);
		upd(l, r, v, nd << 1 | 1, mid + 1, ndr);
		tr[nd] = min(tr[nd << 1], tr[nd << 1 | 1]);
		tr[nd].first += mi[nd];
	}
}

ll s[201010];
int ans[201010];
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif

	int n; ni(n);
	F(i, n)scanf("%lld", s + i);
	F(i, n) {
		tr[B + i] = { s[i], -i };
	}
	for (int i = n; i < B; i++)tr[B + i] = { infl,0 };
	for (int i = B; --i;)tr[i] = min(tr[i << 1], tr[i << 1 | 1]);

	F(tt, n) {
		auto p = tr[1];
		int j = -p.second;
		ans[j] = tt;
		if (j < n - 1) upd(j + 1, n - 1, -(tt + 1));
		upd(j, j, infl);
	}
	F(i, n)printf("%d ", ans[i] + 1); puts("");


	return 0;
}