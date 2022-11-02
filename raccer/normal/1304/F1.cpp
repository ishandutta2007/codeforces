#include <bits/stdc++.h>
using namespace std;

int a[60][20010];
int sum[60][20010];
int dp[20010];

struct Segment_tree {
	int maxj[80010], lazy[80010]; 
	void pushup(int now) {
		maxj[now] = max(maxj[now << 1], maxj[now << 1 | 1]);
	}
	void Build(int now, int l, int r) {
		lazy[now] = 0;
		if (l == r) {
			maxj[now] = dp[l];
			return ;
		}
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
		pushup(now);
	}
	void pushdown(int now) {
		if (!lazy[now]) return ;
		int v = lazy[now]; lazy[now] = 0;
		maxj[now << 1] += v, lazy[now << 1] += v;
		maxj[now << 1 | 1] += v, lazy[now << 1 | 1] += v;
	}
	void Update(int now, int l, int r, int L, int R, int x) {
		if (l == L && r == R) {
			maxj[now] += x, lazy[now] += x;
			return ;
		}
		pushdown(now);
		int mid = l + r >> 1;
		if (R <= mid) Update(now << 1, l, mid, L, R, x);
		else if (L > mid) Update(now << 1 | 1, mid + 1, r, L, R, x);
		else Update(now << 1, l, mid, L, mid, x), Update(now << 1 | 1, mid + 1, r, mid + 1, R, x);
		pushup(now);
	}
	int Query() {return maxj[1];}
}seg;

int main () {
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
			sum[i][j] = sum[i][j - 1] + a[i][j];
		}
	}
	for (int j = 1; j <= m - k + 1; j++) {
		dp[j] = sum[0][j + k - 1] - sum[0][j - 1] + sum[1][j + k - 1] - sum[1][j - 1];
	}
	for (int i = 1; i < n; i++) {
		seg.Build(1, 1, m - k + 1);
		for (int j = 1; j <= k; j++) {
			seg.Update(1, 1, m - k + 1, max(1, j - k + 1), min(m - k + 1, j), -a[i][j]);
		}
		for (int j = 1; j <= m - k + 1; j++) {
			dp[j] = sum[i][j + k - 1] - sum[i][j - 1] + sum[i + 1][j + k - 1] - sum[i + 1][j - 1];
			dp[j] += seg.Query();
			if (j == m - k + 1) break;
			seg.Update(1, 1, m - k + 1, max(1, j - k + 1), min(m - k + 1, j), a[i][j]);
			seg.Update(1, 1, m - k + 1, max(1, j + k - k + 1), min(m - k + 1, j + k), -a[i][j + k]);
		}
	}
	int ans = 0;
	for (int j = 1; j <= m - k + 1; j++) {
		ans = max(ans, dp[j]);
	}
	printf("%d\n", ans);
	return 0;
}