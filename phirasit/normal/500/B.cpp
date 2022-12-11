#include <stdio.h>
#include <vector>
#include <algorithm>

#define N 310

using namespace std;

char str[N][N];
vector<int> idx, idx2, adj[N];
int pass[N];
int G[N];
int val[N];
int n;

void dfs(int u) {
	if(pass[u]) {
		return;
	}
	pass[u] = 1;
	idx.push_back(u);
	idx2.push_back(val[u]);
	for(int i = 0;i < adj[u].size();i++) {
		dfs(adj[u][i]);
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) {
		scanf("%d", &val[i]);
		pass[i] = 0;
	}
	for(int i = 1;i <= n;i++) {
		scanf("%s", str[i] + 1);
		for(int j = 1;j <= n;j++) {
			if(str[i][j] == '1') {
				adj[i].push_back(j);
			}
		}
	}
	for(int i = 1;i <= n;i++) {
		if(!pass[i]) {
			idx.clear();
			idx2.clear();
			dfs(i);
			sort(idx.begin(), idx.end());
			sort(idx2.begin(), idx2.end());
			for(int i = 0;i < idx.size();i++) {
				val[idx[i]] = idx2[i];
			}
		}
	}
	for(int i = 1;i <= n;i++) {
		printf("%d ", val[i]);
	}
	printf("\n");
	return 0;
}