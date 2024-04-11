#include <iostream>
#include <algorithm>
#include <vector>
#define left(X) (X) * 2 + 1
#define right(X) (X) * 2 + 2
using namespace std;

/*
First time I used LCA in a competition...
went pretty bad.
*/

struct SegTree {
	vector<int> tree;
	int size;
	void init(int n) {
		int i = 2;
		for (n--; n > 0; i *= 2, n /= 2);
		size = i / 2, tree.resize(i);
	}
	void fix(int x) { tree[x] = min(tree[left(x)], tree[right(x)]); }
	void init(vector<int> &a) {
		init(a.size());
		for (int i = 0; i < a.size(); i++) tree[i + size - 1] = a[i];
		for (int i = size - 2; i >= 0; i--) fix(i);
	}
	int query(int rst, int ren, int nst, int nen, int node) {
		if (ren < nst || rst > nen) return 2e9;
		if (rst <= nst && ren >= nen) return tree[node];
		int mid = (nst + nen) / 2;
		return min(query(rst, ren, nst, mid, left(node)), query(rst, ren, mid + 1, nen, right(node)));
	}
	int query(int st, int en) {
		return query(min(st, en), max(st, en), 0, size - 1, 0);
	}
};

vector<int> dfsorder, ind;
vector<vector<int>> cons;

void dfs(int v = 0, int prev = -1, int dis = 0) {
	ind[v] = dfsorder.size();
	for (auto i : cons[v]) {
		if (i != prev) {
			dfsorder.push_back(dis);
			dfs(i, v, dis + 1);
		}
	}
	dfsorder.push_back(dis);
}

int main() {
	ios::sync_with_stdio(false);
	int n, q, v, a, b, c, dep[3], lca[3], meet[3];
	cin >> n >> q;
	ind.resize(n), cons.resize(n);
	for (int i = 0; i < n - 1; i++)
		cin >> v, v--, cons[i + 1].push_back(v), cons[v].push_back(i + 1);
	dfs();
	SegTree tree;
	tree.init(dfsorder);
	while (q--) {
		cin >> a >> b >> c;
		--a, --b, --c;
		dep[0] = dfsorder[ind[a]], dep[1] = dfsorder[ind[b]], dep[2] = dfsorder[ind[c]];
		lca[0] = tree.query(ind[a], ind[b]), lca[1] = tree.query(ind[a], ind[c]), lca[2] = tree.query(ind[b], ind[c]);
		meet[0] = max(lca[1], lca[2]), meet[1] = max(lca[0], lca[2]), meet[2] = max(lca[0], lca[1]);
		int mx = -1;
		mx = max(mx, dep[0] - meet[2] + 1 + max(0, lca[2] - meet[2]));
		mx = max(mx, dep[1] - meet[1] + 1 + max(0, lca[1] - meet[1]));
		mx = max(mx, dep[2] - meet[0] + 1 + max(0, lca[0] - meet[0]));
		cout << mx << endl;
	}
}