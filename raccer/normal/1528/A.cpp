#include <bits/stdc++.h>
using namespace std;

int T;
vector <int> from[100010];
int L[100010], R[100010];
long long f[100010], g[100010];

void dfs(int x, int last) {
	f[x] = g[x] = 0;
	for (auto v : from[x]) {
		if (v == last) continue;
		dfs(v, x);
		f[x] = f[x] + max(f[v] + abs(L[x] - L[v]), g[v] + abs(L[x] - R[v]));
		g[x] = g[x] + max(f[v] + abs(R[x] - L[v]), g[v] + abs(R[x] - R[v]));
	}
}

int main() {
	scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) from[i].clear();
		for (int i = 1; i <= n; i++) scanf("%d%d", &L[i], &R[i]);
		for (int i = 1; i < n; i++) {
			int x, y; scanf("%d%d", &x, &y);
			from[x].push_back(y);
			from[y].push_back(x);
		}
		dfs(1, 1);
		printf("%lld\n", max(f[1], g[1]));
	}
	return 0;
}