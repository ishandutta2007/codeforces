#include <bits/stdc++.h>
using namespace std;
#define MAX_N 200005

int adj[MAX_N], dfs_low[MAX_N], dfs_idx[MAX_N], nodeToSCCNum[MAX_N], sz[MAX_N] = {}, idx = 0, cn = 0;
stack<int> s;
bitset<200005> on_stack;

void dfs(int n) {
	dfs_idx[n] = dfs_low[n] = idx++;
	s.push(n);
	on_stack[n] = 1;
	int u = adj[n];
	if (dfs_idx[u] == -1) dfs(u), dfs_low[n] = min(dfs_low[n], dfs_low[u]);
	else if (on_stack[u]) dfs_low[n] = min(dfs_low[n], dfs_idx[u]);
	if (dfs_low[n] == dfs_idx[n]) {
		unordered_set<int> acc;
		while (true) {
			int curr = s.top();
			s.pop();
			on_stack[curr] = 0;
			nodeToSCCNum[curr] = cn;
			sz[cn]++;
			if (curr == n) break;
		}
		cn++;
	}
}

int main() {
	int q;
	scanf("%d", &q);
	while (q--) {
		int n, tmp;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &tmp), adj[i] = tmp;
		on_stack.reset();
		fill(dfs_idx, dfs_idx + MAX_N, -1);
		for (int i = 1; i <= n; i++) {
			if (dfs_idx[i] == -1) dfs(i);
		}
		for (int i = 1; i <= n; i++) {
			printf("%d ", sz[nodeToSCCNum[i]]);
		}
		printf("\n");
	}
}