#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, x, y;
vector <int> a[N];
int dp[N][2];

void dfs(int u, int p) {
  dp[u][0] = dp[u][1] = 0;
  pair<int, int> foo = make_pair(0, 0);
  int sum = 0;
  for (int v : a[u]) {
    if (v == p) {
      continue;
    }
    dfs(v, u);
    sum += max(dp[v][0], dp[v][1]);
    int bar = dp[v][1] + 1 - max(dp[v][0], dp[v][1]);
    if (bar > foo.first) {
      swap(bar, foo.first);
    }
    if (bar > foo.second) {
      swap(bar, foo.second);
    }
  }
  dp[u][1] = sum + foo.first;
  dp[u][0] = sum + foo.second + foo.first;
}

int main() {
  scanf("%d %d %d", &n, &x, &y);
  for (int i =1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    a[u].push_back(v);
    a[v].push_back(u);
  }
  if (x >= y) {
    int f = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i].size() == n - 1) {
        f = 1;
      }
    }
    if (!f) {
      cout << 1ll * y * (n - 1) << endl;
    } else {
      cout << 1ll * y * (n - 2) + x << endl;
    }
    return 0;
  }
  dfs(1, 0);
  int res = max(dp[1][0], dp[1][1]);
  cout << (1ll * res * x + 1ll * (n - res - 1) * y);
  return 0;
}