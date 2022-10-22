#include <bits/stdc++.h>
using namespace std;

int N, M, K;
vector<int> v[200005];
vector<int> order;
bool vis[200005];

void dfs(int x) {
	if (vis[x]) return;
	else vis[x] = 1;
	order.push_back(x);
	for (int i = 0; i < v[x].size(); i++) {
		dfs(v[x][i]);
		if (order.back() != x) order.push_back(x);
	}
	
}

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(0);
	int allowed = (2 * N - 1) / K + 1;
	int cur = 0;
	for (int i = 0; i < K; i++) {
		int use = min((int)order.size() - cur, allowed);
		if (use == 0) {
			printf("1 1\n");
			continue;
		}
		printf("%d ", use);
		for (int j = 0; j < use; j++) printf("%d ", order[cur + j]+1);
		cur += use;
		printf("\n");
	}
}