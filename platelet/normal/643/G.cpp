#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define mid (l + r) / 2
#define lch l, mid, o * 2
#define rch mid + 1, r, o * 2 + 1

using namespace std;
const int N = 1.5e5 + 5;
int n, m, p, tag[N*4];
struct node {
	int x[5], c[5];
	node(int xx = 0, int cc = 0) { x[0] = xx, c[0] = cc; For(i, 1, p) x[i] = c[i] = 0; }
	node operator +(const node& b) {
		node r = *this;
		For(i, 0, p) if(b.c[i]) {
			int f = 0;
			For(j, 0, p) if(r.x[j] == b.x[i]) { r.c[j] += b.c[i], f = 1; break; }
			if(!f) {
				int mi = 1e9;
				For(j, 0, p) mi = min(mi, r.c[j]);
				if(mi >= b.c[i]) For(j, 0, p) { if(!(r.c[j] -= b.c[i])) r.x[j] = 0; }
				else For(j, 0, p) {
					if(r.c[j] == mi && !f) r.x[j] = b.x[i], r.c[j] = b.c[i], f = 1;
					if(!(r.c[j] -= mi)) r.x[j] = 0;
				}
			}
		}
		return r;
	}
} c[N*4];
void put(int o, int x, int len) { c[o] = node(x, len), tag[o] = x; }
void pushdown(int o, int len) {
	if(tag[o]) put(o * 2, tag[o], (len + 1) / 2), put(o * 2 + 1, tag[o], len / 2), tag[o] = 0;
}
void bld(int l, int r, int o) {
	if(l == r) { int x; scanf("%d", &x), c[o] = node(x, 1); }
	else bld(lch), bld(rch), c[o] = c[o*2] + c[o*2+1];
}
void upd(int L, int R, int x, int l, int r, int o) {
	if(L <= l && r <= R) return put(o, x, r - l + 1);
	pushdown(o, r - l + 1);
	if(L <= mid) upd(L, R, x, lch);
	if(R > mid) upd(L, R, x, rch);
	c[o] = c[o*2] + c[o*2+1];
}
node qry(int L, int R, int l, int r, int o) {
	if(L <= l && r <= R) return c[o];
	pushdown(o, r - l + 1);
	node res;
	if(L <= mid) res = res + qry(L, R, lch);
	if(R > mid) res = res + qry(L, R, rch);
	return res;
}
int main() {
	cin >> n >> m >> p, p = 100 / p;
	bld(1, n, 1);
	for(int op, l, r, x; m--;) {
		scanf("%d%d%d", &op, &l, &r);
		if(op == 1) scanf("%d", &x), upd(l, r, x, 1, n, 1);
		else {
			node ans = qry(l, r, 1, n, 1);
			printf("%d", p); For(i, 0, p) printf(" %d", ans.x[i]); puts("");
		}
	}
	return 0;
}