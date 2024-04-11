#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n;
vector<int> edges[N];
bool vis[N];

vector<pair<int, int>> removes;
int dfs(int u, int p) {
  // cerr << u << " " << p << endl;
  vis[u] = true;
  int deg = edges[u].size();
  vector<int> unremoved;
  for (int v : edges[u]) {
    if (v == p) continue;
    if (edges[v].size() > 2 && dfs(v, u)) {
      --deg;
    } else {
      unremoved.push_back(v);
    }
  }
  if (deg > 2) {
    if (p != u) {
      removes.emplace_back(u, p);
      --deg;
    }
    while (deg > 2) {
      // cerr << unremoved.back() + 1 << " " << u + 1 << endl;
      assert(unremoved.size() > 0);
      removes.emplace_back(unremoved.back(), u);
      unremoved.pop_back();
      --deg;
    }
    return 1;
  }
  return 0;
}

vector<pair<int, int>> es;
void findAdd() {
  for (int u = 0; u < n; ++u) {
    for (int j = 0; j < edges[u].size(); ++j) {
      int v = edges[u][j];
      if (binary_search(removes.begin(), removes.end(), make_pair(u, v)) ||
          binary_search(removes.begin(), removes.end(), make_pair(v, u))) {
        edges[u][j] = edges[u].back();
        edges[u].pop_back();
        --j;
      }
    }
  }

  vector<bool> vis(n);
  for (int i = 0; i < n; ++i) {
    if (vis[i]) continue;
    if (edges[i].size() == 2) continue;
    assert(edges[i].size() < 2);

    int u = i, v = i;
    while (!vis[v]) {
      vis[v] = true;
      for (int b : edges[v]) {
        if (!vis[b]) {
          v = b;
          break;
        }
      }
    }

    // cerr << u << " " << v << endl;
    es.emplace_back(u, v);
  }
  // cerr << endl;cf
}

int solve() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;

    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  for (int i = 0; i < n; ++i) {
    if (!vis[i] && edges[i].size() > 2) dfs(i, i);
  }

  // cerr << "OK" << endl;

  sort(removes.begin(), removes.end());

  findAdd();
  // cerr << "OK 2" << endl;

  printf("%d\n", (int) removes.size());
  for (int i = 0; i < removes.size(); ++i) {
    printf("%d %d %d %d\n", removes[i].first + 1, removes[i].second + 1, es[i].second + 1, es[i + 1].first + 1);
  }
  for (int i = 0; i < n; ++i) {
    edges[i].clear();
    vis[i] = false;
    es.clear();
    removes.clear();
  }
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}