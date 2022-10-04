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
const int mod = 1000003;
const int inf = 2012345678;
const ll infl = 9012345678901234567;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

const int N = 201010;
int a[N], b[N];

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif

	int n, m, A, B, k; nii(n, m); nii(A, B); ni(k);
	F(i, n)ni(a[i]);
	F(i, m)ni(b[i]);
	if (k >= n)return puts("-1"), 0;
	int it = 0, ans = -1;
	for (int i = 0; i < n && i <= k; i++) {
		int lf = k - i;
		int arr = a[i] + A;
		while (it < m && b[it] < arr)it++;
		if (it + lf >= m)return puts("-1"), 0;
		ans = max(ans, it + lf);
	}
	printf("%d\n", b[ans] + B);
}