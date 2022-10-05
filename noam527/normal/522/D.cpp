#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

void show(vector<int> &a) {
	for (int i = 0; i < a.size(); i++) cout << a[i] << " "; cout << endl;
}

struct Seg {
	int l, r, len;
	Seg(int a = 0, int b = 0) : l(a), r(b), len(b - a) {};
};

struct SegmentTree {
	vector<int> tree;
	int size;
	void init(int n) {
		int i = 1;
		for (; n; n /= 2, i *= 2);
		tree.resize(2 * i, 2e9), size = i;
	}
	void fix(int x) { tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]); }
	void update(int x, int v) {
		x += size - 1, tree[x] = v;
		for (x = (x - 1) / 2; x; x = (x - 1) / 2) fix(x);
		fix(0);
	}
	int query(int rst, int ren, int nst, int nen, int node) {
		//cout << rst << " " << ren << " " << nst << " " << nen << " " << node << endl;
		if (rst > nen || ren < nst) return 2e9;
		if (rst <= nst && ren >= nen) return tree[node];
		int mid = (nst + nen) / 2;
		return min(query(rst, ren, nst, mid, node * 2 + 1), query(rst, ren, mid + 1, nen, node * 2 + 2));
	}
	int query(int st, int en) {
		return query(st, en, 0, size - 1, 0);
	}
};

int main() {
	ios::sync_with_stdio(0);
	int n, m, l, r, a, mx = -1, loc1, loc2;
	map<int, int> ex;
	vector<Seg> segments;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (ex.find(a) == ex.end()) ex[a] = i;
		else {
			int val = ex[a];
			if (val > mx)
				mx = val, segments.push_back(Seg(val, i));
			ex[a] = i;
		}
	}
	SegmentTree t;
	vector<int> st(n, 0), en(n, 0);
	en[0] = -1;
	t.init(segments.size());
	for (int i = 0; i < segments.size(); i++) t.update(i, segments[i].len), st[segments[i].l + 1]++, en[segments[i].r]++;
	for (int i = 1; i < n; i++) st[i] += st[i - 1], en[i] += en[i - 1];
	//show(st), show(en), show(t.tree);
	for (int i = 0; i < m; i++) {
		cin >> l >> r, l = st[l - 1], r = en[r - 1];
		//cout << "l " << l << " r " << r << endl;
		if (l == segments.size() || r == -1 || l > r)
			cout << -1 << endl;
		else
			cout << t.query(l, r) << endl;
	}
	return 0;
}