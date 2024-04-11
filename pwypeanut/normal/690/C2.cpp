#include <bits/stdc++.h>
using namespace std;

int N, E, mxd, mxnode;
vector<int> v[1000005];

void dfs(int x, int d, int p) {
	if (d > mxd) {
		mxd = d;
		mxnode = x;
	}
	for (int i = 0; i < v[x].size(); i++) if (v[x][i] != p) dfs(v[x][i], d + 1, x);
}

int main() {
	scanf("%d%d", &N, &E);
	for (int i = 0; i < E; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	mxd = -1;
	dfs(0, 0, -1);
	mxd = -1;
	dfs(mxnode, 0, -1);
	printf("%d\n", mxd);
}