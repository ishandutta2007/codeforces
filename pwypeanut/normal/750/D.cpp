#include <bits/stdc++.h>
using namespace std;

int N, T[35];
int dir[8][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
bool vis[305][305][8][31][5];
bool hit[305][305];

void recur(int id, int l, int d, int x, int y) {
	hit[x][y] = 1;
	if (vis[x][y][d][id][l]) return;
	else vis[x][y][d][id][l] =  1;
	if (l != 0) {
		// continue
		int tx = x + dir[d][0], ty = y + dir[d][1];
		recur(id, l - 1, d, tx, ty);
	} else {
		if (id == N - 1) return;
		int nd1 = (d + 1) % 8, nd2 = (d + 7) % 8;
		recur(id + 1, T[id + 1] - 1, nd1, x + dir[nd1][0], y + dir[nd1][1]);
		recur(id + 1, T[id + 1] - 1, nd2, x + dir[nd2][0], y + dir[nd2][1]);
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &T[i]);
	recur(0, T[0] - 1, 0, 152, 152);
	int ans = 0;
	for (int i = 0; i < 305; i++) {
		for (int j = 0; j < 305; j++) {
			if (hit[i][j]) ans++;
		}
	}
	printf("%d\n", ans);
}