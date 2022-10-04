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

int a[101010];

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif

	int n;
	ni(n);
	F(i, n)ni(a[i]);
	sort(a, a + n);
	ll s = 0;
	F(i, n)s += a[i];
	s -= 1LL*n*(n - 1) / 2;

	int j = -1;
	F(i, n - 1) {
		if (a[i] == a[i + 1]) {
			j = i;
			break;
		}
	}
	if (j == -1) {
		if (s % 2 == 0)puts("cslnb");
		else puts("sjfnb");
		return 0;
	}
	if (a[j] == 0)return puts("cslnb"), 0;
	a[j]--; s--;
	F(i, n - 1) {
		if (a[i] == a[i + 1])return puts("cslnb"), 0;
	}
	if (s % 2 == 1)puts("cslnb");
	else puts("sjfnb");

	return 0;
}