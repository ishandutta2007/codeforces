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
#define add(x,y) ((ll)(x)+(y))%mod
#define F(i,n) for(int i = 0; i < (n); i++)
#define FF(i,n) for(int i = 1; i <= (n); i++)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

int C[2000];
int a[2000];

int inv(int n) {
	if (n == 1)return 1;
	else return mul(mod - mod / n, inv(mod%n));
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int n, k; nii(n, k);
	F(i, n)ni(a[i]);
	C[0] = 1;
	F(i, n - 1) {
		C[i + 1] = mul(C[i], k + i);
		C[i + 1] = mul(C[i + 1], inv(i + 1));
	}
	FF(i, n) {
		int ans = 0;
		F(j, i) {
			ans += mul(a[j], C[i - j - 1]);
			if (ans >= mod) ans -= mod;
		}
		printf("%d ", ans);
	}
	puts("");

	return 0;
}