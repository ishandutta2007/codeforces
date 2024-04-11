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

const int B = 1 << 17;
struct Node {
	ll cnt[10];
	int modv[10];
	bool mod;
	Node() {
		F(i, 10)modv[i] = i;
		mod = false;
	}
}tr[B << 1];

void push(int nd) {
	if (!tr[nd].mod)return;
	if (nd >= B) return;
	int lnd = nd << 1;
	{
		vector<ll> ncnt(10);
		F(i, 10) {
			int ni = tr[nd].modv[i];
			ncnt[ni] += tr[lnd].cnt[i];
			tr[lnd].modv[i] = tr[nd].modv[tr[lnd].modv[i]];
		}
		F(i, 10)tr[lnd].cnt[i] = ncnt[i];
		tr[lnd].mod = true;
	}
	lnd = nd << 1 | 1;
	{
		vector<ll> ncnt(10);
		F(i, 10) {
			int ni = tr[nd].modv[i];
			ncnt[ni] += tr[lnd].cnt[i];
			tr[lnd].modv[i] = tr[nd].modv[tr[lnd].modv[i]];
		}
		F(i, 10)tr[lnd].cnt[i] = ncnt[i];
		tr[lnd].mod = true;
	}
	tr[nd].mod = false;
	F(i, 10)tr[nd].modv[i] = i;
}
long long calc(int nd) {
	ll ans = 0;
	F(i, 10) {
		ans += (ll)i*tr[nd].cnt[i];
	}
	return ans;
}
void upd(int l, int r, int x, int y, int nd = 1, int ndl = 0, int ndr = B - 1) {
	if (l > ndr || ndl > r)return;
	else if (l <= ndl && ndr <= r) {
		tr[nd].cnt[y] += tr[nd].cnt[x];
		tr[nd].cnt[x] = 0;
		tr[nd].mod = true;
		F(i, 10) {
			if (tr[nd].modv[i] == x) tr[nd].modv[i] = y;
		}
	}
	else {
		push(nd);
		int mid = (ndl + ndr) / 2;
		upd(l, r, x, y, nd << 1, ndl, mid);
		upd(l, r, x, y, nd << 1 | 1, mid + 1, ndr);
		F(i, 10)tr[nd].cnt[i] = tr[nd << 1].cnt[i] + tr[nd << 1 | 1].cnt[i];
	}
}
ll gg(int l, int r, int nd = 1, int ndl = 0, int ndr = B - 1) {
	if (l > ndr || ndl > r)return 0LL;
	else if (l <= ndl && ndr <= r) {
		return calc(nd);
	}
	else {
		push(nd);
		int mid = (ndl + ndr) / 2;
		return gg(l, r, nd << 1, ndl, mid) + gg(l, r, nd << 1 | 1, mid + 1, ndr);
	}
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n, q; nii(n, q);
	F(i, n) {
		int x; ni(x);
		int p = 1;
		while (x) {
			tr[B + i].cnt[x % 10] += p;
			p *= 10;
			x /= 10;
		}
	}
	for (int i = B - 1; i; i--) {
		F(j, 10) {

			tr[i].cnt[j] = tr[i << 1].cnt[j] + tr[i << 1 | 1].cnt[j];

		}
	}
	F(qq, q) {
		int tp; ni(tp);
		if (tp == 1) {
			int l, r, x, y; nii(l, r); nii(x, y);
			if (x == y)continue;
			l--; r--;
			upd(l, r, x, y);
		}
		else {
			int l, r; nii(l, r); l--; r--;
			printf("%lld\n", gg(l, r));
		}
	}
	return 0;
}