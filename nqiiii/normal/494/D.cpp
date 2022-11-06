#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5, maxq = 5000, mod = 1e9 + 7;
int n, dfn[maxn + 10], ed[maxn + 10], dcnt;
int dep[maxn + 10], val[maxn + 10], q;
vector<pair<int, int> > ask[maxn + 10];
int ans[maxn + 10];

struct edge {
	int to, w;
};
vector<edge> g[maxn + 10];

void dfs(int p, int fa) {
	dfn[p] = ++dcnt;
	val[dcnt] = dep[p];
	for (auto i: g[p]) {
		if (i.to != fa) {
			dep[i.to] = (dep[p] + i.w) % mod;
			dfs(i.to, p);
		}
	}
	ed[p] = dcnt;
}

namespace seg {
	int ls[maxn * 4 + 10], rs[maxn * 4 + 10];
	int s1[maxn * 4 + 10], s2[maxn * 4 + 10], tag[maxn * 4 + 10];

	void upd(int p) {
		s1[p] = (s1[p << 1] + s1[p << 1 | 1]) % mod;
		s2[p] = (s2[p << 1] + s2[p << 1 | 1]) % mod;
	}

	void build(int p, int l, int r) {
		ls[p] = l; rs[p] = r;
		if (l == r) {
			s1[p] = val[l];
			s2[p] = 1ll * val[l] * val[l] % mod;
		} else {
			int mid = (l + r) >> 1;
			build(p << 1, l, mid); build(p << 1 | 1, mid + 1, r);
			upd(p);
		}
	}

	void apply(int p, int v) {
		int len = rs[p] - ls[p] + 1;
		(s2[p] += (1ll * v * v % mod * len + 2ll * v * s1[p]) % mod) %= mod;
		(s1[p] += 1ll * len * v % mod) %= mod;
		(tag[p] += v) %= mod;
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
			upd(p);
		}
	}

	int query(int p, int l, int r) {
		if (ls[p] == l && rs[p] == r) return s2[p];
		else {
			int mid = (ls[p] + rs[p]) >> 1; push(p);
			if (r <= mid) return query(p << 1, l, r);
			else if (l > mid) return query(p << 1 | 1, l, r);
			else return (query(p << 1, l, mid) + query(p << 1 | 1, mid + 1, r)) % mod;
		}
	}
}

int adj(int x) {
	return (x % mod + mod) % mod;
}

void dfsans(int p, int fa) { 
	for (auto i: ask[p]) {
		int w = i.first;
		int s1 = seg::query(1, dfn[w], ed[w]);
		int s2 = seg::query(1, 1, n);
		s2 = adj(s2 - s1);
		s2 = adj(s1 - s2);
		ans[i.second] = s2;
	}
	for (auto i: g[p]) {
		if (i.to != fa) {
			seg::modify(1, 1, n, i.w);
			seg::modify(1, dfn[i.to], ed[i.to], adj(-i.w * 2));
			dfsans(i.to, p);
			seg::modify(1, 1, n, adj(-i.w));
			seg::modify(1, dfn[i.to], ed[i.to], i.w * 2 % mod);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int l, r, w; scanf("%d%d%d", &l, &r, &w);
		g[l].push_back((edge){r, w});
		g[r].push_back((edge){l, w});
	}
	dfs(1, 0);
	seg::build(1, 1, n);
	scanf("%d", &q);
	for (int i = 1; i <= q; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		ask[x].push_back(make_pair(y, i));
	}
	dfsans(1, 0);
	for (int i = 1; i <= q; ++i)
		printf("%d\n", ans[i]);
}