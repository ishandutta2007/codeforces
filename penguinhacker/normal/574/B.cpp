#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, sz[4000];
bool has[4000][4000];
vector<int> adj[4000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b, --a, --b;
		has[a][b] = has[b][a] = 1;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < n; ++i) sz[i] = adj[i].size();
	int ans = INT_MAX;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < adj[i].size(); ++j) {
			for (int k = j + 1; k < adj[i].size(); ++k) {
				int a = adj[i][j], b = adj[i][k];
				if (has[a][b]) {
					ans = min(ans, sz[i] + sz[a] + sz[b] - 6);
				}
			}
		}
	}
	cout << (ans < INT_MAX ? ans : -1);
	return 0;
}