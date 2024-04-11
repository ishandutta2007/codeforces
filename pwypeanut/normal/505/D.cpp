#include <bits/stdc++.h>
using namespace std;

int N, E, ans, pos[200005];
vector<int> adjlist[200005], fadjlist[200005], nodes, topo;
bool vis[200005], vis2[200005];

void dfs(int x) {
	if (vis[x]) return;
	else vis[x] = 1;
	nodes.push_back(x);
	for (int i = 0; i < fadjlist[x].size(); i++) dfs(fadjlist[x][i]);
}

void dfs2(int x) {
	if (vis2[x]) return;
	else vis2[x] = 1;
	for (int i = 0; i < adjlist[x].size(); i++) dfs2(adjlist[x][i]);
	topo.push_back(x);
}

int main() {
	scanf("%d%d", &N, &E);
	for (int i = 0; i < E; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		adjlist[a].push_back(b);
		fadjlist[b].push_back(a);
		fadjlist[a].push_back(b);
	}
	for (int i = 0; i < N; i++) {
		if (vis[i]) continue;
		nodes.clear();
		dfs(i);
		topo.clear();
		for (int j = 0; j < nodes.size(); j++) dfs2(nodes[j]);
		for (int j = 0; j < topo.size(); j++) pos[topo[j]] = j;
		bool flag = 0;
		for (int j = 0; j < nodes.size(); j++) {
			for (int k = 0; k < adjlist[nodes[j]].size(); k++) {
				if (pos[nodes[j]] < pos[adjlist[nodes[j]][k]]) flag = 1;
			}
		}
		if (flag) ans += nodes.size();
		else ans += nodes.size() - 1;
	}
	printf("%d\n", ans);
}