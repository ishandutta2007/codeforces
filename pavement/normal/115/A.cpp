#include <bits/stdc++.h>
using namespace std;
#define MAX_N 2005

vector<int> adj[MAX_N];
int maxD = -1;

void dfs(int n, int e, int d) {
	maxD = max(maxD, d);
	for (int u : adj[n]) {
		if (u != e) dfs(u, n, d + 1);
	}
}

int main() {
	int n, p;
	scanf("%d", &n);
	bool s[n + 1] = {};
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p);
		if (p == -1) continue;
		adj[p].push_back(i);
		s[i] = true;
	}
	for (int i = 1; i <= n; i++) {
		if (!s[i]) dfs(i, -1, 1);
	}
	printf("%d\n", maxD);
}