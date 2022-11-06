#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5;
int n;
ll ans;

namespace bst {
	int lc[maxn + 10], rc[maxn + 10];
	int sz[maxn + 10];
	ll val[maxn + 10], tag1[maxn + 10], tag2[maxn + 10];

	bool rnd(int x, int y) {
		return rand() % (x + y) < x;
	}

	void apply(int p, ll s1, ll s2) {
		if (!p) return;
		val[p] += s1 + sz[lc[p]] * s2;
		tag1[p] += s1; tag2[p] += s2;
	}

	void push(int p) {
		apply(lc[p], tag1[p], tag2[p]);
		apply(rc[p], tag1[p] + (sz[lc[p]] + 1) * tag2[p], tag2[p]);
		tag1[p] = tag2[p] = 0;
	}

	void update(int p) {
		sz[p] = sz[lc[p]] + sz[rc[p]] + 1;
	}

	void split(int p, int k, int &x, int &y) {
		if (!p) x = y = 0;
		else {
			push(p);
			if (k <= sz[lc[p]]) {
				y = p;
				split(lc[p], k, x, p);
				lc[y] = p; update(y);
			} else {
				x = p;
				split(rc[p], k - sz[lc[p]] - 1, p, y);
				rc[x] = p; update(x);
			}
		}
	}

	int merge(int x, int y) {
		if (!x || !y) return x + y;
		if (rnd(sz[x], sz[y])) {
			push(x); rc[x] = merge(rc[x], y);
			update(x); return x;
		} else {
			push(y); lc[y] = merge(x, lc[y]);
			update(y); return y;
		}
	}
	
	ll calc(int p, int k) {
		push(p);
		if (k == sz[lc[p]] + 1) return val[p];
		else if (k <= sz[lc[p]]) return calc(lc[p], k);
		else return calc(rc[p], k - sz[lc[p]] - 1);
	}

	void dfs(int p) {
		if (!p) return;
		push(p); ans = max(ans, val[p]);
		dfs(lc[p]); dfs(rc[p]);
	}

};
int rt;

int main() {
	scanf("%d", &n);
	rt = 1; bst::val[1] = 0; bst::update(1);
	for (int i = 1; i <= n; ++i) {
		int w; scanf("%d", &w);
		int l = 2, r = i + 1;
		while (l != r) {
			int mid = (l + r) >> 1;
			if (bst::calc(rt, mid - 1) + 1ll * w * (mid - 1) > bst::calc(rt, mid)) r = mid;
			else l = mid + 1;
		}
		ll v = bst::calc(rt, l - 1);
		int x, y; bst::split(rt, l - 1, x, y);
		bst::val[i + 1] = v; bst::update(i + 1);
		y = bst::merge(i + 1, y);
		bst::apply(y, 1ll * w * (l - 1), w);
		rt = bst::merge(x, y);
	}
	bst::dfs(rt); printf("%lld", ans);
}