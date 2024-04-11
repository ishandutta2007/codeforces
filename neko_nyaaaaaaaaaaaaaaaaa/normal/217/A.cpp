#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int>> adj(103);
vector<int> v(103);
int cc = 0;

void dfs(int now) {
      v[now] = 1;
      for (int i = 0; i < adj[now].size(); i++) {
            if (v[adj[now][i]]) continue;
            dfs(adj[now][i]);
      }
}

int main() {
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	vector<int> x(n+1), y(n+1);
	for (int i = 1; i <= n; i++) {
            cin >> x[i] >> y[i];
	}

	for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                  if (i == j) continue;

                  if (x[i] == x[j] || y[j] == y[i]) {
                        adj[j].push_back(i);
                  }
            }
	}

	for (int i = 1; i <= n; i++) {
            if (v[i]) continue;
            cc++;
            dfs(i);
	}

	cout << cc-1;

	return 0;
}