#include <bits/stdc++.h>

int max[3], n, m, k;
int l[3], r[3];
int nn[210000][3];
int f[210000][3];
int mark[210000];
int val[1100000], lazy[1100000];

struct ev {
	int tp, x, y, z;
	ev (int tp = 0, int x = 0, int y = 0, int z = 0) : tp (tp), x (x), y (y), z (z) {}
};

bool operator < (const ev &a, const ev &b) { if (a.x != b.x) return a.x > b.x; return a.tp < b.tp; }

void push_down (int n, int l, int r) {
	if (l < r) {
		val[n << 1] = std::max (val[n << 1], lazy[n]);
		lazy[n << 1] = std::max (lazy[n << 1], lazy[n]);
		val[(n << 1) + 1] = std::max (val[(n << 1) + 1], lazy[n]);
		lazy[(n << 1) + 1] = std::max (lazy[(n << 1) + 1], lazy[n]);
	}
	lazy[n] = 0;
}

void modify (int n, int l, int r, int ll, int rr, int d) {
	push_down (n, l, r);
	if (ll <= l && r <= rr) {
		lazy[n] = std::max (lazy[n], d);
		val[n] = std::max (val[n], d);
		return;
	}
	int m = (l + r) / 2;
	if (ll <= m) modify (n << 1, l, m, ll, rr, d);
	if (m + 1 <= rr) modify ((n << 1) + 1, m + 1, r, ll, rr, d);
}

int query (int n, int l, int r, int x) {
	push_down (n, l, r);
	if (l == x && x == r) return val[n];
	int m = (l + r) / 2;
	if (x <= m) return query (n << 1, l, m, x);
	return query ((n << 1) + 1, m + 1, r, x);
}

void flip (int x) {
	for (int i = 0; i < m; ++i) nn[i][x] = max[x] - nn[i][x] + 1;
	for (int i = 0; i < k; ++i) f[i][x] = max[x] - f[i][x] + 1;
	l[x] = max[x] - l[x] + 1; r[x] = max[x] - r[x] + 1; std::swap (l[x], r[x]);
}

int main () {
	std::ios::sync_with_stdio (0);
	std::cin >> max[0] >> max[1] >> max[2] >> n >> m >> k;
	l[0] = max[0]; l[1] = max[1]; l[2] = max[2]; r[0] = r[1] = r[2] = 1;
	for (int i = 0; i < n; ++i) {
		int val[3]; std::cin >> val[0] >> val[1] >> val[2];
		for (int j = 0; j < 3; ++j) l[j] = std::min (l[j], val[j]), r[j] = std::max (r[j], val[j]);
	}
	for (int i = 0; i < m; ++i) {
		std::cin >> nn[i][0] >> nn[i][1] >> nn[i][2];
		bool ok = true; for (int j = 0; j < 3; ++j) if (nn[i][j] < l[j] || nn[i][j] > r[j]) ok = false;
		if (ok) { std::cout << "INCORRECT\n"; return 0; }
	}
	for (int i = 0; i < k; ++i) std::cin >> f[i][0] >> f[i][1] >> f[i][2];
	for (int d1 = 0; d1 < 2; ++d1) {
		for (int d2 = 0; d2 < 2; ++d2) {
			for (int d3 = 0; d3 < 2; ++d3) {
				std::vector <ev> e;
				for (int i = 0; i < m; ++i) {
					if (nn[i][0] <= r[0] && nn[i][1] <= r[1] && nn[i][2] <= r[2])
						e.push_back (ev (-1, nn[i][0] < l[0] ? nn[i][0] : max[0],
									nn[i][1] < l[1] ? nn[i][1] : max[1], nn[i][2] < l[2] ? nn[i][2] : max[2]));
				}
				for (int i = 0; i < k; ++i) e.push_back (ev (i, f[i][0], f[i][1], f[i][2]));
				std::sort (e.begin (), e.end ());
				std::fill (val, val + 1100000, 0);
				std::fill (lazy, lazy + 1100000, 0);
				for (auto &ee : e) {
					if (ee.tp == -1) modify (1, 1, max[1], 1, ee.y, ee.z);
					else {
						int x = query (1, 1, max[1], ee.y);
						if (x >= ee.z) mark[ee.tp] = true;
					}
				}
				flip (2);
			}
			flip (1);
		}
		flip (0);
	}
	std::cout << "CORRECT\n";
	for (int i = 0; i < k; ++i) {
		bool ok = true; for (int j = 0; j < 3; ++j) if (f[i][j] < l[j] || f[i][j] > r[j]) ok = false;
		if (ok) std::cout << "OPEN\n";
		else if (mark[i]) std::cout << "CLOSED\n";
		else std::cout << "UNKNOWN\n";
	}
}