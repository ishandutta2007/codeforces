#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define mid ((l + r) >> 1)
#define lch l, mid, o << 1
#define rch mid + 1, r, o << 1 | 1

using namespace std;
const int N = 1e5 + 5;
int n, q;
struct node {
	double A, B;
	node operator* (const node& b) {
		return (node){ A * b.A, A * b.B + B };
	}
} c[N*4];
void bld(int l, int r, int o) {
	if(l == r) {
		int a, b; scanf("%d%d", &a, &b); 
		c[o].A = 1.0 * b / a - 1, c[o].B = 1;
	} else bld(lch), bld(rch), c[o] = c[o<<1] * c[o<<1|1];
}
void upd(int p, double x, int l, int r, int o) {
	if(l == r) return c[o].A = x, void();
	if(p <= mid) upd(p, x, lch); else upd(p, x, rch);
	c[o] = c[o<<1] * c[o<<1|1];
}
node qry(int L, int R, int l, int r, int o) {
	if(L <= l && r <= R) return c[o];
	node res = { 1, 0 };
	if(L <= mid) res = res * qry(L, R, lch);
	if(R > mid) res = res * qry(L, R, rch);
	return res;
}
int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	cin >> n >> q, bld(1, n, 1);
	int ps, a, b;
	while(q--) {
		scanf("%d", &ps);
		if(ps == 1) scanf("%d%d%d", &ps, &a, &b), upd(ps, 1.0 * b / a - 1, 1, n, 1);
		else {
			scanf("%d%d", &a, &b);
			node res = qry(a, b, 1, n, 1);
			double ans = 1 / (res.A + res.B);
			printf("%.8lf\n", isnan(ans) ? 0 : ans);
		}
	}
	return 0;
}