#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000;
int n, m, a[maxn + 10], fa[maxn + 10], id[maxn + 10];
int d[maxn + 10], f[maxn + 10];
vector<int> g[maxn + 10];
queue<int> q;

int getf(int p) {
	return fa[p] == p ? p : fa[p] = getf(fa[p]);
}

int getid(int x, int y) {
	return (x - 1) * m + y;
}

bool cmp(int x, int y) {
	return a[x] < a[y];
}

void merge(int n) {
	sort(id + 1, id + n + 1, cmp);
	for (int i = 2; i <= n; ++i)
		if (a[id[i]] == a[id[i - 1]])
			fa[getf(id[i])] = getf(id[i - 1]);
}

void adde(int x, int y) {
	x = getf(x); y = getf(y);
	g[x].push_back(y); ++d[y];
}

void build(int n) {
	sort(id + 1, id + n + 1, cmp);
	int pre = id[1];
	for (int i = 2; i <= n; ++i)
		if (a[id[i]] != a[pre]) {
			adde(pre, id[i]); pre = id[i];
		}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= m; ++j)
			scanf("%d", &a[getid(i, j)]);
	for (int i = 1; i <= n * m; ++i) fa[i] = i;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) id[j] = getid(i, j);
		merge(m);
	}
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) id[j] = getid(j, i);
		merge(n);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) id[j] = getid(i, j);
		build(m);
	}
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) id[j] = getid(j, i);
		build(n);
	}
	for (int i = 1; i <= n * m; ++i)
		if (fa[i] == i && !d[i]) {
			q.push(i); f[i] = 1;
		}
	while (!q.empty()) {
		int p = q.front(); q.pop();
		for (int i = 0; i < g[p].size(); ++i) {
			int e = g[p][i]; f[e] = max(f[e], f[p] + 1);
			if (!--d[e]) q.push(e);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			printf("%d ", f[getf(getid(i, j))]);
		printf("\n");
	}
}