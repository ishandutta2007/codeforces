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

const int B = 1 << 19;
int tr[B << 1];
int a[300000];
int ans[300000];
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n; ni(n);
	F(i, n)ni(a[i]);
	if (n == 1) {
		printf("%d\n", a[0]);
		return 0;
	}
	for (int i = 1; i < n - 1; i++) {
		if (a[i] > a[i - 1] && a[i] > a[i + 1])tr[B + i] = max(a[i - 1], a[i + 1]);
		else tr[B + i] = a[i];
	}
	for (int i = B - 1; i; i--)tr[i] = max(tr[i << 1], tr[i << 1 | 1]);
	ans[n - 1] = *max_element(a, a + n);
	for (int i = n - 3; i >= 0; i -= 2) {
		int L = (n - i) / 2;
		int R = n - 1 - L;
		int M = -inf;
		for (L += B - 1, R += B + 1; L / 2 != R / 2; L /= 2, R /= 2) {
			if (!(L & 1))M = max(M, tr[L + 1]);
			if (R & 1)M = max(M, tr[R - 1]);
		}
		ans[i] = M;
	}
	for (int i = 1; i < n - 2; i++) {
		int cr = max(a[i], a[i + 1]);
		int nx = max(a[i + 1], a[i + 2]);
		int ps = max(a[i - 1], a[i]);
		if (cr > nx && cr > ps)tr[B + i] = max(nx, ps);
		else tr[B + i] = cr;
	}
	for (int i = B - 1; i; i--)tr[i] = max(tr[i << 1], tr[i << 1 | 1]);
	ans[n - 2] = *max_element(a, a + n);
	for (int i = n - 4; i >= 0; i -= 2) {
		int L = (n - i) / 2 - 1;
		int R = n - 2 - L;
		int M = -inf;
		for (L += B - 1, R += B + 1; L / 2 != R / 2; L /= 2, R /= 2) {
			if (!(L & 1))M = max(M, tr[L + 1]);
			if (R & 1)M = max(M, tr[R - 1]);
		}
		ans[i] = M;
	}
	F(i, n)printf("%d ", ans[i]); puts("");
	return 0;
}