#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

int n, q;
int a[N];
int t[N << 2];
int cnt = 0;

void init(int node, int l, int r) {
	if (l == r) {
		t[node] = a[l];
		return;
	}
	int m = (l + r) >> 1;
	init(node << 1, l, m);
	init(node << 1 | 1, m + 1, r);
	t[node] = __gcd(t[node << 1], t[node << 1 | 1]);
}

void modify(int node, int l, int r, int id, int y) {
	if (r < id || id < l) {
		return;
	}
	if (l == r) {
		t[node] = y;
		return;
	}
	int m = (l + r) >> 1;
	modify(node << 1, l, m, id, y);
	modify(node << 1 | 1, m + 1, r, id, y);
	t[node] = __gcd(t[node << 1], t[node << 1 | 1]);
}

void get(int node, int l, int r, int x, int y, int val) {
	if (cnt >= 2) {
		return;
	}
	if (x > r || y < l) {
		return;
	}
	if (l == r) {
		cnt += (t[node] % val) != 0;
		return;
	}
	if (x <= l && r <= y) {
		if (t[node] % val == 0) {
			return;
		}
		int m = (l + r) >> 1;
		get(node << 1, l, m, x, y, val);
		get(node << 1 | 1, m + 1, r, x, y, val);
		return;
	}
	int m = (l + r) >> 1;
	get(node << 1, l, m, x, y, val);
	get(node << 1 | 1, m + 1, r, x, y, val);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	init(1, 1, n);
	scanf("%d", &q);
	while (q--) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			int l, r, x;
			scanf("%d %d %d", &l, &r, &x);
			cnt = 0;
			get(1, 1, n, l, r, x);
			if (cnt < 2) {
				puts("YES");
			} else {
				puts("NO");
			}
		} else {
			int x, y;
			scanf("%d %d", &x, &y);
			modify(1, 1, n, x, y);
		}
	}
	return 0;
}