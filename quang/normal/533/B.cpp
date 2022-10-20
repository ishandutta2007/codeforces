#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const long long MAX = (1ll << 60);

int n;
int e[N];
vector <int> a[N];
long long dp[2][N];
long long res;

void getmax(long long &u, long long v) {
  u = max(u, v);
}

void DFS(int u) {
  dp[0][u] = 0;
  dp[1][u] = -MAX;
  for (int i = 0; i < a[u].size(); i++) {
    int v = a[u][i];
    DFS(v);
    long long cur0 = -MAX, cur1 = -MAX;
    getmax(cur0, dp[0][u] + dp[0][v]);
    getmax(cur0, dp[1][u] + dp[1][v]);
    getmax(cur1, dp[1][u] + dp[0][v]);
    getmax(cur1, dp[0][u] + dp[1][v]);
    getmax(dp[0][u], dp[0][v]);
    getmax(dp[1][u], dp[1][v]);
    getmax(dp[0][u], cur0);
    getmax(dp[1][u], cur1);
  }
  getmax(res, dp[1][u]);
  getmax(res, dp[0][u] + e[u]);
  getmax(dp[1][u], dp[0][u] + e[u]);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int p;
    scanf("%d %d", &p, e + i);
    a[p].push_back(i);
  }
  res = -MAX;
  DFS(1);
  cout << res << endl;
  return 0;
}