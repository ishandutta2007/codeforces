#include <bits/stdc++.h>

using namespace std;

const int N = 5010;
const long long inf = (1ll << 60);

int n;
int s;
int l[N], r[N];
long long dp[2][N * 2];
int m, v[N * 2];

long long cost(int u, int v) {
  if (l[u] <= v && r[u] >= v) {
    return 0;
  }
  if (l[u] > v) {
    return l[u] - v;
  }
  return v - r[u];
}

int main() {
  //ios_base::sync_with_stdio(0);
  scanf("%d %d", &n, &s);
  v[++m] = s;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", l + i, r + i);
    v[++m] = l[i];
    v[++m] = r[i];
  }
  sort(v + 1, v + m + 1);
  m = unique(v + 1, v + m + 1) - v - 1;
  for (int i = 1; i <= m; i++) {
    dp[0][i] = inf;
  }
  int pos = lower_bound(v + 1, v + m + 1, s) - v;
  int cur = 0;
  dp[0][pos] = 0;
  for (int i = 1; i <= n; i++) {
    int next = cur ^ 1;
    for (int j = 1; j <= m; j++) {
      dp[next][j] = inf;
    }
    long long minval = inf;
    for (int j = 1; j <= m; j++) {
      minval = min(minval, dp[cur][j] - v[j]);
      dp[next][j] = min(dp[next][j], minval + cost(i, v[j]) + v[j]);
    }
    minval = inf;
    for (int j = m; j >= 1; j--) {
      minval = min(minval, dp[cur][j] + v[j]);
      dp[next][j] = min(dp[next][j], minval + cost(i, v[j]) - v[j]);
    }
    cur = next;
  }
  cout << *min_element(dp[cur] + 1, dp[cur] + m + 1) << endl;
  return 0;
}