#include <bits/stdc++.h>
using namespace std;

int N, M, nodecount;
bool vis[100005];
vector<int> adjlist[100005];

void dfs(int x) {
	if (vis[x]) return;
	else vis[x] = 1;
	nodecount++;
	for (int i = 0; i < adjlist[x].size();i++) dfs(adjlist[x][i]);
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;b--;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	int happy = 0;
	for (int i = 0; i < N; i++) {
		if (!vis[i]) {
			nodecount = 0;
			dfs(i);
			happy += nodecount - 1;
		}
	}
	printf("%d\n", M - happy);
}