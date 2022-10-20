#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

int n, m;
char a[N];
vector<int> adj[N];
int dp[26][N];
int deg[N];

int main() {
	scanf("%d %d", &n, &m);
	scanf("%s", a + 1);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		deg[v]++;
	}
	queue<int> q;
	vector<int> list;
	for (int i = 1; i <= n; i++) {
		if (!deg[i]) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		list.push_back(u);
		for (int v : adj[u]) {
			deg[v]--;
			if (!deg[v]) {
				q.push(v);
			}
		}
	}
	if (list.size() != n) {
		puts("-1");
		return 0;
	}
	int res = 0;
	for (int u : list) {
		dp[a[u] - 'a'][u]++;
		for (int i = 0; i < 26; i++) {
			res = max(res, dp[i][u]);
		}
		for (int v : adj[u]) {
			for (int i = 0; i < 26; i++) {
				dp[i][v] = max(dp[i][v], dp[i][u]);
			}
		}
	}
	cout << res << endl;
	return 0;
}