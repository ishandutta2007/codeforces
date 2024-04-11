#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

struct segtree {
	int n, orig;
	vector<ll> tree, tag;
	vector<int> len;
	segtree() {}
	segtree(vector<ll> &a) {
		n = max(2, (int)a.size());
		orig = a.size();
		while (n != (n & -n)) n += (n & -n);
		tree.resize(2 * n);
		len.resize(2 * n, 1);
		tag.resize(2 * n, -1);
		for (int i = 0; i < a.size(); i++)
			tree[i + n - 1] = a[i];
		for (int i = n - 2; i >= 0; i--) {
			tree[i] = tree[i + i + 1] + tree[i + i + 2];
			len[i] = len[i + i + 1] + len[i + i + 2];
		}
	}
	void push(int x) {
		if (tag[x] == -1) return;
		tree[x] = tag[x] * len[x];
		if (x < n - 1) {
			tag[x + x + 1] = tag[x];
			tag[x + x + 2] = tag[x];
		}
		tag[x] = -1;
	}
	void fix(int x) {
		push(x + x + 1), push(x + x + 2);
		tree[x] = tree[x + x + 1] + tree[x + x + 2];
	}
	void upd(int l, int r, int v) {
		upd(l, r, v, 0, 0, n - 1);
	}
	void upd(int l, int r, int v, int node, int nl, int nr) {
		if (r < nl || nr < l) return;
		if (l <= nl && nr <= r) {
			tag[node] = v;
			return;
		}
		push(node);
		int mid = (nl + nr) / 2;
		upd(l, r, v, 2 * node + 1, nl, mid);
		upd(l, r, v, 2 * node + 2, mid + 1, nr);
		fix(node);
	}
	ll query(int l, int r) {
		return query(l, r, 0, 0, n - 1);
	}
	ll query(int l, int r, int node, int nl, int nr) {
		if (r < nl || nr < l) return 0;
		push(node);
		if (l <= nl && nr <= r) {
			return tree[node];
		}
		int mid = (nl + nr) / 2;
		return query(l, r, 2 * node + 1, nl, mid) + query(l, r, 2 * node + 2, mid + 1, nr);
	}
	int first(ll more) {
		return first(more, 0, 0, n - 1);
	}
	int first(ll more, int node, int nl, int nr) {
		push(node);
		if (more >= tree[node]) return min(nr + 1, orig);
		if (nl == nr) return nl;

		int mid = (nl + nr) / 2;
		int res = first(more, 2 * node + 1, nl, mid);
		if (res <= mid) return res;
		return first(more - tree[2 * node + 1], 2 * node + 2, mid + 1, nr);
	}
	int get(int i) {
		i += n - 1;
		int val = tree[i];
		if (tag[i] != -1) val = tag[i];
		while (i > 0) {
			i = (i - 1) / 2;
			if (tag[i] != -1) val = tag[i];
		}
		return val;
	}
};

int n, q;
vector<ll> a;
segtree T;

void upd(int l, int r, int v) {
	int lo = l, hi = r + 1, mid;
	while (lo < hi) {
		mid = (lo + hi) / 2;
		if (T.get(mid) < v)
			hi = mid;
		else
			lo = mid + 1;
	}
	if (lo <= r)
		T.upd(lo, r, v);
}

int findfirst(int i, ll v) {
	int lo = i, hi = n, mid;
	while (lo < hi) {
		mid = (lo + hi) / 2;
		if (T.get(mid) <= v)
			hi = mid;
		else
			lo = mid + 1;
	}
	return lo;
}

int query(int i, ll y) {
	int ans = 0, lo, hi, mid;
	i = findfirst(i, y);
	while (i < n) {
		ll sub = 0;
		if (i > 0) sub = T.query(0, i - 1);
		lo = T.first(y + sub);
		if (OO) {
			cout << "from " << i << " " << lo << '\n';
		}
		ans += lo - i;
		y -= T.query(i, lo - 1);
		i = findfirst(lo, y);
	}
	return ans;
}

void solve() {
	cin >> n >> q;
	a.resize(n);
	for (auto &i : a) cin >> i;
	T = segtree(a);
	while (q--) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1) {
			upd(0, x - 1, y);
		}
		else {
			cout << query(x - 1, y) << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	//cin >> tst;
	while (tst--) solve();
}