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

const int B = 1 << 19;

struct Node {
	int ln, rp, lpn, rpn, h;
	int len;
}tr[B << 1];
Node merge (const Node& L, const Node& R) {
	Node C;
	C.rp = (R.rp == R.len) ? (R.rp + L.rp) : R.rp;
	C.ln = (L.ln == L.len) ? (L.ln + R.ln) : L.ln;
	C.lpn = (L.lpn == L.len) ? (L.lpn + R.ln) : L.lpn;
	if (L.rp == L.len) C.lpn = max(C.lpn, L.rp + R.lpn);
	C.rpn = (R.rpn == R.len) ? (R.rpn + L.rp) : R.rpn;
	if (R.ln == R.len) C.rpn = max(C.rpn, R.ln + L.rpn);
	C.h = max(L.h, R.h);
	C.h = max(C.h, L.rpn + R.ln);
	C.h = max(C.h, R.lpn + L.rp);
	C.len = L.len + R.len;
	return C;
}
const int N = 300000;
ll a[N];
ll b[N];
void single(int i) {
	int j = i;
	i += B; 
	tr[i].lpn = tr[i].rpn = tr[i].h = (b[j] != 0);
	tr[i].ln = (b[j] < 0);
	tr[i].rp = (b[j] > 0);
}
void upd(int i) {
	single(i);
	i += B;
	for (i /= 2; i; i /= 2) {
		tr[i] = merge(tr[i << 1], tr[i << 1 | 1]);
	}
}
Node get(int l, int r, int nd = 1, int ndl = 0, int ndr = B - 1) {
	if (l > ndr || ndl > r) {
		Node r;
		memset(&r, 0, sizeof(r));
		return r;
	}
	else if (l <= ndl && ndr <= r)return tr[nd];
	else {
		int mid = (ndl + ndr) >> 1;
		return merge(get(l, r, nd << 1, ndl, mid), get(l, r, nd << 1 | 1, mid + 1, ndr));
	}
}
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	F(i, B)tr[B + i].len = 1;
	for (int i = B - 1; i; i--)tr[i].len = tr[i << 1].len << 1;
	int n; ni(n);
	F(i, n) {
		int x; ni(x); a[i] = x;
	}
	F(i, n - 1) {
		b[i] = a[i + 1] - a[i];
		single(i);
	}
	for (int i = B - 1; i; i--)tr[i] = merge(tr[i << 1], tr[i << 1 | 1]);
	int m; ni(m);
	F(i, m) {
		int l, r, v; nii(l, r); ni(v); l--; r--;
		if (l > 0) {
			b[l - 1] += v;
			upd(l - 1);
		}
		if (r < n - 1) {
			b[r] -= v;
			upd(r);
		}
		Node nd = get(0, n - 2);
		printf("%d\n", nd.h + 1);
	}
}