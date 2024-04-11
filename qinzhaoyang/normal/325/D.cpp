#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int sx[] = {1, -1, 0, 0, 1, 1, -1, -1}, zy[] = {0, 0, 1, -1, -1, 1, 1, -1}, N = 3010;

int r, c, n, vis[N][N * 2], id[N][N * 2], cnt, fa[N * N * 2], dep[N * N * 2], ans;

stack <pair<int,int> > s;

int find(int x) {
	return fa[x] == x ? x : find(fa[x]);
}

void con(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	if (dep[x] > dep[y]) swap(x, y);
	fa[x] = y;
	if (dep[x] == dep[y]) dep[y]++, s.push(make_pair(x, y));
	else s.push(make_pair(x, 0));
}

int in(int x, int y) {
	return 1 <= x && x <= r && 1 <= y && y <= 2 * c;
}

int main() {
	scanf("%d%d%d", &r, &c, &n);
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= 2 * c; j++)
			id[i][j] = ++cnt;
	for (int i = 1; i <= r * c * 2; i++) fa[i] = i;
	while (n--) {
		int x, y; scanf("%d%d", &x, &y);
		while (s.size()) s.pop();
		vis[x][y] = vis[x][y + c] = 1;
		for (int i = 0; i < 8; i++) {
			int dx = x + sx[i], dy = y + zy[i];
			if (dy <= 0) dy += 2 * c;
			if (!in(dx, dy) || !vis[dx][dy]) continue;
			con(id[dx][dy], id[x][y]);
		}
		for (int i = 0; i < 8; i++) {
			int dx = x + sx[i], dy = y + c + zy[i];
			if (dy > 2 * c) dy -= 2 * c;
			if (!in(dx, dy) || !vis[dx][dy]) continue;
			con(id[dx][dy], id[x][y + c]);
		}
		if (find(id[x][y]) == find(id[x][y + c])) {
			while (s.size()) {
				int x = s.top().first, y = s.top().second;
				fa[x] = x; if (y) dep[y]--; s.pop();
			}
			vis[x][y] = vis[x][y + c] = 0;
		}
		else ans++;
	}
	printf("%d\n", ans);
	return 0;
}