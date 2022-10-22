#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define lch l, mid, ls[o]
#define rch mid + 1, r, rs[o]
#define lb(a, b) lower_bound(a + 1, a + n + 1, q[i].b) - a

using namespace std;
const int N = 1e5 + 5, MI = 1e6;
int read() {
	static streambuf* in = cin.rdbuf();
	#define gc (p1 == p2 && (p2 = (p1 = buf) + in -> sgetn(buf, MI), p1 == p2) ? -1 : *p1++)
	static char buf[MI], *p1, *p2;
	int c = gc, r = 0;
	while(c < 48) c = gc;
	while(c > 47) r = (r << 3) + (r << 1) + (c & 15), c = gc;
	return r;
}
void wrt(int x) {
	static streambuf* out = cout.rdbuf();
	#define pc out -> sputc
	static char ch[11]; int sz = 0;
	if(!x) pc(48);
	else {
		while(x) ch[++sz] = x % 10, x /= 10;
		while(sz) pc(ch[sz--] + 48);
	} pc(10);
}
struct Qry { int a, t, x; } q[N];
int n, gt[N], gx[N], sz, T[N], ls[N*17], rs[N*17], cnt[N*17];
void upd(int p, int v, int l, int r, int& o) {
	cnt[o ? o : o = ++sz] += v;
	if(l == r) return;
	int mid = (l + r) >> 1;
	if(p <= mid) upd(p, v, lch); else upd(p, v, rch);
}
int qry(int p, int l, int r, int o) {
	if(r <= p) return cnt[o];
	int mid = (l + r) >> 1, ret = qry(p, lch);
	return ret + (p > mid ? qry(p, rch) : 0);
}
int main() {
	#ifdef local
		freopen("in.txt", "r", stdin);
	#endif
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	n = read();
	rep(i, 1, n) q[i].a = read(), gt[i] = q[i].t = read(), gx[i] = q[i].x = read();
	sort(gt + 1, gt + n + 1), sort(gx + 1, gx + n + 1);
	rep(i, 1, n) {
		int t = lb(gt, t), x = lb(gx, x);
		if(q[i].a == 3) wrt(qry(t, 1, n, T[x]));
		else upd(t, q[i].a == 1 ? 1 : -1, 1, n, T[x]);
	}
	return 0;
}