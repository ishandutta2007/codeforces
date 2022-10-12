#include <cstdio>
#include <vector>

const int N = 100000;

std::vector <int> edge[N];

bool vis[N];
int size[N];
void computeSize (int u, int par) {
	if (vis[u]) {
		size[u] = 0;
		return;
	}
	
	size[u] = 1;
	for (int i=0; i<edge[u].size(); i++) {
		int v = edge[u][i];
		
		if (v == par) continue;
		computeSize (v, u);
		size[u] += size[v];
	}
}

int ans[N];
void solve (int u, int par, int officer) {
	//printf ("%d %d", u, officer);
	computeSize(u, u);
	int half = size[u] >> 1;
	
	bool centroid = 0;
	while (!centroid) {
		centroid = 1;
		for (int i=0; i<edge[u].size(); i++) {
			int v = edge[u][i];
			if (v == par) continue;
			
			if (half < size[v]) {
				centroid = 0;
				par = u; u = v;
				break;
			}
		}
	}
	
	vis[u] = 1;
	ans[u] = officer;
	for (int i=0; i<edge[u].size(); i++) {
		int v = edge[u][i];
		if (vis[v]) continue;
		
		solve (v, u, officer + 1);
	}
}

int main () {
	int n;
	scanf ("%d", &n);
	
	int u, v;
	for (int i=1; i<n; i++) {
		scanf ("%d %d", &u, &v);
		u--, v--;
		
		edge[u].push_back (v);
		edge[v].push_back (u);
	}
	
	solve (0, 0, 0);
	for (int i=0; i<n; i++) printf ("%c%c", ans[i] + 'A', i < n - 1 ? ' ' : '\n');	
	
	return 0;
}