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

const int N = 1 << 21;
int a[N], d[N], q[N], qs, qe, chk[N], clk = 100;

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n; ni(n);
	F(i, n)ni(a[i]);
	int ans = 0;
	for (int i = n; i--;) {
		int curmask = 0;
		for (int j = 21; j--;) {
			if (a[i] & 1 << j)continue;
			if (d[curmask | 1 << j] > 1) {
				curmask |= 1 << j;
			}
		}
		if(i < n - 2) ans = max(ans, a[i] | curmask);
		qs = qe = 0;
		++clk;
		if (d[a[i]] < 2) {
			d[a[i]]++;
			chk[a[i]] = clk;
			q[qe++] = a[i];
		}
		while (qs < qe) {
			int u = q[qs++];
			F(j, 21) {
				if (!(u & 1 << j))continue;
				if (d[u ^ 1 << j] < 2 && chk[u ^ 1 << j] != clk) {
					chk[u ^ 1 << j] = clk;
					d[u ^ 1 << j]++;
					q[qe++] = u ^ 1 << j;
				}
			}
		}
	}
	printf("%d\n", ans);


	return 0;
}