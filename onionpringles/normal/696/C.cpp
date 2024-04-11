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

int po(int n, ll e) {
	if (!e)return 1;
	int t = po(n, e / 2);
	t = mul(t, t);
	if (e & 1)t = mul(t, n);
	return t;
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int k; ni(k);
	int x = 2;
	int c = 1;
	F(i, k) {
		ll a; scanf("%I64d", &a);
		x = po(x, a);
		if (a % 2 == 0)c = 0;
	}
	int p, q;
	if (c)p = x - 2;
	else p = x + 2;
	if (p >= mod)p -= mod;
	if (p < mod)p += mod;
	q = mul(3, x);
	int inv2 = (mod + 1) / 2;
	p = mul(p, inv2);
	q = mul(q, inv2);
	int inv3 = (mod + 1) / 3;
	p = mul(p, inv3);
	q = mul(q, inv3);
	printf("%d/%d\n", p, q);
}