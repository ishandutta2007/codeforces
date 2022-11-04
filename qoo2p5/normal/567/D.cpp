#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define sz(x) (int) x.size()
#define INF (int) 1e9
#define LINF (ll) 1e18
#define EPS 1e-8
#define mp(a, b) make_pair(a, b)
#define pb(a, b) push_back(a, b)

int roundpow2(int x) {
	int y = 1;
	while (y < x) {
		y *= 2;
	}

	return y;
}

class SegmentTree {
private:
	vector<pair<int, int>> tree;
	int sz;

	void push(int i) {
		if (tree[i] != mp(-1, -1)) {
			tree[i * 2 + 1] = tree[i];
			tree[i * 2 + 2] = tree[i];
			tree[i] = mp(-1, -1);
		}
	}

	pair<int, int> query(int i, int tl, int tr, int index) {
		if (tl == tr - 1) {
			return tree[i];
		}

		push(i);
		int tm = (tl + tr) / 2;

		if (index < tm) {
			return query(2 * i + 1, tl, tm, index);
		} else {
			return query(2 * i + 2, tm, tr, index);
		}
	}

	void update(int i, int tl, int tr, int l, int r, pair<int, int> val) {
		if (l >= tr || r <= tl) {
			return;
		}

		if (l <= tl && tr <= r) {
			tree[i] = val;
			return;
		}

		if (tl == tr - 1) {
			return;
		}

		push(i);
		int tm = (tl + tr) / 2;
		update(i * 2 + 1, tl, tm, l, r, val);
		update(i * 2 + 2, tm, tr, l, r, val);
	}

public:
	SegmentTree(int n) {
		sz = roundpow2(n);
		tree.resize(2 * sz, mp(-1, -1));

		for (int i = n - 1; i < 2 * n - 1; i++) {
			tree[i] = mp(0, n - 1);
		}
	}

	pair<int, int> query(int index) {
		return query(0, 0, sz, index);
	}

	void update(int l, int r, pair<int, int> val) {
		update(0, 0, sz, l, r + 1, val);
	}
};

int n, k, a;
int m;

int func(int l, int r) {
	return (r - l + 2) / (a + 1);
}

int main() {
	cin >> n >> k >> a >> m;

	SegmentTree tree(n);
	int p = func(0, n - 1);
	int ans = -1;

	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		x--;

		pair<int, int> v = tree.query(x);
		int l = v.first;
		int r = v.second;
		p -= func(l, r);
		p += func(l, x - 1);
		p += func(x + 1, r);
		tree.update(l, x - 1, mp(l, x - 1));
		tree.update(x + 1, r, mp(x + 1, r));

		if (p < k && ans == -1) {
			ans = i + 1;
		}
	}

	cout << ans << endl;

    return 0;
}