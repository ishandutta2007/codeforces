#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5;
int n, a[maxn + 10], pos[maxn + 10];
ll ans;

struct data {
	int mn, c;
};

data operator + (const data &a, const data &b) {
	if (a.mn != b.mn) return a.mn < b.mn ? a : b;
	return (data){a.mn, a.c + b.c};
}

namespace seg {

	data val[maxn * 4 + 10];
	int tag[maxn * 4 + 10], ls[maxn * 4 + 10], rs[maxn * 4 + 10];

	void build(int p, int l, int r) {
		ls[p] = l; rs[p] = r;
		if (l == r) val[p] = (data){0, 1};
		else {
			int mid = (l + r) >> 1;
			build(p << 1, l, mid);
			build(p << 1 | 1, mid + 1, r);
			val[p] = val[p << 1] + val[p << 1 | 1];
		}
	}

	void apply(int p, int v) {
		tag[p] += v; val[p].mn += v;
	}

	void push(int p) {
		if (tag[p]) {
			apply(p << 1, tag[p]); apply(p << 1 | 1, tag[p]);
			tag[p] = 0;
		}
	}

	void modify(int p, int l, int r, int v) {
		if (ls[p] == l && rs[p] == r) apply(p, v);
		else {
			int mid = (ls[p] + rs[p]) >> 1; push(p);
			if (r <= mid) modify(p << 1, l, r, v);
			else if (l > mid) modify(p << 1 | 1, l, r, v);
			else {
				modify(p << 1, l, mid, v);
				modify(p << 1 | 1, mid + 1, r, v);
			}
			val[p] = val[p << 1] + val[p << 1 | 1];
		}
	}

	data query(int p, int l, int r) {
		if (ls[p] == l && rs[p] == r) return val[p];
		else {
			int mid = (ls[p] + rs[p]) >> 1; push(p);
			if (r <= mid) return query(p << 1, l, r);
			else if (l > mid) return query(p << 1 | 1, l, r);
			else return query(p << 1, l, mid) + query(p << 1 | 1, mid + 1, r);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int r, c; scanf("%d%d", &r, &c);
		a[r] = c; pos[c] = r;
	}
	seg::build(1, 1, n);
	for (int i = 1; i <= n; ++i) {
		int p = pos[i];
		seg::modify(1, 1, i, 1);
		if (p > 1 && a[p - 1] < a[p])
			seg::modify(1, 1, a[p - 1], -1);
		if (p < n && a[p + 1] < a[p])
			seg::modify(1, 1, a[p + 1], -1);
		data v = seg::query(1, 1, i);
		if (v.mn == 1) ans += v.c;
	}
	printf("%lld", ans);
}