#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;
int n;
bitset<maxn + 10> a[maxn + 10], t, b[maxn + 10];
vector<int> g[maxn + 10];
bool vis[maxn + 10], c[maxn + 10][maxn + 10];
int l[maxn + 10], r[maxn + 10], ecnt;
int fa[maxn + 10];

int getf(int p) {
	return fa[p] == p ? p : fa[p] = getf(fa[p]);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int k; scanf("%d", &k);
		while (k--) {
			int x; scanf("%d", &x);
			a[i][x] = 1;
		}
	}
	if (n <= 3) {
		for (int i = 2; i <= n; ++i)
			printf("%d %d\n", 1, i);
		return 0;
	}
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j) {
			t = a[i] & a[j];
			if (t.count() == 2) {
				int x = t._Find_first(), y = t._Find_next(x);
				if (c[x][y]) continue;
				c[x][y] = 1;
				g[x].push_back(y); g[y].push_back(x);
				vis[x] = vis[y] = 1;
				b[x][y] = b[y][x] = 1;
				l[++ecnt] = x; r[ecnt] = y;
			}
		}
	if (!ecnt) {
		for (int i = 2; i <= n; ++i)
			printf("%d %d\n", 1, i);
		return 0;
	}
	if (ecnt == 1) {
		for (int i = 1; i <= n; ++i) fa[i] = i;
		for (int i = 1; i <= n; ++i)
			if (a[i].count() < n) {
				int lst = 0;
				for (int j = 1; j <= n; ++j)
					if (!vis[j] && a[i][j]) {
						if (lst) fa[getf(lst)] = getf(j);
						lst = j;
					}
			}
		printf("%d %d\n", l[1], r[1]);
		int any = -1;
		for (int i = 1; i <= n; ++i) 
			if (!vis[i]) any = i;
		for (int i = 1; i <= n; ++i)
			if (!vis[i])
				printf("%d %d\n", i, getf(i) == getf(any) ? l[1] : r[1]);
		return 0;
	}
	for (int i = 1; i <= n; ++i)
		if (vis[i]) b[i][i] = 1;
	for (int i = 1; i <= n; ++i)
		if (!vis[i]) {
			int mn = 1e9, id = 0;
			for (int j = 1; j <= n; ++j)
				if (a[j][i]) {
					int x = a[j].count();
					if (x < mn) {
						mn = x; id = j;
					}
				}
			t = a[id];
			for (int j = 1; j <= n; ++j)
				if (!vis[j]) t[j] = 0;
			for (int j = 1; j <= n; ++j)
				if (vis[j] && t == b[j]) {
					l[++ecnt] = i; r[ecnt] = j;
					break;
				}
		}
	for (int i = 1; i <= ecnt; ++i)
		printf("%d %d\n", l[i], r[i]);
}