#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define lowbit i & -i

using namespace std;
const int N = 2e5 + 5, MI = 1e6;
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
int n, m, cnt, p[N], b[N], c[N], ans[N];
void add(int i, int v) {
	for(; i <= n; i += lowbit) c[i] += v;
}
int qry(int i, int r = 0) {
	for(; i; i -= lowbit) r += c[i];
	return r;
}
struct Qry {
	int id, x, l, r, w;
	bool operator <(const Qry& b)const { return x < b.x; }
} q[N*5];
void cdq(int l, int r) {
	if(l == r) return;
	int mid = (l + r) >> 1, i = l;
	cdq(l, mid), cdq(mid + 1, r);
	sort(q + l, q + mid + 1), sort(q + mid + 1, q + r + 1);
	rep(j, mid + 1, r) {
		for(; i <= mid && !(q[j] < q[i]); i++)
		if(!q[i].id) add(q[i].l, q[i].w);
		ans[q[j].id] += q[j].w * (qry(q[j].r) - qry(q[j].l - 1));
	}
	rep(j, l, i - 1) if(!q[j].id) add(q[j].l, -q[j].w);
}
int main() {
	#ifdef local
		freopen("in.txt", "r", stdin);
	#endif
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	n = read(), m = read();
	rep(i, 1, n) p[read()] = i;
	rep(i, 1, n) q[++cnt] = (Qry){ 0, i, b[i] = p[read()], 0, 1 };
	rep(i, 1, m) if(read() == 1) {
		int la = read(), ra = read(), lb = read(), rb = read();
		q[++cnt] = (Qry){ i, rb, la, ra, 1 };
		q[++cnt] = (Qry){ i, lb - 1, la, ra, -1 };
	} else {
		ans[i] = -1;
		int x = read(), y = read();
		q[++cnt] = (Qry){ 0, x, b[x], 0, -1 };
		q[++cnt] = (Qry){ 0, y, b[y], 0, -1 };
		swap(b[x], b[y]);
		q[++cnt] = (Qry){ 0, x, b[x], 0, 1 };
		q[++cnt] = (Qry){ 0, y, b[y], 0, 1 }; 
	}
	cdq(1, cnt);
	rep(i, 1, m) if(~ans[i]) wrt(ans[i]);
	return 0;
}