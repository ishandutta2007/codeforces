#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 2e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

struct segtree {
	int n;
	vector<int> mx, tag;
	segtree() {}
	segtree(int sz) {
		n = max(2, sz);
		while (n != (n & -n)) n += (n & -n);
		mx.resize(2 * n, 0);
		tag.resize(2 * n, 0);
	}
	void push(int x) {
		mx[x] += tag[x];
		if (x < n - 1) {
			tag[x + x + 1] += tag[x];
			tag[x + x + 2] += tag[x];
		}
		tag[x] = 0;
	}
	void fix(int x) {
		push(2 * x + 1), push(2 * x + 2);
		mx[x] = max(mx[x + x + 1], mx[x + x + 2]);
	}
	void add(int l, int r, int x) {
		if (OO) cout << "adding " << l << " " << r << " " << x << endl;
		add(l, r, x, 0, 0, n - 1);
	}
	void add(int l, int r, int x, int node, int nl, int nr) {
		if (r < nl || nr < l) return;
		if (l <= nl && nr <= r) {
			tag[node] += x;
			return;
		}
		push(node);
		int mid = (nl + nr) / 2;
		add(l, r, x, 2 * node + 1, nl, mid);
		add(l, r, x, 2 * node + 2, mid + 1, nr);
		fix(node);
	}
	int query() {
		push(0);
		return mx[0];
	}
};

int n;
vector<int> p, q;
vector<int> pos;
segtree T;

void solve() {
	cin >> n;
	p.resize(n), q.resize(n), pos.resize(n);
	T = segtree(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		--p[i];
		pos[p[i]] = i;
	}
	for (auto &i : q) cin >> i, --i;

	int nxt = n - 1;
	for (int i = 0; i < n; i++) {
		if (OO) cout << "iter " << i << '\n';
		while (nxt >= 0 && T.query() <= 0) {
			T.add(0, pos[nxt], 1);
			nxt--;
		}
		if (nxt == -1 && T.query() <= 0) {
			cout << "wtf\n";
			return;
		}

		cout << nxt + 2 << " ";
		T.add(0, q[i], -1);
	}

}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
}