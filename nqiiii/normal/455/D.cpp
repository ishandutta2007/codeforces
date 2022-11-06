#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000, blksz = 800;
int n, m, a[maxn / blksz + 10][blksz + 10], pos[maxn / blksz + 10];
int buc[maxn / blksz + 10][maxn + 10], bel[maxn + 10];
int b[maxn + 10], ans;

int getid(int p) {
	return p - (bel[p] - 1) * blksz;
}

inline int getpos(int p) {
	int blk = bel[p]; p -= (blk - 1) * blksz;
	int d = pos[blk] + p - 1;
	return d > blksz ? d - blksz : d;
}

void change(int p, int v) {
	int d = getpos(p);
	--buc[bel[p]][a[bel[p]][d]];
	++buc[bel[p]][a[bel[p]][d] = v];
}


int main() {
	/* freopen("queue.in", "r", stdin); */
	/* freopen("queue.out", "w", stdout); */
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		bel[i] = (i - 1) / blksz + 1;
		++buc[bel[i]][0]; pos[bel[i]] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		int x; scanf("%d", &x);
		change(i, x);
	}
	scanf("%d", &m);
	while (m--) {
		int op, l, r, k;
		scanf("%d%d%d", &op, &l, &r);
		l = (l + ans - 1) % n + 1; r = (r + ans - 1) % n + 1;
		if (l > r ) swap(l, r);
		int bl = bel[l], br = bel[r];
		if (op == 1) {
			if (bl == br) {
				for (int i = l, p = getpos(l); i <= r; ++i, p = p == blksz ? 1 : p + 1)
					b[i - l + 1] = a[bel[i]][p];
				for (int i = l; i <= r; ++i)
					change(i == r ? l : i + 1, b[i - l + 1]);
			} else {
				int lst = a[bl][pos[bl] == 1 ? blksz : pos[bl] -1];
				--buc[bl][lst];
				for (int i = bl + 1; i <= br - 1; ++i) {
					pos[i] = pos[i] == 1 ? blksz : pos[i] - 1;
					int &d = a[i][pos[i]];
					int tmp = d;
					--buc[i][d]; ++buc[i][d = lst];
					lst = tmp;
				}
				int tmp = a[br][getpos(r)];
				for (int i = r, p = getpos(i); i > (br - 1) * blksz + 1; --i, p = p == 1 ? blksz : p - 1) {
					a[br][p] = a[br][p == 1 ? blksz : p - 1];
				}
				--buc[br][tmp];
				++buc[br][a[br][pos[br]] = lst];
				lst = tmp;
				for (int i = bl * blksz, p = getpos(i); i > l; --i, p = p == 1 ? blksz : p - 1) {
					a[bl][p] = a[bl][p == 1 ? blksz : p - 1];
				}
				++buc[bl][a[bl][getpos(l)] = lst];
			}
		} else {
			scanf("%d", &k); k = (k + ans - 1) % n + 1; ans = 0;
			if (bl == br) {
				for (int i = l, p = getpos(i); i <= r; ++i, p = p == blksz ? 1 : p + 1)
					ans += a[bel[i]][p] == k;
			} else {
				for (int i = bl + 1; i <= br - 1; ++i) ans += buc[i][k];
				for (int i = l, p = getpos(i); i <= bl * blksz; ++i, p = p == blksz ? 1 : p + 1) ans += a[bel[i]][p] == k;
				for (int i = (br - 1) * blksz + 1, p = getpos(i); i <= r; ++i, p = p == blksz ? 1 : p + 1) ans += a[bel[i]][p] == k;
			}
			printf("%d\n", ans);
		}
	}
}