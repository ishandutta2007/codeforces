#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

#define N 2010

#define A first
#define B second
#define MP make_pair

using namespace std;

vector<int> adj[N];

vector< pair<int, pair<int, int> > > V;
int F[N];

int d[N][N];
int n;
bool err = false;

void dfs(int u, int p, int val, int r) {
	if(d[r][u] != val) {
		err = true;
	}
	for(int j = 0;j < adj[u].size();j++) {
		int v = adj[u][j];
		if(v != p) {
			dfs(v, u, val + d[u][v], r);
		}
	}
}
int P(int j) {
	return F[j] == j ? j : F[j] = P(F[j]);
}
int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			scanf("%d", &d[i][j]);
		}
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			if(d[i][j] != d[j][i]) {
				err = true;
			}
			if(i != j && d[i][j] == 0) {
				err = true;
			}
			if(i == j && d[i][j]) {
				err = true;
			}
			if(i < j) {
				V.push_back(MP(d[i][j], MP(i,j)));
			}
		}
		F[i] = i;
	}
	sort(V.begin(), V.end());
	for(int i = 0;i < V.size();i++) {
		int u = V[i].B.A, v = V[i].B.B;
		if(P(u) != P(v)) {
			if(P(u) < P(v)) {
				F[P(v)] = P(u);
			}else {
				F[P(u)] = P(v);
			}
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}
	for(int i = 1;i <= n;i++) {
		dfs(i, -1, 0, i);
	}
	if(err) {
		printf("NO\n");
	}else {
		printf("YES\n");
	}
	return 0;
}