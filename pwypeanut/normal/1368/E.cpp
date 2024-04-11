#include <bits/stdc++.h>
using namespace std;

int N, T, E, dis[200005];
vector<int> parents[200005], children[200005];

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &E);
		for (int i = 1; i <= N; i++) {
			parents[i].clear();
			children[i].clear();
		}
		for (int i = 1; i <= N; i++) dis[i] = 0;
		for (int i = 0; i < E; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			parents[b].push_back(a);
		}
		vector<int> closed;
		for (int i = 1; i <= N; i++) {
			int mx = 0;
			for (int j = 0; j < (int)parents[i].size(); j++) mx = max(mx, dis[parents[i][j]] + 1);
			if (mx == 2) {
				closed.push_back(i);
				dis[i] = -1;
			} else dis[i] = mx;
		}
		printf("%d\n", (int)closed.size());
		for (int i = 0; i < (int)closed.size(); i++) {
			if (i) printf(" ");
			printf("%d", closed[i]);
		}
		printf("\n");
	}
}