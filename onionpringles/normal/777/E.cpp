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

tuple<int, int, int> t[100000];
const int B = 1 << 17;
ll tr[B << 1];
ll get(int l, int r) {
	ll ans = -infl;
	for (l += B, r += B; l / 2 != r / 2; l /= 2, r /= 2) {
		if (!(l & 1))ans = max(ans, tr[l + 1]);
		if(r&1) ans = max(ans, tr[r - 1]);
	}
	return ans;
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n; ni(n);
	F(i, n) {
		int a, b, h;  nii(a, b); ni(h);
		t[i] = tuple<int, int, int>(b, a, h);
	}
	sort(t, t + n);
	F(i, n) {
		int l = upper_bound(t, t + n, tuple<int, int, int>(get<1>(t[i]), inf, inf)) - t - 1;
		int r = i;
		ll x = get(l, r);
		//printf("%d %d %lld\n", l, r, x);
		x = max(x + get<2>(t[i]), (long long)get<2>(t[i]));
		tr[i + B] = x;
		for (int j = (i + B) / 2; j; j /= 2)tr[j] = max(tr[j << 1], tr[j << 1 | 1]);
	}
	ll ans = -inf;
	F(i, n) {
		ans = max(ans, tr[i + B]);
	}
	printf("%lld\n", ans);

	return 0;
}