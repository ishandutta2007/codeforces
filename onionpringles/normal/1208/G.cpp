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

const int N = 1010101;

int ph[N], a[N];
vector<pii> V;

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	for (int i = 1; i < N; i++) {
		ph[i] += i;
		for (int j = i + i; j < N; j += i)ph[j] -= ph[i];
	}
	ll ans = 0;
	int n, k; nii(n, k);
	for (int i = 1; i <= n; i++)if (i % 2 == 1)V.emplace_back(ph[i], i);
	sort(V.begin(), V.end());
	if ((int)V.size() >= k + 1) {
		F(j, k + 1)ans += V[j].first;
	}
	else ans = infl;
	V.clear();
	ll ans2 = 0;
	for (int i = 1; i <= n; i++)V.emplace_back(ph[i], i);
	sort(V.begin(), V.end());
	F(j, k + 2)ans2 += V[j].first;
		
	printf("%lld\n", min(ans, ans2));

	return 0;
}