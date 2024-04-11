#include <bits/stdc++.h>
using namespace std;

int N, M, K, ans, selection[10];
bool invalid[10][10], conflict[10][10][10][10];

vector<int> dests[10][10];
vector<int> nodes[10];
vector< pair<int, int> > adjlist[200005];

void dfs(int x) {
	if (x == K + 1) {
		ans++;
		return;
	}
	for (int i = 0; i < x; i++) {
		if (invalid[x][i]) continue;
		bool fail = 0;
		for (int j = 1; j < x; j++) {
			if (conflict[j][selection[j]][x][i]) {
				fail = 1;
				break;
			}
		}
		if (!fail) {
			selection[x] = i;
			dfs(x + 1);
		}
	}
}

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < M; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		u--;
		v--;
		adjlist[u].push_back(make_pair(w, v));
	}
	for (int i = 0; i < N; i++) sort(adjlist[i].begin(), adjlist[i].end());
	for (int i = 0; i < N; i++) nodes[adjlist[i].size()].push_back(i);
	for (int i = 1; i <= K; i++) {
		for (int target = 0; target < i; target++) {
			for (int j = 0; j < nodes[i].size(); j++) {
				int node = nodes[i][j];
				dests[i][target].push_back(adjlist[node][target].second);
			}
		}
	}
	for (int i = 1; i <= K; i++) for (int j = 0; j < i; j++) sort(dests[i][j].begin(), dests[i][j].end());
	for (int i = 1; i <= K; i++) {
		for (int j = 0; j < i; j++) {
			int val = unique(dests[i][j].begin(), dests[i][j].end()) - dests[i][j].begin();
			if (val != dests[i][j].size()) invalid[i][j] = 1;
		}
	}
	for (int i = 1; i <= K; i++) {
		for (int j = 0; j < i; j++) {
			for (int i2 = i + 1; i2 <= K; i2++) {
				for (int j2 = 0; j2 < i2; j2++) {
					vector<int> *v1 = &dests[i][j];
					vector<int> *v2 = &dests[i2][j2];
					if (v1->size() < v2->size()) swap(v1, v2);
					bool fail = 0;
					for (int k = 0; k < v2->size(); k++) {
						int p = lower_bound(v1->begin(), v1->end(), (*v2)[k]) - v1->begin();
						if (p != v1->size() && (*v1)[p] == (*v2)[k]) {
							fail = 1;
							break;
						}
					}
					conflict[i][j][i2][j2] = fail;
				}
			}
		}
	}
	dfs(1);
	printf("%d\n", ans);
}