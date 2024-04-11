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

int a[120][5];

int cnt[5];
int m[5];
pair<int, int> tog(int x, int y, int e, bool slv) {
	if (!slv) {
		if (e < 5 && (1LL << (e + 1))*(ll)x <= y) {
			return{ 0,-1 };
		}
		else if (e < 5) {
			return{ max(0, x*(1 << e) - y), x*(1 << (e + 1)) - y - 1 };
		}
		else {
			return{ 32 * x - y , mod };
		}
	}
	if (e < 5) {
		if (x*(1 << (e + 1)) <= y) {
			int D = (1 << (e + 1)) - 1;
			return{ (y - x*(1 << (e + 1))) / D + 1, mod };
		}
		else if (x*(1 << e) > y) {
			return{ (1 << e)*x - y, inf };
		}
		else return{ 0,mod };
	}
	else {
		if (32 * x > y) {
			return{ 32 * x - y, mod };
		}
		else return{ 0,mod };
	}
}
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n; ni(n);
	F(i, n) {
		F(j, 5) {
			ni(a[i][j]);
			if (a[i][j] >= 0) cnt[j]++;
		}
	}
	int TOT = 6 * 6 * 6 * 6 * 6;
	int ans = inf;
	for (int mk = 0; mk < TOT; mk++) {
		int t = mk;
		F(j, 5) {
			m[j] = t % 6;
			t /= 6;
		}
		int X = 0, Y = 0;
		F(j, 5) {
			if (a[0][j] != -1) X += (250 - a[0][j]) * 2 * (m[j] + 1);
			if (a[1][j] != -1) Y += (250 - a[1][j]) * 2 * (m[j] + 1);
		}
		if (X <= Y)continue;
		pii in = { 0,mod };
		F(j, 5) {
			auto p = tog(cnt[j], n, m[j], a[0][j] != -1);
			in.first = max(in.first, p.first);
			in.second = min(in.second, p.second);
		}
		if (in.first <= in.second) {
			ans = min(ans, in.first);
		}
	}
	if (ans == inf)puts("-1");
	else printf("%d\n", ans);
	return 0;
}