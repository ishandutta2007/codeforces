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

char b[101010];

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif

	set<int> S, T;
	int n, m; nii(n, m);
	scanf("%s", b);
	F(i, n)if (b[i] == '0')S.insert(i);

	bool good = false;
	F(i, n - m + 1) {
		int L = inf, R = -inf;
		if (S.size() && *S.begin() < i)L = min(L, i);
		auto it = S.lower_bound(i);
		if (it != S.begin()) {
			it = prev(it);
			R = max(R, *it);
		}
		if (S.size() && *prev(S.end()) >= i + m)R = max(R, *prev(S.end()));
		it = S.lower_bound(i + m);
		if (it != S.end()) {
			L = min(L, *it);
		}
		if (L == inf)return puts("tokitsukaze"), 0;
		if (R - L >= m) good = true;
	}
	S.clear();
	F(i, n)if (b[i] == '1')S.insert(i);
	F(i, n - m + 1) {
		int L = inf, R = -inf;
		if (S.size() && *S.begin() < i)L = min(L, i);
		auto it = S.lower_bound(i);
		if (it != S.begin()) {
			it = prev(it);
			R = max(R, *it);
		}
		if (S.size() && *prev(S.end()) >= i + m)R = max(R, *prev(S.end()));
		it = S.lower_bound(i + m);
		if (it != S.end()) {
			L = min(L, *it);
		}
		if (L == inf)return puts("tokitsukaze"), 0;
		if (R - L >= m) good = true;
	}
	if (!good)puts("quailty");
	else puts("once again");
	return 0;
}