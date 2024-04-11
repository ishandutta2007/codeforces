#include <bits/stdc++.h>
using namespace std;

int N, p[300005], depth[300005], renum[300005], cur, twok[300005][20], end1[300005], M;
vector<int> roots;
vector<int> level[300005];
vector<int> adjlist[300005];

void dfs(int x, int p, int d) {
	depth[x] = d;
	renum[x] = cur;
	level[depth[x]].push_back(cur);
	cur++;
	twok[x][0] = p;
	for (int i = 1; i <= 19; i++) {
		if (twok[x][i - 1] == -1) break;
		twok[x][i] = twok[twok[x][i - 1]][i - 1];
	}
	for (int i = 0; i < adjlist[x].size(); i++) if (adjlist[x][i] != p) dfs(adjlist[x][i], x, d + 1);
	end1[x] = cur;
}

int kth_parent(int x, int k) {
	for (int i = 0; i <= 19; i++) if ((k & (1 << i)) && x != -1) x = twok[x][i];
	return x;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &p[i]);
		p[i]--;
		if (p[i] != -1) adjlist[p[i]].push_back(i);
		if (p[i] == -1) roots.push_back(i);
	}
	memset(twok, -1, sizeof(twok));
	for (int i = 0; i < roots.size(); i++) dfs(roots[i], -1, 0);
	scanf("%d", &M);
	while (M--) {
		int v, k;
		scanf("%d%d", &v, &k);
		v--;
		int p = kth_parent(v, k);
		if (p == -1) {
			printf("0 ");
			continue;
		}
		int d = depth[v];
		printf("%d ", lower_bound(level[d].begin(), level[d].end(), end1[p]) - lower_bound(level[d].begin(), level[d].end(), renum[p]) - 1);
	}
	printf("\n");
}