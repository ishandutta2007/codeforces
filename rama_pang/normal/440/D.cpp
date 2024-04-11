#include <bits/stdc++.h>
using namespace std;

const int MAXN = 405;

int N, K;
vector<int> adj[MAXN];
int Edge[MAXN][MAXN];
int DP[MAXN][MAXN]; // DP[vertex][size]
int prevState[MAXN][MAXN]; // previous DP state for backtracking
int par[MAXN];

void dfs(int n, int p) {
  DP[n][0] = 0;
  DP[n][1] = adj[n].size();
  par[n] = p;
  for (int k = 2; k <= K; k++) {
    DP[n][k] = 1e6;
  }

  for (auto &i : adj[n]) if (i != p) {
    dfs(i, n);
    for (int k = K; k >= 2; k--) {
      for (int j = 1; j < k; j++) {
        if (DP[n][k] > DP[n][j] + DP[i][k - j] - 2) {
          DP[n][k] = DP[n][j] + DP[i][k - j] - 2;
          prevState[i][k] = k - j; // prevState[n][k] has potential to clash with same child, so we just need to remember what child can contribute to the answer
        }
      }
    }
  }
}

bool inGroup[MAXN];

void trace(int n, int p, int num) {
  inGroup[n] = true;
  for (auto it = adj[n].rbegin(); it != adj[n].rend(); it++) {
    int i = *it;
    if (i != p) {
      if (prevState[i][num] != 0) {
        trace(i, n, prevState[i][num]);
        num -= prevState[i][num];
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N >> K;
  for (int i = 1; i < N; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
    Edge[u][v] = Edge[v][u] = i;
  }

  dfs(1, 0);
  int ans = N;
  int root = 1;
  for (int i = 1; i <= N; i++) {
    if (ans > DP[i][K]) {
      ans = DP[i][K];
      root = i;
    }
  }
  trace(root, par[root], K);
  cout << ans << "\n";
  for (int i = 1; i <= N; i++) {
    if (inGroup[i]) {
      for (auto &j : adj[i]) {
        if (!inGroup[j]) {
          cout << Edge[i][j] << " ";
        }
      }
    }
  }
  cout << "\n";
  return 0;
}