#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, q;
int c[N];

struct IT {
	long double a[N << 2], b[N << 2], sum[N << 2];

	void init(int node, int l, int r) {
		a[node] = 1.;
		b[node] = 0.;
		if (l == r) {
			sum[node] = c[l];
			return;
		}
		int m = (l + r) >> 1;
		init(node << 1, l, m);
		init(node << 1 | 1, m + 1, r);
		sum[node] = sum[node << 1] + sum[node << 1 | 1];
	}

	void refresh(int node, int l, int r, long double aa, long double bb) {
		sum[node] = aa * sum[node] + bb * (r - l + 1);
		b[node] = b[node] * aa + bb;
		a[node] *= aa;
	}

	void down(int node, int l, int m, int r) {
		refresh(node << 1, l, m, a[node], b[node]);
		refresh(node << 1 | 1, m + 1, r, a[node], b[node]);
		a[node] = 1.;
		b[node] = 0.;
	}

	long double getSum(int node, int l, int r, int x, int y) {
		if (x > r || y < l) {
			return 0.;
		}
		if (x <= l && r <= y) {
			return sum[node];
		}
		int m = (l + r) >> 1;
		down(node, l, m, r);
		long double p1 = getSum(node << 1, l, m, x, y);
		long double p2 = getSum(node << 1 | 1, m + 1, r, x, y);
		// printf("%d %d %d %d %.10Lf %.10Lf\n", l, r, x, y, p1, p2);
		return p1 + p2;
	}

	void update(int node, int l, int r, int x, int y, long double aa, long double bb) {
		// if (node == 1) {
		// 	printf("update %d %d %.10Lf %.10Lf\n", x, y, aa, bb);
		// }
		if (x > r || y < l) {
			return;
		}
		if (x <= l && r <= y) {
			refresh(node, l, r, aa, bb);
			return;
		}
		int m = (l + r) >> 1;
		down(node, l, m, r);
		update(node << 1, l, m, x, y, aa, bb);
		update(node << 1 | 1, m + 1, r, x, y, aa, bb);
		sum[node] = sum[node << 1] + sum[node << 1 | 1];
	}
} t;

int main() {
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", c + i);
	}		
	t.init(1, 1, n);
	while (q--) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			int l1, l2, r1, r2;
			scanf("%d %d %d %d", &l1, &r1, &l2 , &r2);
			long double sum1 = t.getSum(1, 1, n, l1, r1) / (r1 - l1 + 1);
			long double sum2 = t.getSum(1, 1, n, l2, r2) / (r2 - l2 + 1);
			t.update(1, 1, n, l1, r1, (long double)(r1 - l1) / (r1 - l1 + 1), sum2 / (r1 - l1 + 1));
			t.update(1, 1, n, l2, r2, (long double)(r2 - l2) / (r2 - l2 + 1), sum1 / (r2 - l2 + 1));
		} else {
			int l, r;
			scanf("%d %d", &l, &r);
			printf("%0.10f\n", (double)t.getSum(1, 1, n, l, r));
		}
		// cout << "Trace\n";
		// for (int i = 1; i <= n; i++) {
		// 	printf("%d %.10Lf\n", i, t.getSum(1, 1, n, i, i));
		// }
	}
	return 0;
}