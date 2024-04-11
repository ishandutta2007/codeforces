#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
char s[100][100];

void dfs(int x, int y) {
	ans += s[x][y] == '*';
	int dx = -1, dy = -1, dis = 100000;
	for (int i = x; i <= n; ++i)
		for (int j = y; j <= m; ++j)
			if (i != x || j != y)
				if (s[i][j] == '*') {
					if (i - x + j - y < dis) {
						dx = i; dy = j;
						dis = i - x + j - y;
					} else if (i - x + j - y == dis && j > dy) {
						dx = i; dy = j;
					}
				}
	if (dx == -1) return;
	dfs(dx, dy);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s[i] + 1);
	}
	dfs(1, 1);
	printf("%d", ans);
}