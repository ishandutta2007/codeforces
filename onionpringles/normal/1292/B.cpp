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
	while (n)n -= n & (-n), x++;
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

ll d(pair<ll, ll> a, pair<ll, ll> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	ll x0, y0, ax, ay, bx, by;
	ll xs, ys, t;
	scanf("%lld%lld%lld%lld%lld%lld", &x0, &y0, &ax, &ay, &bx, &by);
	scanf("%lld%lld%lld", &xs, &ys, &t);

	vector<pair<ll, ll>> V;
	V.emplace_back(x0, y0);
	while (1) {
		ll x = V.back().first*ax + bx;
		ll y = V.back().second*ay + by;
		if (x > xs + t || y > ys + t)break;
		V.emplace_back(x, y);
	}
	int n = V.size();
	int Ans = 0;
	pair<ll, ll> cur = { xs,ys };
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)for (int k = 0; k < n; k++) {
		if (d(cur, V[i]) + d(V[i], V[j]) + d(V[j], V[k]) <= t) {
			Ans = max(Ans, max({ i,j,k }) - min({ i,j,k }) + 1);
		}
	}
	printf("%d\n", Ans);

	return 0;
}