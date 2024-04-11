#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5;
int n, q;

namespace seg {

	int ls[maxn * 4 + 10], rs[maxn * 4 + 10];
	ll mn[maxn * 4 + 10], all[maxn * 4 + 10];
	ll tag1[maxn * 4 + 10], tag2[maxn * 4 + 10];
	ll pw[maxn * 4 + 10];

	void update(int p) {
		mn[p] = min(mn[p << 1], mn[p << 1 | 1]);
		all[p] = all[p << 1] == all[p << 1 | 1] ? all[p << 1] : 0;
	}

	void build(int p, int l, int r) {
		ls[p] = l; rs[p] = r;
		if (l == r) {
			ll x; scanf("%lld", &x);
			all[p] = x; 
			ll pw = 1;
			for (; pw < x; pw *= 42);
			mn[p] = pw - x;
		} else {
			int mid = (l + r) >> 1;
			build(p << 1, l, mid); build(p << 1 | 1, mid + 1, r);
			update(p);
		}
	}

	void applyset(int p, ll v) {
		all[p] = v; tag1[p] = v; tag2[p] = 0;
		ll pw = 1;
		for (; pw < v; pw *= 42);
		mn[p] = pw - v;
	}

	void push(int p);

	void applyadd(int p, ll v) {
		if (v <= mn[p]) {
			tag2[p] += v;
			mn[p] -= v; if (all[p]) all[p] += v;
		} else if (all[p]) {
			applyset(p, all[p] + v);
		} else {
			push(p);
			applyadd(p << 1, v);
			applyadd(p << 1 | 1, v);
			update(p);
		}
	}

	void push(int p) {
		if (tag1[p] && tag2[p]) {
			tag1[p] += tag2[p]; tag2[p] = 0;
		}	
		if (tag1[p]) {
			applyset(p << 1, tag1[p]);
			applyset(p << 1 | 1, tag1[p]);
		}
		if (tag2[p]) {
			applyadd(p << 1, tag2[p]);
			applyadd(p << 1 | 1, tag2[p]);
		}
		tag1[p] = tag2[p] = 0;
	}

	void modifyadd(int p, int l, int r, ll v) {
		if (ls[p] == l && rs[p] == r) applyadd(p, v);
		else {
			int mid = (ls[p] + rs[p]) >> 1; push(p);
			if (r <= mid) modifyadd(p << 1, l, r, v);
			else if (l > mid) modifyadd(p << 1 | 1, l, r, v);
			else {
				modifyadd(p << 1, l, mid, v);
				modifyadd(p << 1 | 1, mid + 1, r, v);
			}
			update(p);
		}
	}

	void modifyset(int p, int l, int r, ll v) {
		if (ls[p] == l && rs[p] == r) applyset(p, v);
		else {
			int mid = (ls[p] + rs[p]) >> 1; push(p);
			if (r <= mid) modifyset(p << 1, l, r, v);
			else if (l > mid) modifyset(p << 1 | 1, l, r, v);
			else {
				modifyset(p << 1, l, mid, v);
				modifyset(p << 1 | 1, mid + 1, r, v);
			}
			update(p);
		}
	}

	ll query(int p, int k) {
		if (ls[p] == rs[p]) return all[p];
		else {
			int mid = (ls[p] + rs[p]) >> 1; push(p);
			if (k <= mid) return query(p << 1, k);
			else return query(p << 1 | 1, k);
		}
	}

}

int main() {
	scanf("%d%d", &n, &q);
	seg::build(1, 1, n);
	while (q--) {
		int op, l, r, v;
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d", &v);
			printf("%lld\n", seg::query(1, v));
		} else if (op == 2) {
			scanf("%d%d%d", &l, &r, &v);
			seg::modifyset(1, l, r, v);
		} else if (op == 3) {
			scanf("%d%d%d", &l, &r, &v);
			seg::modifyadd(1, l, r, v);
			while (!seg::mn[1])
				seg::modifyadd(1, l, r, v);
		}
	}
}