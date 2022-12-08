#include <stdio.h>
#include <bits/stdc++.h>
#define pi pair<int,int>
#define mp make_pair
#define pb push_back
#define vec vector<pi > 
#define fi first
#define se second
#define mid ((l + r) >> 1)

using namespace std;

const int N = 150010;

int n, m, k, a[N], ln[N << 2], lz[N << 2];
vec nod[N << 2];

vec M(vec A, vec B) {
	for (auto i : B) {
		int flag = false;
		for (auto &j : A) if (j.fi == i.fi) {
			j.se += i.se, flag = true; break;
		}
		if (!flag) A.pb(i);
	}
	while (A.size() > k) {
		int s = -1, M = n + 1, c = 0;
		for (int i = 0; i <= k; i++) if(A[i].se < M)
			M = A[i].se, s = i;
		for (int i = 0; i <= k; i++) A[i].se -= M;
		for (int i = 0; i <= k; i++) if(!A[i].se) swap(A[c++], A[i]);
		A.erase(A.begin(), A.begin() + c);
	}
	return A;
}

void B(int p, int l, int r) {
	ln[p] = r - l + 1;
	if(l == r) return (void)(nod[p].pb(mp(a[l], 1)));
	B(p << 1, l, mid), B(p << 1 | 1, mid + 1, r);
	nod[p] = M(nod[p << 1], nod[p << 1 | 1]);
}

void U(int p, int x) {
	nod[p].clear(), nod[p].pb(mp(x, ln[p])), lz[p] = x;
}

void P(int p) {
	if (lz[p]) U(p << 1, lz[p]), U(p << 1 | 1, lz[p]), lz[p] = 0;
}

void A(int p, int l, int r, int tl, int tr, int x) {
	if (tl <= l && r <= tr) return U(p, x); P(p);
	if (tl <= mid) A(p << 1, l, mid, tl, tr, x);
	if (tr > mid) A(p << 1 | 1, mid + 1, r, tl, tr, x);
	nod[p] = M(nod[p << 1], nod[p << 1 | 1]);
}

vec Q(int p, int l, int r, int tl, int tr) {
	if (tl <= l && r <= tr) return nod[p]; P(p); vec C;
	if (tl <= mid) C = M(C, Q(p << 1, l, mid, tl, tr));
	if (tr > mid) C = M(C, Q(p << 1 | 1, mid + 1, r, tl, tr));
	return C;
}

int main() {
	scanf("%d%d%d", &n, &m, &k), k = 100 / k;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	B(1, 1, n);
	for (int i = 1; i <= m; i++) {
		int o, l, r, x; scanf("%d%d%d", &o, &l, &r);
		if(o == 1) scanf("%d", &x), A(1, 1, n, l, r, x);
		else {
			vec A = Q(1, 1, n, l, r); printf("%d ", (int)A.size());
			for (auto j : A) printf("%d ", j.fi);
			printf("\n");
		}
	}
	return 0;
}