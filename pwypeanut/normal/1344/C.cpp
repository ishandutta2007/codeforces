#include <bits/stdc++.h>
using namespace std;

int N, M;
bool vis[200005], instack[200005], fail = 0, vis2[200005];
vector<int> adjlist_f[200005];
vector<int> adjlist_b[200005];
char ans[200005];

void dfs(int x) {
	if (vis[x]) return;
	else vis[x] = 1;
	instack[x] = 1;
	for (int i = 0; i < adjlist_f[x].size(); i++) {
		if (instack[adjlist_f[x][i]]) fail = 1;
		if (!vis[adjlist_f[x][i]]) {
			dfs(adjlist_f[x][i]);
		}
	}
	instack[x] = 0;
}

void dfs2(int x) {
	if (vis2[x]) return;
	else vis2[x] = 1;
	for (int i = 0; i < adjlist_b[x].size(); i++) {
		if (!vis2[adjlist_b[x][i]]) {
			dfs2(adjlist_b[x][i]);
		}
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		adjlist_f[a].push_back(b);
		adjlist_b[b].push_back(a);
	}
	for (int i = 0; i < N; i++) {
		if (!vis[i]) dfs(i);
	}
	if (fail) {
		printf("-1\n");
		return 0;
	}
	int fans = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < N; i++) {
		if (!vis[i] && !vis2[i]) {
			ans[i] = 'A';
			fans++;
		} else ans[i] = 'E';
		dfs(i);
		dfs2(i);
	}
	printf("%d\n", fans);
	for (int i = 0; i < N; i++) printf("%c", ans[i]);
	printf("\n");
}