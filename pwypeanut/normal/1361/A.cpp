#include <bits/stdc++.h>
using namespace std;

int N, E, T[500005];
bool pushed[500005], used[500005];
queue<int> Q;
set<int> S[500005];
vector<int> ans;
vector<int> adjlist[500005];

int main() {
	scanf("%d%d", &N, &E);
	for (int i = 0; i < E; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	for (int i = 0; i < N; i++) scanf("%d", &T[i]);
	for (int i = 0; i < N; i++) {
		if (T[i] == 1) {
			Q.push(i);
			pushed[i] = 1;
		}
	}
	while (!Q.empty()) {
		int p = Q.front();
		Q.pop();
		ans.push_back(p + 1);
		used[p] = 1;
		if (S[p].size() == T[p] - 1) {
			/* correct */
			for (int i = 0; i < adjlist[p].size(); i++) {
				int other = adjlist[p][i];
				if (used[other]) continue;
				if (T[p] >= T[other]) {
					printf("-1\n");
					return 0;
				}
				S[other].insert(T[p]);
				if (S[other].size() == T[other] - 1 && !pushed[other]) {
					pushed[other] = 1;
					Q.push(other);
				}
			}
		} else {
			printf("-1\n");
			return 0;
		}
	}
	if (ans.size() != N) {
		printf("-1\n");
		return 0;
	}
	for (int i = 0; i < ans.size(); i++) {
		if (i) printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
		
}