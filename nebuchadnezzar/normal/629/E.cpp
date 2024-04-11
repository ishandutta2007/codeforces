#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 1e5 + 5, bd = 20;

int n, m;
vector<int> graph[MAXN];
int binup[bd][MAXN];
ll sumd[MAXN];
int tree_sz[MAXN];
int tree_sz_up[MAXN];
ll d_up[MAXN];
int depth[MAXN];

int dfs(int v, int p, int d) {
 	depth[v] = d;
 	binup[0][v] = p;
 	for (int i = 1; i < bd; ++i) {
 	 	binup[i][v] = binup[i - 1][binup[i - 1][v]];
 	}
 	int num = 0;
 	tree_sz[v] = 1;
 	for (int to: graph[v]) {
 	 	if (to != p) {
 	 	 	dfs(to, v, d + 1);
 	 	 	tree_sz[v] += tree_sz[to];
			++num;
			sumd[v] += sumd[to] + tree_sz[to];
 	 	}
 	}

 	return 0;
}

int dfs2(int v, int p, ll du, int tsu) {
 	d_up[v] = du;
 	tree_sz_up[v] = tsu;
 	for (int to: graph[v]) {
 	 	if (to != p) {
 	 	 	dfs2(to, v, du + tsu + sumd[v] - sumd[to] - tree_sz[to], tsu + tree_sz[v] - tree_sz[to]);
 	 	}
 	}
 	return 0;
}

int get_lca(int a, int b) {
 	if (depth[a] > depth[b]) {
 	 	swap(a, b);
 	}
 	for (int i = bd - 1; i >= 0; --i) {
 	 	if (depth[a] <= depth[b] - (1 << i)) {
 	 		b = binup[i][b];
		}	
 	}

 	if (a == b) {
 	 	return a;
 	}

 	for (int i = bd - 1; i >= 0; --i) {
 	 	if (binup[i][a] != binup[i][b]) {
 	 		a = binup[i][a];
 	 		b = binup[i][b];
		}	
 	}
 	return binup[0][a];
}

int up_for(int v, int d) {
 	for (int i = bd - 1; i >= 0; --i) {
 	 	if (d >= (1 << i)) {
 	 	 	d -= 1 << i;
 	 	 	v = binup[i][v];
 	 	}
 	}
 	return v;
}

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);
	 
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n - 1; ++i) {
	 	int a, b;
	 	scanf("%d%d", &a, &b);
	 	--a; --b;
	 	graph[a].puba(b);
	 	graph[b].puba(a);
	}

	dfs(0, 0, 0);
	dfs2(0, 0, 0, 0);

	/*
	for (int i = 0; i < n; ++i) {
	 	cerr << sumd[i] << " " << tree_sz[i] << " " << d_up[i] << " " << tree_sz_up[i] << endl;
	}*/

	for (int i = 0; i < m; ++i) {
	 	int a, b;
	 	scanf("%d%d", &a, &b);
	 	--a; --b;
	 	int lca = get_lca(a, b);
	 	if (a != lca && b != lca) {
	 	 	//cerr << sumd[a] << " " << sumd[b] << " " << (depth[a] + depth[b] - 2 * depth[lca] + 1) * tree_sz[a] * tree_sz[b] << endl;
	 	 	printf("%.15f\n", (sumd[a] * tree_sz[b] + sumd[b] * tree_sz[a] + (double) (depth[a] + depth[b] - 2 * depth[lca] + 1) * tree_sz[a] * tree_sz[b]) / (double) tree_sz[a] / tree_sz[b]);
	 	} else {
	 	 	if (b == lca) {
	 	 	 	swap(a, b);
	 	 	}
	 	 	int tmp = up_for(b, depth[b] - depth[a] - 1);
	 	 	ll da = sumd[a] - sumd[tmp] - tree_sz[tmp] + d_up[a] + tree_sz_up[a];
	 	 	int sza = tree_sz[a] - tree_sz[tmp] + tree_sz_up[a];
	 	 	//cerr << da << " " << sza << endl;
	 	 	printf("%.15f\n", (da * tree_sz[b] + sumd[b] * sza + (double) (depth[b] - depth[a] + 1) * sza * tree_sz[b]) / (double) sza / tree_sz[b]);
	 	}	
	}

	return 0;
}