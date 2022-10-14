#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int N, M;
int adj[105][105];
int dp[105][105][30][2];

int Dfs(int a, int b, int c, int t) {
  int &res = dp[a][b][c][t];
  if (res != -1) {
    return res;
  }
  res = 0;
  if (t & 1) {
    for (auto v = 1; v <= N; v++) if (adj[a][v] >= c) {
      res |= !Dfs(v, b, adj[a][v], t ^ 1);
    }
  } else {
    for (auto v = 1; v <= N; v++) if (adj[b][v] >= c) {
      res |= !Dfs(a, v, adj[b][v], t ^ 1);
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  memset(dp, -1, sizeof(dp));

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int u, v;
    char c;
    cin >> u >> v >> c;
    adj[u][v] = c - 'a' + 1;
  }  

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      Dfs(i, j, 1, 1);
      if (dp[i][j][1][1]) {
        cout << 'A';
      } else {
        cout << 'B';
      }
    }
    cout << "\n";
  }
  return 0;
}