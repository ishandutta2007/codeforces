#include <bits/stdc++.h>
using namespace std;

const int N = 1000 * 1000;

int n, m;
string s;

struct node {
	int ans;
	int opening;
	int closing;

	node() {
		ans = 0;
		opening = 0;
		closing = 0;
	}

	node(char c) {
		ans = 0;
		if (c == '(') {
			opening = 1;
			closing = 0;
		} else {
			opening = 0;
			closing = 1;
		}
	}
};

node combine(const node &left, const node &right) {
	node result;
	int temp = min(left.opening, right.closing);
	result.ans = left.ans + right.ans + 2 * temp;
	result.opening = left.opening + right.opening - temp;
	result.closing = left.closing + right.closing - temp;
	return result;
}

node tree[4 * N];

void build(int i, int l, int r) {
	if (l == r) {
		tree[i] = node(s[l]);
	} else {
		int mid = (l + r) >> 1;
		build(2 * i, l, mid);
		build(2 * i + 1, mid + 1, r);
		tree[i] = combine(tree[2 * i], tree[2 * i + 1]);
	}
}

node query(int ql, int qr, int i, int l, int r) {
	if (r < ql || qr < l) {
		return node();
	} else if (ql <= l && r <= qr) {
		return tree[i];
	} else {
		int mid = (l + r) >> 1;
		node x = query(ql, qr, 2 * i, l, mid);
		node y = query(ql, qr, 2 * i + 1, mid + 1, r);
		return combine(x, y);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s;
	n = (int) s.length();

	build(1, 0, n - 1);

	cin >> m;
	while (m--) {
		int l, r;
		cin >> l >> r;
		--l, --r;
		cout << query(l, r, 1, 0, n - 1).ans << '\n';
	}
	return 0;
}