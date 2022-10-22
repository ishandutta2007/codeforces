#include <bits/stdc++.h>
using namespace std;

int N, col[200005];
vector<int> v[200005];

void dfs(int x, int p, int c) {
	col[x] = c;
	int cur = 0;
	for (int i = 0; i < v[x].size(); i++) {
		if (v[x][i] != p) {
			while (cur == col[x] || (p != -1 && cur == col[p])) cur++;
			dfs(v[x][i], x, cur);
			cur++;
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(0, -1, 0);
	int mx = 0;
	for (int i = 0; i < N; i++) mx = max(mx, col[i]);
	printf("%d\n", mx+1);
	for (int i = 0; i < N; i++) {
		if (i) printf(" ");
		printf("%d", col[i] + 1);
	}
	printf("\n");
}