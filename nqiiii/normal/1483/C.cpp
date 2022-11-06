#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5;
int n;
int s[maxn + 10], scnt;
int b[maxn + 10], h[maxn + 10];;
ll f[maxn + 10];

namespace seg {
	int ls[maxn * 4 + 10], rs[maxn * 4 + 10];
	ll tag[maxn * 4 + 10], val[maxn * 4 + 10];

	void build(int p, int l, int r) {
		ls[p] = l; rs[p] = r;
		tag[p] = val[p] = 0;
		if (l != r) {
			int mid = (l + r) >> 1;
			build(p << 1, l, mid); build(p << 1 | 1, mid + 1, r);
		}
	}

	void apply(int p, ll v) {
		tag[p] += v; val[p] += v;
	}

	void push(int p) {
		if (tag[p]) {
			apply(p << 1, tag[p]);
			apply(p << 1 | 1, tag[p]);
			tag[p] = 0;
		}
	}

	void modify(int p, int l, int r, ll v) {
		if (l > r) return;
		if (ls[p] == l && rs[p] == r) apply(p, v);
		else {
			int mid = (ls[p] + rs[p]) >> 1;
			push(p);
			if (r <= mid) modify(p << 1, l, r, v);
			else if (l > mid) modify(p << 1 | 1, l, r, v);
			else {
				modify(p << 1, l, mid, v);
				modify(p << 1 | 1, mid + 1, r, v);
			}
			val[p] = max(val[p << 1], val[p << 1 | 1]);
		}
	}

	ll query(int p, int l, int r) {
		if (ls[p] == l && rs[p] == r) return val[p];
		int mid = (ls[p] + rs[p]) >> 1; push(p);
		if (r <= mid) return query(p << 1, l, r);
		if (l > mid) return query(p << 1 | 1, l, r);
		return max(query(p << 1, l, mid), query(p << 1 | 1, mid + 1, r));
	}

	void dfsout(int p) {
		if (ls[p] == rs[p]) printf("%lld ", val[p]);
		else {
			push(p);
			dfsout(p << 1); dfsout(p << 1 | 1);
		}
	}
}

void popback() {
	//printf("{%d %d %d}\n", s[scnt], b[s[scnt - 1]], b[s[scnt]]);
	seg::modify(1, s[scnt - 1] + 1, n, -b[s[scnt]] + b[s[scnt - 1]]);
	//seg::dfsout(1); printf("\n");
	--scnt;
}

void pushback(int k) {
	//printf("{%d %d %d}\n", k, b[k], b[s[scnt]]);
	seg::modify(1, s[scnt] + 1, n, -b[s[scnt]] + b[k]);
	//seg::dfsout(1); printf("\n");
	s[++scnt] = k;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &h[i]);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &b[i]);
	seg::build(1, 1, n);
	for (int i = 1; i <= n; ++i) {
		while (scnt && h[i] < h[s[scnt]])
			popback();
		pushback(i);
		f[i] = seg::query(1, 1, i);
		//printf("|%d %lld|\n", i, f[i]);
		if (i < n) seg::modify(1, i + 1, i + 1, f[i]);
	}
	printf("%lld", f[n]);
}