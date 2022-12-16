#include <bits/stdc++.h>

int mx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, my[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int N;
int AX, AY, BX, BY, CX, CY;
int map[1100][1100], vis[1100][1100];

bool is_valid (int x, int y) { return x >= 1 && x <= N && y >= 1 && y <= N; }

int main () {
	scanf ("%d", &N);
	scanf ("%d%d%d%d%d%d", &AX, &AY, &BX, &BY, &CX, &CY);
	for (int i = 1; i <= N; ++i) map[i][AY] = 1;
	for (int i = 1; i <= N; ++i) map[AX][i] = 1;
	{ int x = AX, y = AY; while (is_valid (x, y)) map[x][y] = 1, --x, --y; }
	{ int x = AX, y = AY; while (is_valid (x, y)) map[x][y] = 1, --x, ++y; }
	{ int x = AX, y = AY; while (is_valid (x, y)) map[x][y] = 1, ++x, ++y; }
	{ int x = AX, y = AY; while (is_valid (x, y)) map[x][y] = 1, ++x, --y; }
	std::queue <std::pair <int, int>> q; q.push ({BX, BY}); vis[BX][BY] = 1;
	while (!q.empty ()) {
		int x = q.front ().first, y = q.front ().second; q.pop ();
		for (int k = 0; k < 8; ++k) { int nx = x + mx[k], ny = y + my[k];
			if (is_valid (nx, ny) && !map[nx][ny] && !vis[nx][ny]) q.push ({nx, ny}), vis[nx][ny] = 1;
		}
	}
	if (vis[CX][CY]) puts ("YES"); else puts ("NO");
}