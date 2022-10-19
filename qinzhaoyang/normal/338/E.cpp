#include <stdio.h>
#include <bits/stdc++.h>
#define lep(i, j, k) for (int i = (j); i <= (k); i++)
#define rep(i, j, k) for (int i = (j); i >= (k); i--)
#define Lep(i, j, k) for (int i = (j); i < (k); i++)
#define Rep(i, j, k) for (int i = (j); i > (k); i--)

using namespace std;

const int N = 150010;

struct Node {
	int s, Min, lch, rch, t, lzy, k;
	Node() {Min = 0x3f3f3f3f;}
}	o[N]; int cnt = 0, rt = 0;

void PushUp(int x) {
	o[x].Min = min(o[x].t, min(o[o[x].lch].Min, o[o[x].rch].Min));
	o[x].s = o[o[x].lch].s + o[o[x].rch].s + 1;
}

void Update(int x, int y) {
	if (!x) return;
	o[x].Min += y, o[x].t += y, o[x].lzy += y;
}

void PushDown(int x) {
	if (o[x].lzy) {
		Update(o[x].lch, o[x].lzy);
		Update(o[x].rch, o[x].lzy);
		o[x].lzy = 0;
	}
}

int Merge(int x, int y) {
	if (!x || !y) return x + y; PushDown(x), PushDown(y);
	if (rand() % (o[x].s + o[y].s) < o[x].s)
		return o[x].rch = Merge(o[x].rch, y), PushUp(x), x;
	else return o[y].lch = Merge(x, o[y].lch), PushUp(y), y;
}

void Split(int w, int key, int &x, int &y) {
	if (!w) return x = 0, y = 0, void(); PushDown(w);
	if (o[w].k <= key) x = w, Split(o[w].rch, key, o[x].rch, y);
	else y = w, Split(o[w].lch, key, x, o[y].lch); PushUp(w);
}

int n, m, h, a[N], b[N], ans;

void Insert(int x) {
	int sh = lower_bound(b + 1, b + m + 1, h - a[x]) - b;
	// cout << "Run " << x << " " << sh << " " << a[x] << endl;
	sh = m - sh + 1;
	++cnt; o[cnt].k = a[x];
	int d, f; Split(rt, a[x], d, f);
	o[cnt].t = sh - o[d].s - 1;
	Update(f, -1), PushUp(cnt);
	rt = Merge(Merge(d, cnt), f);
}

void Del(int x) {
	int d, f, g;
	Split(rt, a[x] - 1, d, f), Split(f, a[x], f, g);
	Update(o[f].rch, 1), Update(g, 1);
	rt = Merge(Merge(d, Merge(o[f].lch, o[f].rch)), g);
}

void output(int x) {
	if (!x) return; PushDown(x);
	output(o[x].lch);
	cout << o[x].k << " " << o[x].t << endl;
	output(o[x].rch);
}

int main() {
	scanf("%d%d%d", &n, &m, &h);
	lep (i, 1, m) scanf("%d", &b[i]);
	lep (i, 1, n) scanf("%d", &a[i]);
	sort (b + 1, b + m + 1);
	lep (i, 1, m) Insert(i);
	ans += o[rt].Min >= 0;
	lep (i, m + 1, n) {
		Del(i - m), Insert(i);
		ans += o[rt].Min >= 0;
	}
	printf("%d\n", ans);
	return 0;
}