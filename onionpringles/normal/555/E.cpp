#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <set>
#include <algorithm>
#include <string.h>

using namespace std;

const int MN = 200000;

int par[MN];
int anc[MN];
int rnk[MN];
int tec[MN];
int cc[MN];
int vis[MN];
vector<int> adj[MN];
set<int> br[MN];
int ccn = 0;
int ccn2 = 0;
vector<int> adj2[MN];
int anc2[MN][18];
vector<int> qs[MN];

void dfs1(int i) {
	cc[i] = ccn;
	anc[i] = i;
	vis[i] = 1;
	int parfind = 0;
	for (auto &x : adj[i]) {
		if (!parfind && x == par[i]) {
			parfind = 1;
			continue;
		}
		if (vis[x]) {
			if (rnk[x] < rnk[anc[i]]) anc[i] = x;
			continue;
		}
		par[x] = i;
		rnk[x] = rnk[i] + 1;
		dfs1(x);
		if (rnk[anc[x]] < rnk[anc[i]]) anc[i] = anc[x];
	}
	if (anc[i] == i && par[i] != -1) {
		int p = par[i];
		br[p].insert(i);
		br[i].insert(p);
	}
}

void dfs2(int i) {
	tec[i] = ccn2;
	vis[i] = 1;
	for (auto &x : adj[i]) {
		if (vis[x]) continue;
		if (br[i].find(x) != br[i].end()) continue;
		dfs2(x);
	}
}

void dfs3(int i) {
	vis[i] = 1;
	for (auto &x : adj2[i]) {
		if (vis[x]) continue;
		anc2[x][0] = i;
		rnk[x] = rnk[i] + 1;
		dfs3(x);
	}
}


int goup(int x, int d) {
	int LOG = 17;
	while (LOG >= 0) {
		if (d >= (1 << LOG)) {
			d -= (1 << LOG);
			x = anc2[x][LOG];
		}
		LOG--;
	}
	return x;
}



int lca(int x, int y) {
	if (rnk[x] < rnk[y]) swap(x, y);
	int d = rnk[x] - rnk[y];
	x = goup(x, d);
	if (x == y) return x;
	int log = 17;
	while (log >= 0) {
		if (anc2[x][log] != anc2[y][log]) {
			x = anc2[x][log];
			y = anc2[y][log];
		}
		log--;
	}
	return anc2[x][0];
}

void dfs4(int i) {
	vis[i] = 1;
	anc[i] = i;
	for (auto &x : adj2[i]) {
		if (vis[x]) continue;
		dfs4(x);
		if (rnk[anc[x]] < rnk[anc[i]]) anc[i] = anc[x];
	}
	for (auto &x : qs[i]) {
		int y = lca(x, i);
		if (y == x) {
			if (rnk[x] < rnk[anc[i]]) anc[i] = x;
		}
		else if (y == i) {
			int d = rnk[x] - rnk[i];
			int yy = goup(x, d - 1);
			if (anc[yy] != yy) {
				puts("No");
				exit(0);
			}
		}
		else {
			if (rnk[y] < rnk[anc[i]]) anc[i] = y;
			qs[y].push_back(x);
		}
	}

}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, q;
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--; v--;
		adj[u].push_back(v); adj[v].push_back(u);
	}
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		rnk[i] = 0;
		par[i] = -1;
		dfs1(i);
		ccn++;
	}
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		dfs2(i);
		ccn2++;
	}
	for (int i = 0; i < n; i++) {
		for (auto &x : br[i]) {
			adj2[tec[x]].push_back(tec[i]);
		}
	}
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < ccn2; i++) {
		if (vis[i]) continue;
		anc2[i][0] = -1;
		rnk[i] = 0;
		dfs3(i);
	}
	for (int i = 1; i < 18; i++) {
		for (int j = 0; j < ccn2; j++) {
			int a = anc2[j][i - 1];
			if (a == -1) anc2[j][i] = -1;
			else {
				anc2[j][i] = anc2[a][i - 1];
			}
		}
	}
	for (int i = 0; i < q; i++) {
		int s, d;
		scanf("%d%d", &s, &d);
		s--; d--;
		if (cc[s] != cc[d]) {
			puts("No");
			return 0;
		}
		qs[tec[s]].push_back(tec[d]);
	}
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < ccn2; i++) {
		if (vis[i]) continue;
		dfs4(i);
	}
	puts("Yes");
	return 0;
}