#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <complex>
#include <tuple>

#define ni(x) scanf("%d", &(x))
#define nii(x,y) scanf("%d%d",&(x),&(y))
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const double pi = 3.1415926535897932384626433832795;
const int mod = 1000000007;

const int B = 262144;

ll tr_1[2 * B];
ll tr_2[2 * B];
ll dat[B];

void upd(int i, ll val, ll* tr) {
	tr[B + i] = val;
	int cur = (B + i) / 2;
	while (cur) {
		tr[cur] = tr[2 * cur] + tr[2 * cur + 1];
		cur /= 2;
	}
	return;
}

ll get(int nd, int ndl, int ndr, int l, int r, ll* tr) {
	if (l > r) return 0LL;
	else if (ndl > r || l > ndr) return 0LL;
	else if (l <= ndl && ndr <= r) return tr[nd];
	else {
		int mid = (ndl + ndr) / 2;
		return get(2 * nd, ndl, mid, l, r, tr) + get(2 * nd + 1, mid + 1, ndr, l, r, tr);
	}
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, k, a, b, q;
	nii(n, k); nii(a, b); ni(q);
	for (int i = 0; i < q; i++) {
		int tp; ni(tp);
		if (tp == 1) {
			int d, ai;
			nii(d, ai);
			d--;
			dat[d] += ai;
			upd(d, min((ll)b, dat[d]), tr_1);
			upd(d, min((ll)a, dat[d]), tr_2);
		}
		else {
			int p;
			ni(p);
			p--;
			ll ans = get(1, 0, B - 1, 0, p - 1, tr_1);
			ans += get(1, 0, B - 1, p + k, n - 1, tr_2);
			printf("%I64d\n", ans);
		}
	}
	return 0;
}