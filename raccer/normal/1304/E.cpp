#include <bits/stdc++.h>
using namespace std;

vector <int> from[100010];
int fa[100010][17];
int dep[100010];

void dfs(int x, int last) {
	fa[x][0] = last;
	for (int j = 1; j < 17; j++) {
		fa[x][j] = fa[fa[x][j - 1]][j - 1];
	}
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i];
		if (v == last) continue;
		dep[v] = dep[x] + 1, dfs(v, x);
	}
}

int LCA(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	int tmp = dep[x] - dep[y], cnt = 0;
	while (tmp) {
		if (tmp & 1) x = fa[x][cnt];
		tmp >>= 1, cnt++;
	}
	if (x == y) return x;
	for (int i = 16; i >= 0; i--) {
		if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	}
	return fa[x][0];
}

int get_dist(int x, int y) {
	return dep[x] + dep[y] - 2 * dep[LCA(x, y)];
}

int main () {
	int n; scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		from[x].push_back(y);
		from[y].push_back(x);
	}
	dfs(1, 1);
	int q; scanf("%d", &q);
	while (q--) {
		int x, y, a, b, k; scanf("%d%d%d%d%d", &x, &y, &a, &b, &k);
		int tmp = get_dist(a, b);
		if (tmp <= k && (k - tmp) % 2 == 0) {
			printf("YES\n");
			continue;
		}
		tmp = get_dist(a, x) + 1 + get_dist(b, y);
		if (tmp <= k && (k - tmp) % 2 == 0) {
			printf("YES\n");
			continue;
		}
		tmp = get_dist(b, x) + 1 + get_dist(a, y);
		if (tmp <= k && (k - tmp) % 2 == 0) {
			printf("YES\n");
			continue;
		}
		printf("NO\n");
	}
	return 0;
}