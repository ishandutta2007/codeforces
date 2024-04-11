#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000, maxm = 2e4, maxq = 1e5;
int n, q, all, d[maxq + 10], x[maxq + 10], y[maxq + 10];
int len[maxq + 10], op[maxq + 10], ans[maxq + 10];

namespace bit {
	int a[maxn + 10][maxn + 10];
	
	void init() {
		memset(a, 0, sizeof a);
	}

	void modify(int x, int y, int v) {
		for (int i = x; i <= maxn; i += i & -i)
			for (int j = y; j <= maxn; j += j & -j)
				a[i][j] += v;
	}

	int query(int x, int y) {
		int ans = 0;
		for (int i = x; i; i -= i & -i)
			for (int j = y; j; j -= j & -j)
				ans += a[i][j];
		return ans;
	}
}

namespace bits {
	int c[maxm + 10];

	void init() {
		memset(c, 0, sizeof c);
	}

	void modify(int p, int v) {
		for (; p <= maxm; p += p & -p) c[p] += v;
	}

	int query(int p) {
		int ans = 0;
		for (; p; p -= p & -p) ans += c[p];
		return ans;
	}
};

void modrec(int lx, int rx, int ly, int ry) {
	bit::modify(lx, ly, 1);
	bit::modify(lx, ry + 1, -1);
	bit::modify(rx + 1, ly, -1);
	bit::modify(rx + 1, ry + 1, 1);
}

void modseg(int l, int r) {
	bits::modify(l, 1);
	bits::modify(r + 1, -1);
}

void rot() {
	for (int i = 1; i <= q; ++i) {
		swap(x[i], y[i]); x[i] = n + 1 - x[i];
	}
}

void solve(int s) {
	bit::init();
	for (int i = 1; i <= q; ++i)
		if (op[i] == 1 && d[i] == s)
			modrec(1, x[i] - 1, 1, y[i] - 1);
		else if (op[i] == 2) ans[i] += bit::query(x[i], y[i]);

	bit::init();
	for (int i = 1; i <= q; ++i)
		if (op[i] == 1 && d[i] == s)
			modrec(y[i], maxn, 1, x[i] + y[i] + len[i]);
		else if (op[i] == 2) ans[i] += bit::query(y[i], x[i] + y[i]);

	bit::init();
	for (int i = 1; i <= q; ++i)
		if (op[i] == 1 && d[i] == s)
			modrec(x[i], maxn, 1, x[i] + y[i] + len[i]);
		else if (op[i] == 2) ans[i] += bit::query(x[i], x[i] + y[i]);

	bits::init();	
	for (int i = 1; i <= q; ++i)
		if (op[i] == 1 && d[i] == s)
			modseg(1, x[i] + y[i] + len[i]);
		else if (op[i] == 2) ans[i] -= bits::query(x[i] + y[i]);
}


int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= q; ++i) {
		scanf("%d", &op[i]);
		if (op[i] == 1) scanf("%d%d%d%d", &d[i], &x[i], &y[i], &len[i]);
		else scanf("%d%d", &x[i], &y[i]);
	}
	solve(1);
	rot(); solve(2);
	rot(); solve(4);
	rot(); solve(3);
	for (int i = 1; i <= q; ++i)
		if (op[i] == 2) printf("%d\n", ans[i]);
}