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

int a[1010][1010];

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif

	int n; ni(n);
	F(i, n * n / 4) {
		int Y = i % (n / 2);
		int X = i / (n / 2);
		a[X * 2][Y * 2] = 4 * i;
		a[X * 2][Y * 2 + 1] = 4 * i + 2;
		a[X * 2 + 1][Y * 2] = 4 * i + 1;
		a[X * 2 + 1][Y * 2 + 1] = 4 * i + 3;
	}
	F(i, n) {
		F(j, n)printf("%d ", a[i][j]); puts("");
	}


	return 0;
}