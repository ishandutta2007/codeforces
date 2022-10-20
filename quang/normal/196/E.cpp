#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
typedef pair<int, int> pi;

int n, m, k, cnt;
vector <pi> a[N];
pair<pi, int> edge[N];
pair<long long, pi> newedge[N];
pair<long long, int> d[N];
bool used[N];
int par[N], ok[N];

int root(int u) {
  return par[u] ? par[u] = root(par[u]) : u;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    edge[i] = make_pair(pi(u, v), w);
    a[u].push_back(pi(v, w));
    a[v].push_back(pi(u, w));
  }
  for (int i = 1; i <= n; i++) {
    d[i] = make_pair(1ll << 60, 0);
  }
  priority_queue <pair<long long, int> > p;
  scanf("%d", &k);
  for (int i = 1; i <= k; i++) {
    int u;
    scanf("%d", &u);
    d[u] = make_pair(0, u);
    p.push(make_pair(0, u));
    ok[u] = 1;
  }
  while (!p.empty()) {
    int u = p.top().second;
    p.pop();
    if (used[u]) {
      continue;
    }
    used[u] = 1;
    for (int i = 0; i < a[u].size(); i++) {
      int v = a[u][i].first;
      int len = a[u][i].second;
      if (d[v].first > d[u].first + len) {
        d[v].first = d[u].first + len;
        d[v].second = d[u].second;
        p.push(make_pair(-d[v].first, v));
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    int u = edge[i].first.first;
    int v = edge[i].first.second;
    int rootu = d[u].second, rootv = d[v].second;
    if (rootu == rootv) {
      continue;
    }
    newedge[++cnt] = make_pair(d[u].first + d[v].first + edge[i].second, pi(rootu, rootv));
  }
  sort(newedge + 1, newedge + cnt + 1);
  long long res = 0;
  for (int i = 1; i <= cnt; i++) {
    int u = newedge[i].second.first;
    int v = newedge[i].second.second;
    long long len = newedge[i].first;
    int uu = root(u);
    int vv = root(v);
    if (uu == vv) {
      continue;
    }
    par[uu] = vv;
    res += len;
  }
  if (!ok[1]) {
    res += d[1].first;
  }
  cout << res << endl;
  return 0;
}