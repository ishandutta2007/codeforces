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
#define add(x,y) ((ll)(x)+(y))%mod
#define F(i,n) for(int i = 0; i < (n); i++)
#define FF(i,n) for(int i = 1; i <= (n); i++)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

pair<ll,ll> ee(ll a, ll b) {
	ll xx = 1, yy = 0, x = 0, y = 1, zz = a, z = b;
	while (z) {
		ll q = zz / z;

		xx -= x*q;
		swap(xx, x);

		yy -= y*q;
		swap(yy, y);

		zz -= z*q;
		swap(zz, z);
	}
	return mp(xx, yy);
}
ll gcd(ll a, ll b) {
	if (!b) return a;
	else return gcd(b, a%b);
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int n, m, k; nii(n, m); ni(k);

	auto f = [&](ll a, ll b) {
		ll g = gcd(2 * n, 2 * m);
		if ((b - a) % g != 0) return 9000000000000000000LL;;
		ll N = 2 * n / g;
		ll M = 2 * m / g;
		auto P = ee(N, M);
		ll X = P.first * ((b - a) / g);
		ll NUM = -2 * n*X - a;
		ll K;
		if (NUM <= 0) K = NUM / (2 * n*M);
		else K = (NUM - 1) / (2 * n*M)+1;
		X += M*K;
		return 2*n*X + a;
	};

	F(i, k) {
		int x, y; nii(x, y);
		ll a1, a2, a3, a4;
		a1 = f(x, y);
		a2 = f(x, -y);
		a3 = f(-x, y);
		a4 = f(-x, -y);
		ll ans = min(min(a1, a2), min(a3, a4));
		if (ans == 9000000000000000000LL) puts("-1");
		else printf("%I64d\n", ans);
	}
	

	return 0;
}