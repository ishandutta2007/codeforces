#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N;
vector<int> adj[MAXN];
int ans[MAXN];
int dp[MAXN];
int score = 0;

void Dfs(int u, int p) {
  for (auto v : adj[u]) if (v != p) {
    Dfs(v, u);
    if (ans[v] == 0 && ans[u] == 0) {
      ans[u] = v;
      ans[v] = u;
      score += 2;
    } else if (ans[v] == 0) {
      ans[v] = ans[u];
      ans[u] = v;
      score += 2;
    }
  }

  if (ans[u] == 0 && p == 0) {
    int ch = ans[adj[u][0]];
    ans[u] = ch;
    ans[adj[u][0]] = u;
    score += 2;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N;
  for (int i = 1; i < N; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  Dfs(1, 0);
  
  cout << score << "\n";
  for (int i = 1; i <= N; i++) {
    assert(ans[i] != i);
    cout << ans[i] << " ";
  }
  cout << "\n";
  return 0;
}