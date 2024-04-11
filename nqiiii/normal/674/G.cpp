#include <bits/stdc++.h>
using namespace std;
const int maxn = 1.5e5;
int n, m, p, mx;

struct data {
	int val[5], cnt[5];

	void init(int v, int c) {
		memset(cnt, 0, sizeof cnt);
		val[0] = v; cnt[0] = c;	
	}
};

data operator + (data a, const data &b) {
	for (int i = 0; i < mx; ++i) {
		bool fd = 0; int mn = 1e9;
		for (int j = 0; j < mx; ++j) {
			if (b.val[i] == a.val[j]) {
				a.cnt[j] += b.cnt[i];
				fd = 1; break;
			}
			mn = min(mn, a.cnt[j]);
		}
		if (fd) continue;
		if (b.cnt[i] < mn) {
			for (int j = 0; j < mx; ++j) a.cnt[j] -= b.cnt[i];
			continue;
		} else {
			bool fir = 1;
			for (int j = 0; j < mx; ++j) {
				a.cnt[j] -= mn;
				if (!a.cnt[j] && fir) {
					a.val[j] = b.val[i];
					a.cnt[j] = b.cnt[i] - mn;
					fir = 0;
				}
			}
			assert(!fir);
		}
	}
	return a;
}

namespace seg {
	int ls[maxn * 4 + 10], rs[maxn * 4 + 10];
	data a[maxn * 4 + 10];
	int tag[maxn * 4 + 10];

	void build(int p, int l, int r) {
		ls[p] = l; rs[p] = r;
		if (l == r) {
			int x; scanf("%d", &x);
			a[p].init(x, 1);
		} else {
			int mid = (l + r) >> 1;
			build(p << 1, l, mid); build(p << 1 | 1, mid + 1, r);
			a[p] = a[p << 1] + a[p << 1 | 1];
		}
	}

	void apply(int p, int v) {
		tag[p] = v; a[p].init(v, rs[p] - ls[p] + 1);
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
			a[p] = a[p << 1] + a[p << 1 | 1];
		}
	}

	data query(int p, int l, int r) {
		if (ls[p] == l && rs[p] == r) return a[p];
		else {
			int mid = (ls[p] + rs[p]) >> 1; push(p);
			if (r <= mid) return query(p << 1, l, r);
			else if (l > mid) return query(p << 1 | 1, l, r);
			else return query(p << 1, l, mid) + query(p << 1 | 1, mid + 1, r);
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &p);
	mx = 100 / p;
	seg::build(1, 1, n);
	while (m--) {
		int op, l, r;
		scanf("%d%d%d", &op, &l, &r);
		if (op == 1) {
			int v; scanf("%d", &v);
			seg::modify(1, l, r, v);
		} else {
			data ans = seg::query(1, l, r);
			int s = 0;
			for (int i = 0; i < mx; ++i)
				if (ans.cnt[i]) ++s;
			printf("%d ", s);
			for (int i = 0; i < mx; ++i)
				if (ans.cnt[i]) printf("%d ", ans.val[i]);
			printf("\n");
		}
	}
}