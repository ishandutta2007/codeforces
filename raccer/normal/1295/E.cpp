#include <bits/stdc++.h>
using namespace std;

int a[200010], num[200010];
long long sum = 0;

struct Segment_tree {
	long long minj[800010], lazy[800010];
	void pushup(int now) {
		minj[now] = min(minj[now << 1], minj[now << 1 | 1]);
	}
	void Build(int now, int l, int r) {
		lazy[now] = 0;
		if (l == r) {
			sum += a[num[l]];
			minj[now] = sum;
			return ;
		}
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
		pushup(now);
	}
	void pushdown(int now) {
		if (!lazy[now]) return ;
		long long v = lazy[now]; lazy[now] = 0;
		minj[now << 1] += v, lazy[now << 1] += v;
		minj[now << 1 | 1] += v, lazy[now << 1 | 1] += v;
	}
	void Update(int now, int l, int r, int L, int R, int x) {
		if (L > R) return ;
		if (l == L && r == R) {
			minj[now] += x, lazy[now] += x;
			return ;
		}
		pushdown(now);
		int mid = l + r >> 1;
		if (R <= mid) Update(now << 1, l, mid, L, R, x);
		else if (L > mid) Update(now << 1 | 1, mid + 1, r, L, R, x);
		else Update(now << 1, l, mid, L, mid, x), Update(now << 1 | 1, mid + 1, r, mid + 1, R, x);
		pushup(now);
	}
	long long Query() {return minj[1];}
}seg;

int p[200010];

int main () {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
		num[p[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	seg.Build(1, 1, n);
	long long ans = min(a[1], a[n]);
	for (int i = 1; i < n; i++) {
		int x = p[i];
		seg.Update(1, 1, n, x, n, -a[i]);
		seg.Update(1, 1, n, 1, x - 1, a[i]);
		ans = min(ans, seg.Query());
	}
	printf("%I64d\n", ans);
	return 0;
}