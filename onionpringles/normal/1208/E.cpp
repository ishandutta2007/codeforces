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

ll ans[1010101];
int chk[1010101];
vector<int> V, tr;
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif

	int n, w; nii(n, w);
	ll Ans = 0;
	F(i, n) {
		int d; ni(d);
		int B = 1;
		V.clear(), tr.clear();
		int Max = 0;
		F(j, d) {
			int x; ni(x);
			V.push_back(x);
			Max = max(Max, x);
		}
		Ans += Max;
		while (B < d)B *= 2;
		tr.resize(B << 1);
		F(j, d)tr[B + j] = V[j];
		for (int i = B; --i;)tr[i] = max(tr[i << 1], tr[i << 1 | 1]);
		F(j, w) {
			if (j >= d && j < w - d)break;
			chk[j] = i + 1;
			int R = j, L = j - (w - d);
			int X = -inf;
			for (int l = max(L, 0) + B - 1, r = min(R, d - 1) + B + 1; l / 2 != r / 2; l /= 2, r /= 2) {
				if (!(l & 1))X = max(X, tr[l + 1]);
				if (r & 1)X = max(X, tr[r - 1]);
			}
			if (L < 0 || R >= d)X = max(X, 0);
			ans[j] += X - Max;
		}
		for (int j = w; j--;) {
			if (j >= d && j < w - d)break;
			if (chk[j] == i + 1)break;
			int R = j, L = j - (w - d);
			int X = -inf;
			for (int l = max(L, 0) + B - 1, r = min(R, d - 1) + B + 1; l / 2 != r / 2; l /= 2, r /= 2) {
				if (!(l & 1))X = max(X, tr[l + 1]);
				if (r & 1)X = max(X, tr[r - 1]);
			}
			if (L < 0 || R >= d)X = max(X, 0);
			ans[j] += X - Max;
		}
	}
	F(i, w) {
		printf("%lld ", Ans + ans[i]);
	}
	puts("");

	return 0;
}