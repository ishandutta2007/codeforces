#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <vector>
#define mp(a,b) make_pair(a,b)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int n, k;

char buf[3][200];

vector<int> adj[500];

int chkup(int i, int j) {
	if (i == 0) return 0;
	if (buf[i][j + 1] != '.') return 0;
	if (buf[i - 1][j + 1] != '.') return 0;
	if (buf[i - 1][j + 2] != '.') return 0;
	if (buf[i - 1][j + 3] != '.') return 0;
	return 1;
}

int chkdown(int i, int j) {
	return i != 2 && buf[i][j + 1] == '.' && buf[i + 1][j + 1] == '.' && buf[i + 1][j + 2] == '.' && buf[i + 1][j + 3] == '.';
}

int chkfw(int i, int j) {
	return buf[i][j + 1] == '.' && buf[i][j + 2] == '.' && buf[i][j + 3] == '.';
}

int vis[500];

int dfs(int i) {
	vis[i] = 1;
	if (i % (n + 5) >= n - 1) {
		return 1;
	}
	for (auto &x : adj[i]) {
		if (vis[x]) continue;
		if (dfs(x)) return 1;
	}
	return 0;
}

int getind(int i, int j) {
	return (n + 5)*i + j;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		for (int i = 0; i < 500; i++) adj[i].clear();
		memset(vis, 0, sizeof(vis));
		scanf("%d %d", &n, &k);
		scanf("%s %s %s", buf[0], buf[1], buf[2]);
		for (int i = 0; i < 3; i++) buf[i][n] = buf[i][n + 1] = buf[i][n + 2] = '.';
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < n; j++) {
				if (chkup(i, j)) {
					adj[getind(i, j)].push_back(getind(i - 1, j + 3));
				}
				if (chkfw(i, j)) {
					adj[getind(i, j)].push_back(getind(i, j + 3));
				}
				if (chkdown(i, j)) {
					adj[getind(i, j)].push_back(getind(i + 1, j + 3));
				}
			}
		}

		int start;
		for (int i = 0; i < 3; i++) {
			if (buf[i][0] == 's') start = getind(i, 0);
		}
		if (dfs(start)) puts("YES");
		else puts("NO");
	}
}