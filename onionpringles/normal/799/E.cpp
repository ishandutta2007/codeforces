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

const int B = 1 << 18;
ll tr[B << 1];
int cnt[B << 1];
const int N = 200000;
pii c[N];

void upd(int i) {
	tr[i + B] = 0;
	cnt[i + B] = 0;
	i = (i + B) / 2;
	for (; i; i /= 2) {
		tr[i] = tr[i << 1] + tr[i << 1 | 1];
		cnt[i] = cnt[i << 1] + cnt[i << 1 | 1];
	}
}
ll get(int l, int r) {
	ll ans = 0;
	for (l += B, r += B; l / 2 != r / 2; l /= 2, r /= 2) {
		if (!(l & 1))ans += tr[l + 1];
		if (r & 1)ans += tr[r - 1];
	}
	return ans;
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n, m, k; nii(n, m); ni(k);
	F(i, n)ni(c[i].first);
	int a; ni(a);
	F(i, a) {
		int x; ni(x);
		c[--x].second |= 1;
	}
	ni(a);
	F(i, a) {
		int x; ni(x);
		c[--x].second |= 2;
	}
	sort(c, c + n);
	F(i, n) {
		tr[B + i] = c[i].first;
		cnt[B + i] = 1;
	}
	vector<int> X[4];
	F(i, n) {
		if (c[i].second) {
			X[c[i].second].push_back(i);
		}
	}
	/*if (X[1].size() + X[3].size() < k || X[2].size() + X[3].size() < k) {
		puts("-1"); return 0;
	}*/
	F(i, n)if (c[i].second == 3)tr[B + i] = 0, cnt[B + i] = 0;
	for (int i = B - 1; i; i--) {
		tr[i] = tr[i << 1] + tr[i << 1 | 1];
		cnt[i] = cnt[i << 1] + cnt[i << 1 | 1];
	}
	int sz = X[3].size();
	ll cur = 0;
	ll c1 = 0, c2 = 0;
	for (auto i : X[3])cur += c[i].first;
	ll ans = infl;
	int i1 = 0;
	for (int num = sz; num >= 0; num--) {
		if (num < sz) cur -= c[X[3][num]].first;
		int nd = k - num - 1;
		if (nd >= (int)X[1].size() || nd >= (int)X[2].size())continue;
		while (i1 <= nd) {
			c1 += c[X[1][i1]].first;
			c2 += c[X[2][i1]].first;
			upd(X[1][i1]);
			upd(X[2][i1]);
			i1++;
		}
		int hi = (num > k) ? num : (k + k - num);
		hi = m - hi;
		if (hi < 0)continue;
		else if (hi == 0) {
			ans = min(ans, cur + c1 + c2);
			continue;
		}
		int cr = 1;
		if (cnt[cr] < hi)continue;
		while (cr < B) {
			if (cnt[cr << 1] >= hi) {
				cr = cr << 1;
			}
			else {
				hi -= cnt[cr << 1];
				cr = cr << 1 | 1;
			}
		}
		assert(cnt[cr] == 1);
		cr -= B;
		ans = min(ans, cur + c1 + c2 + get(-1, cr + 1));
	}
	assert(cur == 0);
	if (ans >= infl)puts("-1");
	else printf("%lld\n", ans);
	return 0;
}