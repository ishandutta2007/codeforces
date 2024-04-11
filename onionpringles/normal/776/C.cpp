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

const int N = 100010;
int a[N];
ll p[N];
const int B = 1 << 17;
int tr[B << 1];
void upd(int i, int v) {
	tr[i += B] = v;
	for (i /= 2; i; i /= 2)tr[i] = tr[i << 1] + tr[i << 1 | 1];
}
int get(int l, int r) {
	int re = 0;
	for (l += B, r += B; l / 2 != r / 2; l /= 2, r /= 2) {
		if (!(l & 1))re += tr[l + 1];
		if (r & 1)re += tr[r - 1];
	}
	return re;
}
pair<ll, int> p2[N];
int ind[N];

int get(int i, ll kp, int n) {
	int lb = lower_bound(p2, p2 + n + 1, mp(p[i] + kp, -inf)) - p2;
	int ub = lower_bound(p2, p2 + n + 1, mp(p[i] + kp, inf)) - p2;
	return get(lb - 1, ub);
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n, k; nii(n, k);
	F(i, n) {
		ni(a[i]);
		p[i + 1] = p[i] + a[i];
	}
	FE(i, n)p2[i] = mp(p[i], i);
	sort(p2, p2 + n + 1);
	FE(i, n)ind[p2[i].second] = i;
	FE(i, n)tr[B + i] = 1;
	for (int i = B - 1; i; i--)tr[i] = tr[i << 1] + tr[i << 1 | 1];
	ll ans = 0;
	FE(i, n) {
		upd(ind[i], 0);
		if (k == 1) {
			ans += get(i, 1, n);
		}
		else if (k == -1) {
			ans += get(i, 1, n);
			ans += get(i, -1, n);
		}
		else {
			ll kp = 1;
			while (kp <= 1000000000000000) {
				ans += get(i, kp, n);
				kp *= k;
			}
		}
	}
	printf("%I64d\n", ans);

	return 0;
}