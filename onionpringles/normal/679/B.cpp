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
#define F(i,n) for(int i = 0; i < n; i++)
#define FF(i,n) for(int i = 1; i <= n; i++)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

const int N = 100000;

ll cub[N + 1];
pair<ll,ll> solve(ll n) {
	if (n == 0) return mp(0,0);
	auto it = upper_bound(cub, cub + N + 1, n) - cub;
	ll val = cub[it - 1];
	ll nval = cub[it - 2];
	ll fi = n - val;
	ll sc = val - 1 - nval;
	auto afi =  solve(fi);
	auto asc =  solve(sc);
	if (afi.first > asc.first) {
		return mp(afi.first + 1, afi.second + val);
	}
	else if (afi.first < asc.first) {
		return mp(asc.first + 1, asc.second + nval);
	}
	else {
		if (afi.second + val > asc.second + nval) {
			return mp(afi.first + 1, afi.second + val);
		}
		else return mp(afi.first + 1, asc.second + nval);
	}
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll m; scanf("%I64d", &m);
	 cub[0] = 0;
	 for (int i = 1; i <= N; i++) {
		 cub[i] = (1LL*i*i*i);
	 }
	 auto p = solve(m);
	 printf("%I64d %I64d\n", p.first, p.second);
	return 0;
}