#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000, lgn = 20;
int n, s, l;
int f[lgn + 10][maxn + 10], g[lgn + 1][maxn + 10], h[maxn + 10];

namespace seg {
	int val[maxn * 4 + 10];
	
	void change(int p, int k, int v, int ls, int rs) {
		if (ls == rs) val[p] = v;
		else {
			int mid = ls + rs >> 1;
			if (k <= mid) change(p << 1, k, v, ls, mid);
			else change(p << 1 | 1, k, v, mid + 1, rs);
			val[p] = min(val[p << 1], val[p << 1 | 1]);
		}
	}

	int query(int p, int l, int r, int ls, int rs) {
		if (l > r) return 2e9;
		else if (l == ls && r == rs) return val[p];
		else {
			int mid = ls + rs >> 1;
			if (r <= mid) return query(p << 1, l, r, ls, mid);
			else if (l > mid) return query(p << 1 | 1, l, r, mid + 1, rs);
			else return min(query(p << 1, l, mid, ls, mid), query(p << 1 | 1, mid + 1, r, mid + 1, rs));
		}	
	}
}

int main() {
	scanf("%d%d%d", &n, &s, &l);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &f[0][i]); g[0][i] = f[0][i];
	}
	for (int i = 1; i <= lgn; ++i)
		for (int j = 1 << i; j <= n; ++j) {
			f[i][j] = max(f[i - 1][j], f[i - 1][j - (1 << i - 1)]);
			g[i][j] = min(g[i - 1][j], g[i - 1][j - (1 << i - 1)]);
		}
	for (int i = 1; i <= n; ++i) {
		int maxv = -1000000001, minv = 1000000001, p = i;
		for (int j = lgn; j >= 0; --j)
			if (p >= 1 << j && max(maxv, f[j][p]) - min(minv, g[j][p]) <= s) {
				maxv = max(maxv, f[j][p]); minv = min(minv, g[j][p]);
				p -= 1 << j;
			}
		h[i] = seg::query(1, p, i - l, 0, n) + 1;
		seg::change(1, i, h[i], 0, n);
	}
	printf("%d", h[n] > 2e9 ? -1 : h[n]);
}