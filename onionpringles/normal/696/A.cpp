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

map<ll, ll> fee;

ll lca(ll u, ll v) {
	if (u == v)return u;
	if (u < v)return lca(u, v / 2);
	else return lca(u / 2, v);
}
ll get(ll u, ll v) {
	ll L = lca(u, v);
	ll ret = 0;
	while (L != u) {
		ret += fee[u];
		u /= 2;
	}
	while (L != v) {
		ret += fee[v];
		v /= 2;
	}
	return ret;
}
void upd(ll u, ll v, ll w) {
	ll L = lca(u, v);
	while (L != u) {
		fee[u] = fee[u] + w;
		u /= 2;
	}
	while (L != v) {
		fee[v] = fee[v] + w;
		v /= 2;
	}
}


int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int Q; ni(Q);
	F(q, Q) {
		int tp; ni(tp);
		if (tp == 1) {
			ll u, v, w; scanf("%I64d%I64d%I64d", &u, &v, &w);
			upd(u, v, w);
		}
		else {
			ll u, v; scanf("%I64d%I64d", &u, &v);
			printf("%I64d\n", get(u, v));
		}
	}

	return 0;
}