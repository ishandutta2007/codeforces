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

const int N = 1000000;
int a[N];
int b[N], c[N];
ll bs, cs;

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n; ni(n);
	F(i, n) {
		ni(a[i]);
		a[i]--;
	}
	vector<pii> V;
	F(i, n) {
		if (i > a[i]) {
			b[i] = 1;
			c[i] = i - a[i];
		}
		else {
			b[i] = -1;
			c[i] = a[i] - i;
		}
		V.emplace_back((a[i] - i + n) % n, i);
	}
	sort(V.begin(), V.end());
	F(i, n)bs += b[i], cs += c[i];
	pair<ll, int> ans = { infl,0 };
	int r = 0;
	F(t, n) {
		ans = min(ans, { bs*t + cs, t });
		while (r < n && V[r].first == t) {
			int i = V[r].second;
			bs -= b[i];
			cs -= c[i];
			b[i] = 1;
			c[i] = -t;
			bs += b[i];
			cs += c[i];
			r++;
		}
		int i = n - 1 - t;
		bs -= b[i];
		cs -= c[i];
		b[i] = -1;
		c[i] = t + a[i] + 1;
		bs += b[i];
		cs += c[i];
	}

	printf("%lld %d\n", ans.first, ans.second);

	return 0;
}