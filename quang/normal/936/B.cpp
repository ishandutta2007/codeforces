#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
vector<int> adj[N];
int s;
int dp[2][N];
int deg[N];
queue<pair<int, int> > q;

int main() {
	memset(dp, -1, sizeof dp);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int c;
		scanf("%d", &c);
		for (int j = 1; j <= c; j++) {
			int u;
			scanf("%d", &u);
			adj[u].push_back(i);
		}
		deg[i] = c * 2;
		if (!c) {
			dp[0][i] = i;
			dp[1][i] = 0;
			q.push(make_pair(0, i));
			q.push(make_pair(1, i));
		}
	}	
	while (!q.empty()) {
		int u, id;
		tie(id, u) = q.front();
		q.pop();
		if (dp[id][u] == -1) dp[id][u] = 0;
		for (int v : adj[u]) {
			if (dp[id ^ 1][v] == -1 && dp[id][u] > 0) {
				dp[id ^ 1][v] = u;
				q.push(make_pair(id ^ 1, v));
			}
			deg[v]--;
			if (deg[v] == 0) {
				if (dp[0][v] == -1) {
					dp[0][v] = 0;
					q.push(make_pair(0, v));
				}
				if (dp[1][v] == -1) {
					dp[1][v] = 0;
					q.push(make_pair(1, v));
				}
			}
		}
	}
	cin >> s;
	// for (int i = 1; i <= n; i++) {
	// 	cout << dp[0][i] << " " << dp[1][i] << endl;
	// }
	if (dp[1][s] == 0) {
		puts("Lose");
	} else if (dp[1][s] == -1) {
		puts("Draw");
	} else {
		puts("Win");
		int id = 1;
		while (1) {
			printf("%d ", s);
			if (s == dp[id][s]) {
				break;
			}
			s = dp[id][s];
			id ^= 1;
		}
	}
	return 0;
}