#include <stdio.h>
#include <math.h>
#include <vector>

#define N 100010
#define LG_N 20

using namespace std;

int n, q;
int sz[N];

vector<int> E, H, adj[N];
int first[N], len[N], P[N];

int TB[LG_N][4*N];
int TB_P[LG_N][4*N];

void dfs(int u, int p, int h) {
	P[u] = p;
	len[u] = h;
	sz[u] = 1;
	first[u] = E.size();
	E.push_back(u);
	H.push_back(h);
	
	for(int i = 0;i < adj[u].size();i++) {
		int v = adj[u][i];
		if(v == p) {
			continue;
		}
		dfs(v, u, h+1);
		sz[u] += sz[v];
		E.push_back(u);
		H.push_back(h);
	}
}
void init_LCA(void) {
	for(int i = 0;i < LG_N;i++) {
		for(int j = 0;j < E.size();j++) {
			if(i == 0) {
				TB[i][j] = E[j];
			}else {
				int u = TB[i-1][j], v = TB[i-1][min((int)E.size()-1, j + (1 << (i-1)))];
				TB[i][j] = (len[u] <= len[v] ? u : v);
			}
		}
	}
}
int log2(int l) {
	int x = 0;
	while((1 << (x+1)) <= l) {
		x++;
	}
	return x;
}
int lca(int u, int v) {
	if(first[u] > first[v]) {
		swap(u, v);
	}
	int lg = log2(first[v] - first[u] + 1);
	int l1 = TB[lg][first[u]], l2 = TB[lg][first[v] - (1 << lg) + 1];
	return len[l1] <= len[l2] ? l1 : l2; 
}
void init_Parent(void) {
	for(int i = 0;i < LG_N;i++) {
		for(int j = 1;j <= n;j++) {
			if(i == 0) {
				TB_P[i][j] = P[j];
			}else {
				TB_P[i][j] = TB_P[i-1][TB_P[i-1][j]];
			}
		}
	}
}
int Parent(int u, int l) {
	while(l > 0) {
		int lg = log2(l);
		u = TB_P[lg][u];
		l -= (1 << lg);
	}
	return u;
}
int main() {
	scanf("%d", &n);
	for(int i = 0;i < n-1;i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(1, 1, 0);

	init_LCA();
	init_Parent();

	scanf("%d", &q);
	while(q--) {
		int u, v;
		scanf("%d%d", &u, &v);
		if(u == v) {
			printf("%d\n", n);
			continue;
		}
		int l = lca(u, v);
		int dis = len[u] + len[v] - 2 * len[l];
		if(dis%2) {
			printf("0\n");
			continue;
		}
		int mid = dis / 2;
		if(len[u] == len[v]) {
			int b1 = Parent(u, mid-1), b2 = Parent(v, mid-1);
			printf("%d\n", n - sz[b1] - sz[b2]);
		}else if(len[u] > len[v]) {
			int b1 = Parent(u, mid-1), b2 = Parent(u, mid);
			printf("%d\n", sz[b2] - sz[b1]);
		}else {
			int b2 = Parent(v, mid-1), b1 = Parent(v, mid);
			printf("%d\n", sz[b1] - sz[b2]);
		}
	}
	return 0;
}