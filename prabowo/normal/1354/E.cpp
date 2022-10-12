#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

int n, m;
int n1, n2, n3;

vector<int> edges[N];

void NO() {
  printf("NO\n");
  exit(0);
}

int col[N];
pair<vector<int>, vector<int>> bfs(int u) {
  queue<int> q;
  q.push(u);

  vector<int> vertices[2];
  vertices[0].push_back(u);
  col[u] = 0;

  while (q.size()) {
    int u = q.front();
    q.pop();

    for (int v: edges[u]) {
      if (col[v] != -1) {
        if (col[v] != 1 - col[u]) NO();
        continue;
      }

      vertices[col[v] = 1 - col[u]].push_back(v);
      q.push(v);
    }
  }

  return make_pair(vertices[0], vertices[1]);
}

vector<pair<vector<int>, vector<int>>> bis;

int dp[N][N];
int dfs(int x, int sum) {
  if (sum < 0) return 0;
  if (x == bis.size()) return sum == 0;
  if (~dp[x][sum]) return dp[x][sum];
  return dp[x][sum] = (dfs(x+1, sum - bis[x].first.size()) | dfs(x+1, sum - bis[x].second.size()));
}

int ans[N];

int solve() {
  scanf("%d %d", &n, &m);
  scanf("%d %d %d", &n1, &n2, &n3);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;

    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  for (int i = 0; i < n; ++i) col[i] = -1;


  for (int i = 0; i < n; ++i) {
    if (col[i] == -1) {
      bis.push_back(bfs(i));
    }
  }

  memset(dp, -1, sizeof dp);
  if (dfs(0, n2) == 0) NO();

  for (int i = 0; i < n; ++i) ans[i] = -1;

  for (int i = 0; i < bis.size(); ++i) {
    if (dfs(i+1, n2 - bis[i].first.size())) {
      n2 -= bis[i].first.size();
      for (int u: bis[i].first) ans[u] = 2;
    } else {
      n2 -= bis[i].second.size();
      for (int u: bis[i].second) ans[u] = 2;
    }
  }

  printf("YES\n");
  for (int i = 0; i < n; ++i) {
    if (ans[i] == -1) {
      if (n1 > 0) {
        --n1;
        printf("1");
      } else {
        --n3;
        printf("3");
      }
    } else {
      printf("2");
    }
  }
  printf("\n");
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) solve();  
  return 0;
}