#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10; 

struct Node {
	int c, lch, rch;
}	o[N * 21];
int cnt = 0, rt[N];

void Mdf(int &p, int lst, int l, int r, int s) {
	o[p = ++cnt] = o[lst], o[p].c++;
	if (l == r) return; int mid = (l + r) >> 1;
	if (s <= mid) Mdf(o[p].lch, o[lst].lch, l, mid, s);
	else Mdf(o[p].rch, o[lst].rch, mid + 1, r, s);
}

int Qry(int p, int l, int r, int tl, int tr) {
	if (tl <= l && r <= tr) return o[p].c;
	int mid = (l + r) >> 1, ret = 0;
	if (tl <= mid) ret += Qry(o[p].lch, l, mid, tl, tr);
	if (tr > mid) ret += Qry(o[p].rch, mid + 1, r, tl, tr);
	return ret; 
}

int n, m, a[N], b[N], mb[N], lst;

int f(int x) {
	return (x - 1 + lst) % n + 1;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]), mb[b[i]] = i;
	for (int i = 1; i <= n; i++)
		Mdf(rt[i], rt[i - 1], 1, n, mb[a[i]]);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
		int l1 = min(f(a), f(b)), r1 = max(f(a), f(b)),
			l2 = min(f(c), f(d)), r2 = max(f(c), f(d));
		lst = Qry(rt[r1], 1, n, l2, r2) - Qry(rt[l1 - 1], 1, n, l2, r2);
		printf("%d\n", lst); lst++; 
	}
	return 0;
}