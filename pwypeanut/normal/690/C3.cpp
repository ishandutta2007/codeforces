#include <bits/stdc++.h>
using namespace std;

int N, p[200005], twok[200005][18], depth[200005];
vector<int> v[200005];

void dfs(int x, int p, int d) {
	twok[x][0] = p;
	depth[x] = d;
	for (int i = 1; i <= 17; i++) {
		if (twok[x][i - 1] == -1) break;
		twok[x][i] = twok[twok[x][i - 1]][i - 1];
	}
	for (int i = 0; i < v[x].size(); i++) if (v[x][i] != p) dfs(v[x][i], x, d + 1);
}

int lca(int x, int y) {
	if (depth[x] > depth[y]) {
		int dd = depth[x] - depth[y];
		for (int i = 0; i <= 17; i++) if (dd & (1 << i)) x = twok[x][i];
	}
	if (depth[y] > depth[x]) {
		int dd = depth[y] - depth[x];
		for (int i = 0; i <= 17; i++) if (dd & (1 << i)) y = twok[y][i];
	}
	if (x == y) return x;
	for (int i = 17; i >= 0; i--) {if (twok[x][i] != twok[y][i]) { x=twok[x][i];y=twok[y][i];}}
	return twok[x][0];
}

int d(int x, int y) {
	//printf("%d %d  = %d\n", x, y, depth[x] + depth[y] - 2 * depth[lca(x, y)]);
	return depth[x] + depth[y] - 2 * depth[lca(x, y)];
}

int node1 = 0, node2 = 1, dis = 1;

int main() {
	scanf("%d", &N);
	for (int i = 1; i < N; i++) {
		int x;
		scanf("%d", &x);
		p[i] = x - 1;
		v[x - 1].push_back(i);
	}
	dfs(0, -1, 0);
	printf("1");
	for (int i = 2; i < N; i++) {
		int n2l = d(i, node1), n2r = d(i, node2);
		int o1 = node1, o2 = node2;
		if (n2l > dis) {
			dis = n2l;
			node1 = i;
			node2 = o1;
		}
		if (n2r > dis) {
			dis = n2r;
			node1 = i;
			node2 = o2;
		}
		printf(" %d", dis);
	}
	printf("\n");
}