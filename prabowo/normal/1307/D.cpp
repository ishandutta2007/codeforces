#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m, k;
int a[N];
vector<int> edges[N];

int dist0[N], dist1[N];

void bfs(int u, int dist[]) {
  for (int i = 0; i < n; ++i) dist[i] = -1;

  queue<int> q;
  q.push(u);
  dist[u] = 0;

  while (q.size()) {
    int u = q.front();
    q.pop();

    for (int v: edges[u]) {
      if (dist[v] != -1) continue;
      dist[v] = dist[u] + 1;
      q.push(v);
    }
  }

  // for (int i = 0; i < n; ++i) cerr << dist[i] << " "; cerr << endl;
}

int solve() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < k; ++i) {
    scanf("%d", &a[i]);
    --a[i];
  }
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;

    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  bfs(0, dist0);
  bfs(n-1, dist1);

  int shortest = dist0[n-1];

  vector<pair<int, int>> d0(k), d1(k);
  for (int i = 0; i < k; ++i) {
    d0[i] = {dist0[a[i]], a[i]};
    d1[i] = {dist1[a[i]], a[i]};
  }

  sort(d0.begin(), d0.end());
  sort(d1.begin(), d1.end());

  int ans = -1;

  int j = k-1;
  for (int i = 0; i < k; ++i) {
    while (j >= 0 && d1[j].first + d0[i].first + 1 > shortest) {
      if (d0[j].second != d1[i].second) ans = max(ans, min(shortest, min(d1[j].first + d0[i].first + 1, dist0[d1[j].second] + dist1[d0[i].second] + 1)));
      --j;
    }

    if (j >= 0) ans = max(ans, min(shortest, min(d1[j].first + d0[i].first + 1, dist0[d1[j].second] + dist1[d0[i].second] + 1)));
  }

  j = k-1;
  for (int i = 0; i < k; ++i) {
    while (j >= 0 && d0[j].first + d1[i].first + 1 > shortest) {
      if (d1[j].second != d0[i].second) ans = max(ans, min(shortest, min(d0[j].first + d1[i].first + 1, dist1[d0[j].second] + dist0[d1[i].second] + 1)));
      --j;
    }

    if (j >= 0) ans = max(ans, min(shortest, min(d0[j].first + d1[i].first + 1, dist1[d0[j].second] + dist0[d1[i].second] + 1)));
  }

  printf("%d\n", ans);

  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) {
    solve();
  }

  return 0;
}