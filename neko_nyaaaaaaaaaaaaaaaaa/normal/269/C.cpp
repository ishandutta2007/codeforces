#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
vector<pair<int, int>> edge;
vector<pair<int, int>> adj[200001];
vector<int> sum(200001);
vector<int> finished(200001);
map<pair<int, int>, int> ans;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            edge.push_back({x, y});
            adj[x].push_back({y, z});
            adj[y].push_back({x, z});
            sum[x] += z;
            sum[y] += z;
	}
	for (int i = 1; i < n; i++) sum[i] /= 2;

      sum[1] = 0; finished[1] = 1;
      queue<int> q;
      q.push(1);
      while (q.size()) {
            int now = q.front(); q.pop();

            for (auto u: adj[now]) {
                  int x = u.first, w = u.second;
                  if (finished[x]) continue;

                  sum[x] -= w;
                  ans[{now, x}] = 0;
                  ans[{x, now}] = 1;

                  if (sum[x] == 0) {
                        q.push(x);
                        finished[x] = 1;
                  }
            }
      }

      for (auto u: edge) cout << ans[u] << '\n';

	return 0;
}