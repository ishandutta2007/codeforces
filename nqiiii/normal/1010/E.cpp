#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000, maxc = 16000000;
int xmax, ymax, zmax, n, m, k;
int xl, xr, yl, yr, zl, zr, ndcnt;
int lc[maxc + 10], rc[maxc + 10], rt[maxn * 4 + 10];
int vl[maxc + 10], vr[maxc + 10];

void add2(int &p, int y, int z, int ls, int rs) {
	if (!p) {
		p = ++ndcnt; vr[p] = zmax + 1;
	}
	if (z <= zr) vl[p] = max(vl[p], z);
	if (z >= zl) vr[p] = min(vr[p], z);
	if (ls != rs) {
		int mid = ls + rs >> 1;
		if (y <= mid) add2(lc[p], y, z, ls, mid);
		else add2(rc[p], y, z, mid + 1, rs);
	}
}

void add(int p, int x, int y, int z, int ls, int rs) {
	add2(rt[p], y, z, 1, ymax);
	if (ls != rs) {
		int mid = ls + rs >> 1;
		if (x <= mid) add(p << 1, x, y, z, ls, mid);
		else add(p << 1 | 1, x, y, z, mid + 1, rs);
	}
}

bool query2(int p, int yl, int yr, int zl, int zr, int ls, int rs) {
	if (!p) return 1;
	if (yl == ls && yr == rs) return zl > vl[p] && zr < vr[p];
	else {
		int mid = ls + rs >> 1;
		if (yr <= mid) return query2(lc[p], yl, yr, zl, zr, ls, mid);
		else if (yl > mid) return query2(rc[p], yl, yr, zl, zr, mid + 1, rs);
		else return query2(lc[p], yl, mid, zl, zr, ls, mid) && query2(rc[p], mid + 1, yr, zl, zr, mid + 1, rs);
	}
}

bool query(int p, int xl, int xr, int yl, int yr, int zl, int zr, int ls, int rs) {
	if (xl == ls && xr == rs) return query2(rt[p], yl, yr, zl, zr, 1, ymax);
	else {
		int mid = ls + rs >> 1;
		if (xr <= mid) return query(p << 1, xl, xr, yl, yr, zl, zr, ls, mid);
		else if (xl > mid) return query(p << 1 | 1, xl, xr, yl, yr, zl, zr, mid + 1, rs);
		else return query(p << 1, xl, mid, yl, yr, zl, zr, ls, mid) && query(p << 1 | 1, mid + 1, xr, yl, yr, zl, zr, mid + 1, rs);
	}
}

int main() {
	scanf("%d%d%d%d%d%d", &xmax, &ymax, &zmax, &n, &m, &k);
	xl = xmax; yl = ymax; zl = zmax;
	for (int i = 1; i <= n; ++i) {
		int x, y, z; scanf("%d%d%d", &x, &y, &z);
		xl = min(xl, x); xr = max(xr, x);
		yl = min(yl, y); yr = max(yr, y);
		zl = min(zl, z); zr = max(zr, z);
	}
	for (int i = 1; i <= m; ++i) {
		int x, y, z; scanf("%d%d%d", &x, &y, &z);
		if (x >= xl && x <= xr && y >= yl && y <= yr && z >= zl && z <= zr) {
			puts("INCORRECT"); return 0;
		}
		add(1, x, y, z, 1, xmax);
	}
	puts("CORRECT");
	while (k--) {
		int x, y, z; scanf("%d%d%d", &x, &y, &z);
		if (x >= xl && x <= xr && y >= yl && y <= yr && z >= zl && z <= zr) puts("OPEN");
		else if (query(1, min(x, xl), max(x, xr), min(y, yl), max(y, yr), min(z, zl), max(z, zr), 1, xmax)) puts("UNKNOWN");
		else puts("CLOSED");
	}
}