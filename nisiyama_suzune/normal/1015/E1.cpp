#include <bits/stdc++.h>

int N, M;
char str[1100][1100];
int rpre[1100][1100], rsuf[1100][1100];
int cpre[1100][1100], csuf[1100][1100];
int res[1100][1100];
int rval[1100][1100], cval[1100][1100];
int vis[1100][1100];

int main () {
	std::ios::sync_with_stdio (0);
	std::cin >> N >> M;
	for (int i = 1; i <= N; ++i) for (int j = 1; j <= M; ++j) std::cin >> str[i][j];
	for (int i = 1; i <= N; ++i) for (int j = 1; j <= M; ++j) if (str[i][j] == '*')
		rpre[i][j] = rpre[i][j - 1] + 1, cpre[i][j] = cpre[i - 1][j] + 1;
	for (int i = N; i >= 1; --i) for (int j = M; j >= 1; --j) if (str[i][j] == '*')
		rsuf[i][j] = rsuf[i][j + 1] + 1, csuf[i][j] = csuf[i + 1][j] + 1;
	for (int i = 1; i <= N; ++i) for (int j = 1; j <= M; ++j) { 
		res[i][j] = std::min (std::min (rpre[i][j], cpre[i][j]), std::min (rsuf[i][j], csuf[i][j])) - 1;
		if (res[i][j] > 0) rval[i][j - res[i][j]] = res[i][j] * 2 + 1, cval[i - res[i][j]][j] = res[i][j] * 2 + 1;
	}
	for (int i = 1; i <= N; ++i) {
		int col = 0;
		for (int j = 1; j <= M; ++j) {
			col = std::max (col, rval[i][j]);
			if (col) vis[i][j] = true;
			--col;
		}
	}
	for (int j = 1; j <= M; ++j) {
		int col = 0;
		for (int i = 1; i <= N; ++i) {
			col = std::max (col, cval[i][j]);
			if (col) vis[i][j] = true;
			--col;
		}
	}
	for (int i = 1; i <= N; ++i) for (int j = 1; j <= M; ++j) if (vis[i][j] == 0 && str[i][j] == '*') {
		std::cout << -1 << "\n"; return 0;
	}
	int ans = 0;
	for (int i = 1; i <= N; ++i) for (int j = 1; j <= M; ++j) if (res[i][j] > 0) ++ans;
	std::cout << ans << "\n";
	for (int i = 1; i <= N; ++i) for (int j = 1; j <= M; ++j) if (res[i][j] > 0) 
		std::cout << i << " " << j << " " << res[i][j] << "\n";
}