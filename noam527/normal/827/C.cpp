#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void show(vector<int> &a) {
	for (auto &i : a) cout << i << " "; cout << endl;
}

struct segtree {
	vector<int> tree;
	int size;
	bool specialmode = false;
	void init(int n) {
		int i = 1;
		for (n--; n; n /= 2, i *= 2);
		size = max(2, i), tree.resize(2 * size, 0);
	}
	void fix(int x) { tree[x] = tree[2 * x + 1] + tree[2 * x + 2]; }
	void fixall() { for (int i = size - 2; i >= 0; i--) fix(i); }
	void set_special_mode(bool b) {
		specialmode = b;
		if (!b) fixall();
	}
	void update(int x, int v) {
		if (!specialmode) {
			x += size - 1, tree[x] = v;
			for (x = (x - 1) / 2; x; x = (x - 1) / 2) fix(x);
			fix(0);
			return;
		}
		tree[x + size - 1] = v;
	}
	int query(int rst, int ren, int nst, int nen, int node) {
		//cout << rst << " " << ren << " " << nst << " " << nen << " " << node << endl;
		if (rst > nen || ren < nst) return 0;
		if (rst <= nst && ren >= nen) return tree[node];
		int mid = (nst + nen) / 2;
		return query(rst, ren, nst, mid, node * 2 + 1) + query(rst, ren, mid + 1, nen, node * 2 + 2);
	}
	int query(int rst, int ren) {
		return query(rst, ren, 0, size - 1, 0);
	}
};

int tonum(char &c) {
	if (c == 'A') return 0;
	if (c == 'C') return 1;
	if (c == 'G') return 2;
	return 3;
}

int main() {
	ios::sync_with_stdio(0);
	string s, e;
	int q, op, x, l, r;
	char c;
	cin >> s >> q;
	segtree trees[4][10][10]; // letter, start, jump
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 4; k++)
				trees[k][i][j].init(s.size()), trees[k][i][j].set_special_mode(true);
			for (int k = i; k < s.size(); k += j + 1)
				trees[tonum(s[k])][i][j].update(k, 1);
			for (int k = 0; k < 4; k++)
				trees[k][i][j].set_special_mode(false);
		}
	}
	while (q--) {
		cin >> op;
		if (op == 1) {
			cin >> x >> c;
			--x;
			for (int i = 0; i < 10; i++) // jumps
				trees[tonum(s[x])][x % (i + 1)][i].update(x, 0);
			s[x] = c;
			for (int i = 0; i < 10; i++)
				trees[tonum(s[x])][x % (i + 1)][i].update(x, 1);
		}
		else {
			cin >> l >> r >> e;
			int ans = 0;
			while (e.size() > r - l + 1) e.pop_back();
			for (int i = 0; i < e.size(); i++)
				ans += trees[tonum(e[i])][(l + i - 1) % e.size()][e.size() - 1].query(l - 1, r - 1);
			cout << ans << endl;
		}
	}
}