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
#include <limits.h>
#include <tuple>

#define ni(x) scanf("%d", &(x))
#define nii(x,y) scanf("%d%d",&(x),&(y))
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const double pi = 3.1415926535897932384626433832795;
const int mod = 1000000007;

const int MM = 200000;
const int B = 262144;

pii xp[B];
int tr[2 * B];
int dyn[B];
int m;
int upper_bound(int x) {
	int l = 0;
	int u = m + 2;
	while (l!=u) {
		int mid = (l + u) / 2;
		if (xp[mid].first > x) u = mid;
		else l = mid + 1;
	}
	return l;

}

void build() {
	xp[B - 1].second = INT_MAX;
	for (int i = B; i < 2 * B; i++) tr[i] = i - B;
	for (int i = B - 1; i > 0; i--) {
		int c1 = tr[2 * i];
		int c2 = tr[2 * i + 1];
		if (xp[c1].second < xp[c2].second) tr[i] = c1;
		else tr[i] = c2;
	}
}

int get(int nd, int ndl, int ndr, int l, int r) {
	if (l > r || ndl > r || l > ndr) return B - 1;
	else if (l <= ndl && ndr <= r) return tr[nd];
	else {
		int mid = (ndl + ndr) / 2;
		int c1 = get(2 * nd, ndl, mid, l, r);
		int c2 = get(2 * nd + 1, mid + 1, ndr, l, r);
		if (xp[c1].second < xp[c2].second) return c1;
		else return c2;
	}
}

int stk[B];
int sp = -1;

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int d, n;
	nii(d, n); ni(m);
	for (int i = 0; i < m; i++) {
		int xi, pi;
		nii(xi, pi);
		xp[i + 1] = mp(xi, pi);
	}
	xp[m + 1] = mp(d, -1);
	sort(xp, xp + m + 2);
	for (int i = m + 1; i >= 0; i--) {
		while (sp >= 0 && xp[stk[sp]].second >= xp[i].second) sp--;
		if (sp == -1) dyn[i] = m + 2;
		else {
			dyn[i] = stk[sp];
		}
		stk[++sp] = i;
	}
	build();
	int curlit = n;
	int curpos = 0; ll cost = 0;
	while (curpos != m + 1) {
		int dd = dyn[curpos];
		if (dd != m +2 && xp[dd].first - xp[curpos].first <= n) {
			int dist = xp[dd].first - xp[curpos].first;
			int need = max(0, dist - curlit);
			cost += (ll)need*xp[curpos].second;
			curlit = curlit + need - dist;
			curpos = dd;
		}
		else {
			int ub = upper_bound(xp[curpos].first + n);
			if (ub == curpos + 1) {
				puts("-1"); exit(0);
			}
			int g = get(1, 0, B - 1, curpos + 1, ub - 1);
			int need = n - curlit;
			cost += (ll)need*xp[curpos].second;
			int dist = xp[g].first - xp[curpos].first;
			assert(dist <= n);
			curlit = n - dist;
			curpos = g;
		}
	}
	printf("%I64d", cost);

	return 0;
}