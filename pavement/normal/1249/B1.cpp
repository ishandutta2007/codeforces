#include <bits/stdc++.h>
using namespace std;

int main() {
	int q, n, tmp;
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &n);
		int adj[n + 1];
		for (int i = 1; i <= n; i++) {
			scanf("%d", &tmp);
			adj[i] = tmp;
		}
		for (int i = 1; i <= n; i++) {
			queue<pair<int, int> > q;
			q.emplace(i, 0);
			while (!q.empty()) {
				auto ii = q.front();
				q.pop();
				if (ii.first == i && ii.second) {
					printf("%d ", ii.second);
					break;
				}
				q.emplace(adj[ii.first], ii.second + 1);
			}
		}
		printf("\n");
	}
}