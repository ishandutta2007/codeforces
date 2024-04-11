#include <bits/stdc++.h>
using namespace std;

int N, M;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
char g[1005][1005];
bool vis[1005][1005];

bool checkvalid(int x, int y) {
	if (x < 0 || x >= N) return false;
	if (y < 0 || y >= M) return false;
	if (vis[x][y]) return false;
	if (g[x][y] == '.') return false;
	return true;
}

void dfs(int x, int y) {
	if (vis[x][y]) return;
	else vis[x][y] = 1;
	//printf("%d %d\n", x, y);
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (checkvalid(nx, ny)) {
			dfs(nx, ny);
		}
	}
}

int rownth = 0, colnth = 0;


int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%s", g[i]);
	for (int i = 0; i < N; i++) {
		int mn = 1000000000, mx = 0;
		for (int j = 0; j < M; j++) {
			if (g[i][j] == '#') {
				mx = max(mx, j);
				mn = min(mn, j);
			}
		}
		if (mn == 1000000000 && mx == 0) rownth++;
		for (int j = 0; j < M; j++) {
			if (g[i][j] == '.' && j >= mn && j <= mx) {
				printf("-1\n");
				return 0;
			}
		}
	}
	
	for (int i = 0; i < M; i++) {
		int mn = 1000000000, mx = 0;
		for (int j = 0; j < N; j++) {
			if (g[j][i] == '#') {
				mx = max(mx, j);
				mn = min(mn, j);
			}
		}
		if (mn == 1000000000 && mx == 0) colnth++;
		for (int j = 0; j < N; j++) {
			if (g[j][i] == '.' && j >= mn && j <= mx) {
				printf("-1\n");
				return 0;
			}
		}
	}
	if (rownth == N && colnth == M) {
		printf("0\n");
		return 0;
	} else if ((rownth == 0 && colnth != 0) || (rownth != 0 && colnth == 0)) {
		printf("-1\n");
		return 0;
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!vis[i][j] && g[i][j] == '#') {
				ans++;
				dfs(i, j);
			}
		}
	}
	printf("%d\n", ans);
	
}