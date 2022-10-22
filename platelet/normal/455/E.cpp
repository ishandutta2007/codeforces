#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define mid (l + r - 1) / 2
#define lch l, mid
#define rch mid + 1, r

using namespace std;
const int N = 1e5 + 5, P = 998244353;
int n, q, a[N], s[N], x[N], y[N], T[N*4], ls[N*100], rs[N*100], sz;
struct line {
	int k, b;
	line(int k = 0, int b = 1e9) :k(k), b(b) {}
	int operator ()(int x) { return k * x + b; }
} c[N*100];
void ins(line x, int l, int r, int& o) {
	if(!o) o = ++sz;
	if(x(mid) < c[o](mid)) swap(x, c[o]);
	if(l < r) { if(x(l) < c[o](l)) ins(x, lch, ls[o]); else ins(x, rch, rs[o]); }
}
int qry(int p, int l, int r, int o) {
	return min(c[o](p), l < r ? p <= mid ? qry(p, lch, ls[o]) : qry(p, rch, rs[o]) : (int)1e9);
}
void bld(int l, int r, int o) {
	rep(i, l, r) ins(line(a[i], i * a[i] - s[i]), 1 - n, 0, T[o]);
	if(l < r) bld(lch, o * 2), bld(rch, o * 2 + 1);
}
int qry(int x, int L, int R, int l, int r, int o) {
	if(L <= l && r <= R) return qry(x, 1 - n, 0, T[o]);
	int res = 1e9;
	if(L <= mid) res = min(res, qry(x, L, R, lch, o * 2));
	if(R > mid) res = min(res, qry(x, L, R, rch, o * 2 + 1));
	return res;
}
int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	cin >> n;
	rep(i, 1, n) scanf("%d", &a[i]), s[i] = s[i-1] + a[i];
	bld(1, n, 1);
	cin >> q;
	for(int x, y; q--; scanf("%d%d", &x, &y), printf("%d\n", s[y] + qry(x - y, y - x + 1, y, 1, n, 1)));
	return 0;
}