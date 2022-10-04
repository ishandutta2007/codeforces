#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

int dist[500000];
int chk[1000001];
vector<int> adj[500000];
vector<int> lea;
queue<int> q;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < n; i++)dist[i] = 2000000000;
	dist[0] = 0;
	int ans = -1;
	for (auto &x : adj[0]) {
		dist[x] = 1;
		q.push(x);
		while (!q.empty()) {
			int u = q.front();  q.pop();
			int cnt = 0;
			for (auto &v : adj[u]) {
				if (dist[v] < 2000000000) continue;
				dist[v] = dist[u] + 1;
				cnt++;
				q.push(v);
			}
			if (cnt == 0) lea.push_back(dist[u]);
		}
		int curmin = 0;
		sort(lea.begin(), lea.end());
		for (auto &x : lea) {
			if (x > curmin) curmin = x + 1;
			else curmin++;
		}
		ans = max(ans, curmin - 1);
		lea.clear();
	}
	printf("%d", ans);
}