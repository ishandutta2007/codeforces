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


int sm(int k) {
	k %= mod;
	return (ll)k*(k + 1) / 2 % mod;
}

int Do(int i, int j, int k) {
	if (!i || !j)return 0;
	int ans = 0;
	int off = 0;
	for (int e = 29; e >= 0; e--) {
		int n = 1 << e;
		if (i < n && j < n) continue;
		else if (j < n)swap(i, j);
		if (i < n) {
			ans += mul(i, sm(min(k,n)));
			if (ans >= mod)ans -= mod;
			ans += mul(off, mul(i, min(k,n)));
			if (ans >= mod)ans -= mod;
			j -= n;
			k -= n;
			if (k <= 0)return ans;
			off += n;
		}
		else {
			ans += mul(n, sm(min(k,n)));
			if (ans >= mod)ans -= mod;
			ans += mul(off, mul(n, min(k,n)));
			if (ans >= mod)ans -= mod;
			i -= n;
			j -= n;
			if (k > n) {
				ans += mul(i, sm(min(k - n,n)));
				if (ans >= mod)ans -= mod;
				ans += mul(off + n, mul(i, min(k - n,n)));
				if (ans >= mod)ans -= mod;

				ans += mul(j, sm(min(k - n,n)));
				if (ans >= mod)ans -= mod;
				ans += mul(off + n, mul(j, min(k - n,n)));
				if (ans >= mod)ans -= mod;
			}
		}
	}
	return ans;
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int q; ni(q);
	F(i, q) {
		int a, b, c, d, k; nii(a, b); nii(c, d); ni(k);
		a--; b--;
		int ans = Do(c, d, k) + Do(a, b, k);
		if (ans >= mod)ans -= mod;
		ans += mod - Do(a, d, k);
		if (ans >= mod)ans -= mod;
		ans += mod - Do(c, b, k);
		if (ans >= mod)ans -= mod;
		printf("%d\n", ans);
	}

}