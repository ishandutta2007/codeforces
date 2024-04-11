#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

const int N = 500000;

std :: vector <int> edge[N];
std :: vector <int> leaf;

void dfs (int x, int par, int d) {
	if (edge[x].size() == 1 && x) {
		leaf.push_back(d);
		return;
	}
	
	for (int i=0; i<edge[x].size(); i++) {
		if (edge[x][i] == par) continue;
		dfs (edge[x][i], x, d + 1);
	}	
	
	return;
}

int main () {
	int n;
	scanf ("%d", &n);
	
	int u, v;
	for (int i=1; i<n; i++) {
		scanf ("%d %d", &u, &v);
		u--, v--;
		
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	
	int maks = 0;
	for (int i=0; i<edge[0].size(); i++) {
		leaf.clear();
		dfs (edge[0][i], 0, 0);
		
		std :: sort (leaf.begin(), leaf.end(), std :: greater <int> ());
		
		for (int j=0; j<leaf.size(); j++)
			maks = std :: max (maks, leaf[j] + j);
	}
		
	printf ("%d\n", maks + 1);
	
	return 0;
}