#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int n, m, x;

int ***dp;
int f(int x, int interval, int open) {
  if (interval < 0) return 0;
  if (x == m) return interval == 0 && open == 0;
  if (~dp[x][interval][open]) return dp[x][interval][open];
  
  long long ret = 0;
  
  // Start interval
  ret += f(x+1, interval-1, open+1);
  
  // Start and end immediately
  if (open == 0) ret += f(x+1, interval-1, open);
  
  // End and start immediately
  if (open > 0) ret += f(x+1, interval-1, open);
  
  if (x != ::x) {
    // End interval
    if (open > 0) ret += f(x+1, interval, open-1);
    
    // Do nothing
    ret += f(x+1, interval, open);
  }
  
  return dp[x][interval][open] = ret % MOD;
}

int main() {
  scanf("%d %d %d", &n, &m, &x);
  --x;
  if (n > m) return 0 * printf("0\n");

  dp = (int***) malloc(sizeof(int**) * m);
  for (int i=0; i<m; i++) {
    dp[i] = (int**) malloc(sizeof(int*) * (n+1));
    for (int j=0; j<=n; j++) {
      dp[i][j] = (int*) malloc(sizeof(int) * (n+1));
      for (int k=0; k<=n; k++) {
        dp[i][j][k] = -1;
      }
    }
  }
  
  int ans = f(0, n, 0);
  for (int i=1; i<=n; i++) ans = 1LL * ans * i % MOD;
  
  printf("%d\n", ans);
  
  return 0;
}