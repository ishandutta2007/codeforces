#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;

int n, m, a[N], tree[2 * N], flag[2 * N];

void build(int i, int l, int r) {
	if (l == r) {
		flag[i] = 1;
		tree[i] = a[l];
	} else {
		int mid = (l + r) >> 1;
		build(2 * i, l, mid);
		build(2 * i + 1, mid + 1, r);
		flag[i] = 1 ^ flag[2 * i];
		if (flag[i] == 0) {
			tree[i] = tree[2 * i] | tree[2 * i + 1];
		} else {
			tree[i] = tree[2 * i] ^ tree[2 * i + 1];
		}
	}
}

void update(int j, int x, int i, int l, int r) {
	if (l == r) {
		tree[i] = x;
	} else {
		int mid = (l + r) >> 1;
		if (j <= mid) {
			update(j, x, 2 * i, l, mid);
		} else {
			update(j, x, 2 * i + 1, mid + 1, r);
		}
		if (flag[i] == 0) {
			tree[i] = tree[2 * i] | tree[2 * i + 1];
		} else {
			tree[i] = tree[2 * i] ^ tree[2 * i + 1];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	n = (1 << n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	build(1, 0, n - 1);

	while (m--) {
		int p, b;
		cin >> p >> b, --p;

		update(p, b, 1, 0, n - 1);
		cout << tree[1] << '\n';
	}
	return 0;
}