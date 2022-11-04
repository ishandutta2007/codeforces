#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int INF = 1e9;
const int N = 4004;
const int K = 808;

int n, k;
int u[N][N];

int prefix[N][N];
int cost[N][N];
int dp[K][N];

void calc(int i, int l, int r, int cur_l, int cur_r) {
  if (l > r) return;
  
  int m = (l + r) / 2;
  int best = cur_l;
  
  for (int j = cur_l; j <= cur_r; j++) {
    if (j < m && dp[i - 1][j] + cost[j][m - 1] < dp[i][m]) {
      best = j;
      dp[i][m] = dp[i - 1][j] + cost[j][m - 1];
    }
  }
  
  if (l != r) {
    calc(i, l, m - 1, cur_l, best);
    calc(i, m + 1, r, best, cur_r);
  }
}

int main() {
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  
  scanf("%d %d\n", &n, &k);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c = ' ';
      while (!('0' <= c && c <= '9')) c = getchar();
      u[i][j] = c - '0';
    }
  }
  
  for (int i = 0; i < n; i++) {
    prefix[i][0] = u[i][0];
    for (int j = 1; j < n; j++) {
      prefix[i][j] = prefix[i][j - 1] + u[i][j];
    }
  }
  
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      cost[i][j] = cost[i][j - 1] + prefix[j][j];
      if (i > 0) {
        cost[i][j] -= prefix[j][i - 1];
      }
    }
  }
  
  for (int i = 0; i <= k; i++) {
    fill(dp[i], dp[i] + n + 1, INF);
  }
  
  dp[0][0] = 0;
  
  for (int i = 1; i <= k; i++) {
    calc(i, 1, n, i - 1, n);
  }
  
  cout << dp[k][n] << "\n";
  
  return 0;
}