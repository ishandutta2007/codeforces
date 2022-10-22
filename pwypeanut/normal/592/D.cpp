#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> impt_nodes;
long long ans = 0, dis[200005];
bool impt[200005];
vector< pair<int, int> > adjlist[200005];

int dfs(int x, int p) {
	int cur_sze = impt[x];
	for (int i = 0; i < adjlist[x].size(); i++) {
		if (adjlist[x][i].first != p) {
			int subtree_size = dfs(adjlist[x][i].first, x);
			if (subtree_size != 0 && subtree_size != K) ans += adjlist[x][i].second * 2;
			cur_sze += subtree_size;
		}
	}
	return cur_sze;
}

void dfs2(int x, int p, long long d) {
	dis[x] = d;
	for (int i = 0; i < adjlist[x].size(); i++) if (adjlist[x][i].first != p) dfs2(adjlist[x][i].first, x, d + adjlist[x][i].second);
}

int main() {
	scanf("%d%d", &N, &K);
	
	for (int i = 0; i < N-1; i++) {
		int a, b, c;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		c = 1;
		adjlist[a].push_back(make_pair(b, c));
		adjlist[b].push_back(make_pair(a, c));
	}
	
	for (int i = 0; i < K; i++) {
		int a;
		scanf("%d", &a);
		a--;
		impt[a] = 1;
		impt_nodes.push_back(a);
	}
	dfs(0, -1);
	dfs2(impt_nodes[0], -1, 0);
	long long far = -1;
	int node = -1;
	for (int i = 0; i < N; i++) {
		if (impt[i] && dis[i] > far) {
			far = dis[i];
			node = i;
		}
	}
	dfs2(node, -1, 0);
	int pnode = node;
	far = -1;
	for (int i = 0; i < N; i++) {
		if (impt[i] && dis[i] > far) {
			far = dis[i];
			node = i;
		}
	}
	printf("%d\n", min(node + 1, pnode + 1));
	printf("%lld\n", ans - far);
}