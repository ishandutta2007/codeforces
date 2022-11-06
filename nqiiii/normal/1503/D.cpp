#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 5e5 + 10;
int n;
typedef int ll;

struct seg {
	int ls[maxn * 4 + 10], rs[maxn * 4 + 10];
	ll tag[maxn * 4 + 10], val[maxn * 4 + 10];

	void build(int p, int l, int r) {
		ls[p] = l; rs[p] = r;
		tag[p] = 0;
		val[p] = inf;
		if (l != r) {
			int mid = (l + r) >> 1;
			build(p << 1, l, mid); build(p << 1 | 1, mid + 1, r);
		}
	}

	void apply(int p, ll v) {
		tag[p] = min(tag[p] + v, inf);
		val[p] = min(val[p] + v, inf);
	}

	void push(int p) {
		if (tag[p]) {
			apply(p << 1, tag[p]);
			apply(p << 1 | 1, tag[p]);
			tag[p] = 0;
		}
	}

	void change(int p, int k, int v) {
		if (ls[p] == rs[p]) val[p] = min(val[p], v);
		else {
			int mid = (ls[p] + rs[p]) >> 1; push(p);
			if (k <= mid) change(p << 1, k, v);
			else change(p << 1 | 1, k, v);
			val[p] = min(val[p << 1], val[p << 1 | 1]);
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
			val[p] = min(val[p << 1], val[p << 1 | 1]);
		}
	}

	ll query(int p, int l, int r) {
		if (ls[p] == l && rs[p] == r) return val[p];
		int mid = (ls[p] + rs[p]) >> 1; push(p);
		if (r <= mid) return query(p << 1, l, r);
		if (l > mid) return query(p << 1 | 1, l, r);
		return min(query(p << 1, l, mid), query(p << 1 | 1, mid + 1, r));
	}

	void dfsout(int p) {
		if (ls[p] == rs[p]) printf("%d ", val[p]);
		else {
			push(p);
			dfsout(p << 1); dfsout(p << 1 | 1);
		}
	}
}s[2];

struct dt {
	int a, b, d;

	bool operator < (const dt &t) const {
		return a < t.a;
	}

}a[maxn + 10];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &a[i].a, &a[i].b);
		if (a[i].a > a[i].b) {
			swap(a[i].a, a[i].b);
			a[i].d = 1;
		}
	}
	sort(a + 1, a + n + 1);
	a[0].b = 2 * n + 1;
	s[0].build(1, 1, 2 * n + 1);
	s[1].build(1, 1, 2 * n + 1);
	s[0].change(1, 2 * n + 1, 0);
	s[1].change(1, 2 * n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		int v0 = s[0].query(1, a[i].b + 1, 2 * n + 1);
		int v1 = s[1].query(1, a[i].b + 1, 2 * n + 1);
		if (a[i].b < a[i - 1].b) {
			s[0].modify(1, 1, 2 * n + 1, a[i].d ^ 1);
			s[1].modify(1, 1, 2 * n + 1, a[i].d);
		} else {
			s[0].modify(1, 1, 2 * n + 1, inf);
			s[1].modify(1, 1, 2 * n + 1, inf);
		}
		s[0].change(1, a[i - 1].b, v1 + (a[i].d ^ 1));
		s[1].change(1, a[i - 1].b, v0 + a[i].d);
	}
	int ans = min(s[0].query(1, 2 * n + 1, 2 * n + 1), s[1].query(1, 2 * n + 1, 2 * n + 1));
	for (int i = 1; i < n; ++i) {
		if (a[i].b < a[n].a) continue;
		if (a[i].a > a[n].b) continue;
		ans = min(ans, s[0].query(1, a[i].b, a[i].b));
		ans = min(ans, s[1].query(1, a[i].b, a[i].b));
	}
	printf("%d", ans >= inf ? -1 : ans);
}