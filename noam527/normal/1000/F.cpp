#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

struct segtree {
	int n;
	vector<pair<int, int>> tree;
	segtree(int size = 2) {
		n = max(2, size);
		while (n != (n & -n)) n += (n & -n);
		tree.resize(2 * n);
		for (int i = n - 1; i < 2 * n - 1; i++)
			tree[i] = { -1, i - n + 1 };
	}
	pair<int, int> mx(const pair<int, int> &aa, const pair<int, int> &bb) {
		if (aa.first > bb.first) return aa;
		return bb;
	}
	void upd(int pos, int v) {
		pos += n - 1;
		tree[pos] = { v, pos - n + 1 };
		pos = (pos - 1) / 2;
		while (pos) {
			tree[pos] = mx(tree[2 * pos + 1], tree[2 * pos + 2]);
			pos = (pos - 1) / 2;
		}
		tree[0] = mx(tree[1], tree[2]);
	}
	pair<int, int> query(int l, int r) {
		return query(0, 0, n - 1, l, r);
	}
	pair<int, int> query(int node, int nl, int nr, int l, int r) {
		if (r < nl || nr < l) return{ -1, -1 };
		if (l <= nl && nr <= r) return tree[node];
		int mid = (nl + nr) / 2;
		return mx(query(2 * node + 1, nl, mid, l, r), query(2 * node + 2, mid + 1, nr, l, r));
	}
};

const int mxn = 5e5 + 5;
int n, q, A[mxn], B[mxn], C[mxn], ans[mxn];
map<int, int> m;
vector<int> pos[mxn];
vector<int> que[mxn];

bool cmp(const vector<int> &aa, const vector<int> &bb) {
	return aa[0] < bb[0];
}

int main() {
	fast;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];

	m.clear();
	for (int i = 0; i < n; i++) {
		if (m.count(A[i])) B[i] = m[A[i]];
		else B[i] = -1;
		m[A[i]] = i;
	}
	m.clear();
	for (int i = n - 1; i >= 0; i--) {
		if (m.count(A[i])) C[i] = m[A[i]];
		else C[i] = n;
		m[A[i]] = i;
	}

	for (int i = 0; i < n; i++)
		pos[1 + B[i]].push_back(i);

	cin >> q;
	for (int i = 0, l, r; i < q; i++) {
		cin >> l >> r;
		que[i] = { --l, --r, i };
	}
	sort(que, que + q, cmp);

	int nxt = 0;
	segtree T(n);
	for (int i = 0; i < q; i++) {
		while (nxt <= que[i][0]) {
			for (const auto &j : pos[nxt])
				T.upd(j, C[j]);
			nxt++;
		}
		auto rtn = T.query(que[i][0], que[i][1]);
		if (rtn.first > que[i][1]) ans[que[i][2]] = A[rtn.second];
		else ans[que[i][2]] = 0;
	}
	for (int i = 0; i < q; i++) cout << ans[i] << endl;
}