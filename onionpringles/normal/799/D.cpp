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

const int N = 100000;
int v[N];
const int B = 1 << 17;
int tr[B << 1];
void init() {
	F(i, B << 1)tr[i] = inf;
}
void upd(int i, int v) {
	for (i += B; i; i /= 2)tr[i] = min(tr[i], v);
}
int get(int l, int r) {
	int ans = inf;
	for (l += B, r += B; l / 2 != r / 2; l /= 2, r /= 2) {
		if (!(l & 1))ans = min(ans, tr[l + 1]);
		if (r & 1)ans = min(ans, tr[r - 1]);
	}
	return ans;
}
pair<pii,int> mx[1 << 18];
pair<pii,int> my[1 << 18];

int solve(int a, int b, int w, int h) {
	int X = (w + a - 1) / w;
	int Y = (h + b - 1) / h;
	int ans = inf;
	int j = 1 << 18;
	init();
	FF(i, (1 << 18) - 1) {
		int A = mx[i].first.first;
		int B = mx[i].first.second;
		int C = (X + A - 1) / A;
		int E = (Y + B - 1) / B;
		while (j > 1 && my[j - 1].first.first >= C) {
			j--;
			int D = my[j].first.second;
			upd(D, my[j].second);
		}
		ans = min(ans, mx[i].second + get(E - 1, ::B));
	}
	return ans;
}
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int a, b, h, w, n;
	nii(a, b); nii(h, w); ni(n);
	F(i, n)ni(v[i]);
	if (n <= 34) for (int j = n; j < 34; j++)v[j] = 1;
	sort(v, v + n, greater<int>());
	FF(mk, (1 << 18) - 1) {
		int end;
		for (end = 17; end; end--)if (mk&(1 << end))break;
		pii q, w;
		q = w = { 1,1 };
		F(i, end) {
			if (mk&(1 << i)) {
				if (q.first <= N / v[i])q.first *= v[i];
				else q.first = N;
				if (w.first <= N / v[17 + i])w.first *= v[17 + i];
				else w.first = N;
			}
			else {
				if (q.second <= N / v[i])q.second *= v[i];
				else q.second = N;
				if (w.second <= N / v[17 + i])w.second *= v[17 + i];
				else w.second = N;
			}
		}
		mx[mk] = make_pair(q, end);
		my[mk] = make_pair(w, end);
	}
	sort(mx + 1, mx + (1 << 18));
	sort(my + 1, my + (1 << 18));
	int ans = min(solve(a, b, w, h), solve(b, a, w, h));
	if (ans >= inf)puts("-1");
	else printf("%d\n", ans);
	return 0;
}