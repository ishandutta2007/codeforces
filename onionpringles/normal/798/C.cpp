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

int a[101010];
int g(int a, int b) { return b == 0 ? a : g(b, a%b); }
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	puts("YES");
	int n; ni(n);
	F(i, n)ni(a[i]);
	int c = 0;
	F(i, n)c = g(c, a[i]);
	if (c > 1) {
		puts("0");
		return 0;
	}
	int ans = 0;
	for (int i = 0; i < n;) {
		if (a[i] % 2 == 0) {
			i++;
			continue;
		}
		int j = i;
		while (j < n && a[j] % 2 == 1)j++;
		if ((j - i) % 2 == 0)ans += (j - i) / 2;
		else ans += (j - i) / 2 + 2;
		i = j;
	}
	printf("%d\n", ans);
	return 0;
}