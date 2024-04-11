#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000, maxv = 6000000;
int n, q;
int prm[maxv + 10], pcnt, g[maxv + 10], c[maxv + 10], a[maxn + 10], acnt;
int f[maxv + 10][8], h[maxn + 10][15];
bool nprm[maxv + 10];

void pre() {
	for (int i = 2; i <= maxv; ++i) {
		if (!nprm[i]) {
			prm[++pcnt] = i; g[i] = i;
		}
		for (int j = 1; j <= pcnt && i * prm[j] <= maxv; ++j) {
			nprm[i * prm[j]] = 1; g[i * prm[j]] = prm[j];
			if (i % prm[j] == 0) break;
		}
	}
}

int main() {
	pre();
	scanf("%d%d", &n, &q);
	for (int i = 1, x; i <= n; ++i) {
		scanf("%d", &x); acnt = 0;
		for (int t = x; t > 1; ) {
			int v = g[t], b = 0;
			while (t % v == 0) {
				t /= v; b ^= 1;
			}
			if (b) a[acnt++] = v;
		}
		for (int j = 0; j <= 14; ++j) h[i][j] = h[i - 1][j];
		for (int j = 0; j < 1 << acnt; ++j) {
			int v = 1, d = acnt;
			for (int k = 0; k < acnt; ++k)
				if (j >> k & 1) {
					v *= a[k]; --d;
				}
			for (int k = 0; k <= 7; ++k)
				h[i][d + k] = max(h[i][d + k], f[v][k]);
		}
		for (int j = 0; j < 1 << acnt; ++j) {
			int v = 1, d = acnt;
			for (int k = 0; k < acnt; ++k)
				if (j >> k & 1) {
					v *= a[k]; --d;
				}
			f[v][d] = i;
		}
	}
	while (q--) {
		int l, r, ans = 1e9; scanf("%d%d", &l, &r);
		for (int i = 0; i <= 14; ++i)
			if (l <= h[r][i]) ans = min(ans, i);
		printf("%d\n", ans);
	}
}