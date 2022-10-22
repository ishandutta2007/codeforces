#include <bits/stdc++.h>
using namespace std;

int N, M, col[300005], mini[300005];
vector<int> nc[300005], cn[300005], v[300005];
set<int> nos[300005];

void add(int node, int val) {
	nos[node].insert(val);
	while (nos[node].find(mini[node]) != nos[node].end()) mini[node]++;
}

void dfs(int x, int p) {
	for (int i = 0; i < nc[x].size(); i++) {
		int ic = nc[x][i];
		if (col[ic] != -1) continue;
		col[ic] = mini[x];
		int assign = mini[x];
		add(x, assign);
		for (int j = 0; j < cn[ic].size(); j++) add(cn[ic][j], assign);
	}
	for (int i = 0; i < v[x].size(); i++) if (v[x][i] != p) dfs(v[x][i], x);
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		while (x--) {
			int y;
			scanf("%d", &y);
			y--;
			nc[i].push_back(y);
			cn[y].push_back(i);
		}
	}
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	memset(col, -1, sizeof(col));
	dfs(0, -1);
	for (int i = 0; i < M; i++) if (col[i] == -1) col[i] = 0;
	for (int i = 0; i < M; i++) col[i]++;
	int mx = 0;
	for (int i = 0; i < M; i++) mx = max(mx, col[i]);
	printf("%d\n", mx);
	for (int i = 0; i < M; i++) {
		if (i) printf(" ");
		printf("%d", col[i]);
	}
	printf("\n");
}