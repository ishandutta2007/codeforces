#include <bits/stdc++.h>
using namespace std;

int N, K, dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}}, cur;
bool vis[505][505];
int col[505][505], sze[250005], countX, cnt[250005], totalcnt;
char g[505][505];

bool cv(int x, int y) {
	if (x < 0 || x >= N) return false;
	if (y < 0 || y >= N) return false;
	if (g[x][y] == 'X') return false;
	return true;
}

bool wr(int x, int y) {
	if (x < 0 || x >= N) return false;
	if (y < 0 || y >= N) return false;
	//if (g[x][y] == 'X') return false;
	return true;
}

void dfs(int x, int y) {
	if (vis[x][y]) return;
	else vis[x][y] = 1;
	col[x][y] = cur;
	for (int i = 0; i < 4; i++) {
		int newx = x + dir[i][0], newy = y + dir[i][1];
		if (!cv(newx, newy)) continue;
		dfs(newx, newy);
	}
}

void add(int x, int y) {
	//printf("add %d %d\n", x, y);
	if (g[x][y] == 'X') countX++;
	else {
		cnt[col[x][y]]++;
		if (cnt[col[x][y]] == 1) {
			//printf("color %d added\n", col[x][y]);
			totalcnt += sze[col[x][y]];
		}
	}
}

void rem(int x, int y) {
	//printf("rem %d %d\n", x, y);
	if (g[x][y] == 'X') countX--;
	else {
		cnt[col[x][y]]--;
		if (cnt[col[x][y]] == 0) {
			//printf("color %d removed\n", col[x][y]);
			totalcnt -= sze[col[x][y]];
		}
	}
}

void add_rect(int x, int y) {
	for (int i = 0; i < K; i++) if (wr(x-1, y+i)) add(x-1, y+i);
	for (int i = 0; i < K; i++) if (wr(x+K, y+i)) add(x+K, y+i);
	for (int i = 0; i < K; i++) if (wr(x+i, y-1)) add(x+i, y-1);
	for (int i = 0; i < K; i++) if (wr(x+i, y+K)) add(x+i, y+K);
}

void rem_rect(int x, int y) {
	for (int i = 0; i < K; i++) if (wr(x-1, y+i)) rem(x-1, y+i);
	for (int i = 0; i < K; i++) if (wr(x+K, y+i)) rem(x+K, y+i);
	for (int i = 0; i < K; i++) if (wr(x+i, y-1)) rem(x+i, y-1);
	for (int i = 0; i < K; i++) if (wr(x+i, y+K)) rem(x+i, y+K);
}

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) scanf("%s", &g[i]);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!vis[i][j] && g[i][j] == '.') {
				dfs(i, j);
				cur++;
			}
		}
	}
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (g[i][j] == '.') sze[col[i][j]]++;
	int ans = 0;
	for (int i = 0; i < N - K + 1; i++) {
		countX = 0;
		for (int j = 0; j < K; j++) {
			for (int k = 0; k < K; k++) {
				add(i + j, k);
			}
		}
		int curX = countX;
		add_rect(i, 0);
		ans = max(ans, curX + totalcnt);
		//printf("%d, %d: %d\n", i, 0, curX + totalcnt);
		rem_rect(i, 0);
		for (int j = 1; j < N - K + 1; j++) {
			for (int k = 0; k < K; k++) add(i+k,j+K-1);
			for (int k = 0; k < K; k++) rem(i+k,j-1);
			curX = countX;
			add_rect(i, j);
			ans = max(ans, curX + totalcnt);
			//printf("%d, %d: %d + %d = %d (%d)\n", i, j, curX, totalcnt, curX + totalcnt, cnt[0]);
			rem_rect(i, j);
		}
		for (int j = 0; j < K; j++) {
			for (int k = 0; k < K; k++) {
				rem(i + j, N - k - 1);
			}
		}
	}
	printf("%d\n", ans);
}