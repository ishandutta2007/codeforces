#include <bits/stdc++.h>
using namespace std;
 
const int N = 3005;
const int MOD = 1000000007;
const int INF = 1e9;

int n, m;
int a[N];

int deg[N];
vector<pair<int, int>> edges[N];
bool star[N];

bool used[N];
vector<int> tour;
vector<int> visEdge;
void dfs(int u) {
  for (int i = 0; i < edges[u].size(); ++i) {
    int v, idx;
    tie(v, idx) = edges[u][i];
    if (!used[idx]) {
      used[idx] = true;
      visEdge.push_back(idx);
      dfs(v);
    }
  }
  tour.push_back(u);
}

bool adj[N][N];

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;

    edges[u].emplace_back(v, i);
    edges[v].emplace_back(u, i);
    ++deg[u], ++deg[v];
    adj[u][v] = adj[v][u] = true;
  }

  int odd = 0;
  for (int i = 0; i < n; ++i) odd += (deg[i] & 1);

  for (int u = 0; u < n; ++u) {
    int deletedEdge = 0;
    for (int i = 0; i < edges[u].size(); ++i) {
      int v = edges[u][i].first;
      if (deg[v] & 1) {
        used[edges[u][i].second] = true;
        star[edges[u][i].second] = true;
        ++deletedEdge;
      }
    }

    auto checkForEulerTour = [&]() {
      if (odd - deletedEdge + ((int) edges[u].size() - deletedEdge & 1) - (edges[u].size() & 1) <= 2) {
      dfs(u);

      bool euler = true;
      for (int i = 1; i < tour.size(); ++i) {
        if (!adj[tour[i - 1]][tour[i]]) euler = false;
      }

      if (euler && visEdge.size() + deletedEdge == m) {
        vector<int> ans;
        for (int u : tour) ans.push_back(u);
        ans.push_back(-2);
        for (int j = 0; j < edges[u].size(); ++j) {
          if (star[edges[u][j].second] & 1) {
            ans.push_back(edges[u][j].first);
            ans.push_back(u);
          }
        }

        printf("%d\n", (int) ans.size());
        for (int u : ans) printf("%d ", u + 1);
        printf("\n");
        exit(0);
      }

      for (int idx : visEdge) used[idx] = false;
      tour.clear(); visEdge.clear();
    }
    };

    checkForEulerTour();
    for (int i = 0; i < edges[u].size(); ++i) {
      int v = edges[u][i].first;
      if (deg[v] & 1) {
        used[edges[u][i].second] = false;
        star[edges[u][i].second] = false;
        --deletedEdge;
        checkForEulerTour();
        used[edges[u][i].second] = true;
        star[edges[u][i].second] = true;
        ++deletedEdge;
      }
    }

    for (int i = 0; i < edges[u].size(); ++i) {
      int v = edges[u][i].first;
      if (deg[v] & 1) {
        used[edges[u][i].second] = false;
        star[edges[u][i].second] = false;
      }
    }
  }

  printf("0\n");
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}