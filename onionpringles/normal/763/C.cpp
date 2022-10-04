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

const int N = 100010;
int a[N];
int b[N];

int po(int n, int e, int p) {
	if (!e)return 1;
	int t = po(n, e / 2, p);
	t = (ll)t*t%p;
	if (e & 1)t = (ll)t*n%p;
	return t;
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int m, n; nii(m, n);
	F(i, n)ni(a[i]);
	set<int> s;
	F(i, n) {
		s.insert(a[i]);
	}
	if (n == 1) {
		printf("%d %d\n", a[0], 0);
		 return 0;
	}
	if (n == m) {
		printf("%d %d\n", 0, 1);
		return 0;
	}
	ll sum = 0, sqsum = 0;
	F(i, n) {
		sum += a[i];
		sqsum += (ll)a[i] * a[i];
		sum = sum%m;
		sqsum = sqsum%m;
	}
	ll c1 = (ll)n*(n - 1) / 2 % m;
	ll c2 = (ll)n*(n - 1)*(2*n - 1)/6 % m;
	ll ic1 = po((int)c1, m - 2, m);
	F(i, n) {
		int x = a[i];
		ll c1d = sum - (ll)n*x;
		c1d = c1d%m;
		if (c1d < 0)c1d += m;
		int d = (int)(c1d*ic1%m);
		if (d == 0)continue;
		ll check = 0;
		ll tmp = 0;
		tmp = (ll)n*x%m*x%m;
		check += tmp;
		tmp = 2LL*x*d%m*c1%m;
		check += tmp;
		tmp = (ll)c2*d%m*d%m;
		check += tmp;
		check = check %m;
		if (sqsum != check)continue;
		bool bad = false;
		F(j, n) {
			if (s.find((x + (ll)j*d) % m) == s.end()) {
				bad = true; break;
			}
		}
		if (bad)continue;
		printf("%d %d\n", x, d); return 0;
	}
	puts("-1");
	return 0;
}