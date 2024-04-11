#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 0;
using namespace std;

struct fenwick {
	int n;
	vector<int> t;
	fenwick(int sz) {
		n = sz;
		t.resize(n + 1, 0);
	}
	void add(int i) {
		for (i++; i <= n; i += (i & -i)) t[i]++;
	}
	int query(int x) {
		int ans = 0;
		for (x++; x; x -= (x & -x)) ans += t[x];
		return ans;
	}
	int query(int l, int r) {
		return query(r) - query(l - 1);
	}
};

struct segtree {
	int n;
	vector<int> t, tag;
	segtree(int sz) {
		n = max(2, sz);
		while (n != (n & -n)) n += (n & -n);
		t.resize(2 * n, -md);
		tag.resize(2 * n, 0);
	}
	void push(int x) {
		t[x] += tag[x];
		if (x < n - 1) {
			tag[2 * x + 1] += tag[x];
			tag[2 * x + 2] += tag[x];
		}
		tag[x] = 0;
	}
	void fix(int x) {
		push(2 * x + 1), push(2 * x + 2);
		t[x] = max(t[2 * x + 1], t[2 * x + 2]);
	}
	void set(int i, int v) {
		set(i, v, 0, 0, n - 1);
	}
	void set(int i, int v, int node, int nl, int nr) {
		if (nl == nr) {
			tag[node] = 0;
			t[node] = v;
			return;
		}
		push(node);
		int mid = (nl + nr) / 2;
		if (i <= mid) set(i, v, 2 * node + 1, nl, mid);
		else set(i, v, 2 * node + 2, mid + 1, nr);
		fix(node);
	}
	void add(int l, int r, int v) {
		add(l, r, v, 0, 0, n - 1);
	}
	void add(int l, int r, int v, int node, int nl, int nr) {
		if (nr < l || r < nl) return;
		if (l <= nl && nr <= r) {
			tag[node] += v;
			return;
		}
		push(node);
		int mid = (nl + nr) / 2;
		add(l, r, v, 2 * node + 1, nl, mid);
		add(l, r, v, 2 * node + 2, mid + 1, nr);
		fix(node);
	}
	int query(int l, int r) {
		if (l > r) return -md;
		return query(l, r, 0, 0, n - 1);
	}
	int query(int l, int r, int node, int nl, int nr) {
		if (nr < l || r < nl) return -md;
		push(node);
		if (l <= nl && nr <= r) {
			return t[node];
		}
		int mid = (nl + nr) / 2;
		return max(query(l, r, 2 * node + 1, nl, mid), query(l, r, 2 * node + 2, mid + 1, nr));
	}
};

int n;
vector<int> a;

void solve() {
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i, --i;
	vector<int> b(n);
	for (int i = 0; i < n; i++)
		b[a[i]] = i;

	fenwick F(n);
	segtree T(n);
	int ans = 0;

	vector<int> used(n, 0);
	int nxt = 0;
	for (auto &i : b) {
		if (OO) {
			cout << "start " << i << '\n';
		}
		int l = F.query(0, i), r = F.query(i, n - 1);
		F.add(i);
		int cur;
		if (l == i) cur = 0;
		if (i & 1) cur = i - l;
		else cur = i - l + 1;

		cur += r;

		if (OO) cout << "cur " << cur << '\n';

		T.add(0, i - 1, 1);
		T.set(i, cur);
		T.add(i + 1, n - 1, -1);

		used[i] = 1;
		while (nxt < n && used[nxt]) nxt++;

		int res = T.query(nxt, n - 1);
		ans = max(ans, res);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}