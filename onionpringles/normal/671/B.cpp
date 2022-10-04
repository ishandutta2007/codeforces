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

const int N = 500010;
int a[N]; ll b[N];

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n, k; nii(n, k);
	F(i, n)ni(a[i]);
	sort(a, a + n);
	F(i, n) b[i + 1] = b[i] + a[i];
	int m = (int)(b[n] / n); int M = (int)((b[n] - 1) / n + 1);
	int low = a[0], high = m;
	while (low != high) {
		int mid = (low + high + 1) / 2;
		int i = lower_bound(a, a + n, mid) - a;
		ll need = (ll)mid*i - b[i];
		if (need <= k) low = mid;
		else high = mid - 1;
	}
	int a1 = low;
	low = M, high = a[n - 1];
	while (low != high) {
		int mid = (low + high) / 2;
		int i = upper_bound(a, a + n, mid) - a;
		ll need = b[n] - b[i] - (ll)mid*(n - i);
		if (need <= k) high = mid;
		else low = mid + 1;
	}
	int a2 = low;
	printf("%d\n", a2 - a1);
	return 0;
}

// 0 1 2 3 4