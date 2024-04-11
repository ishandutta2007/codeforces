#include <bits/stdc++.h>
using namespace std;

const int N = 2002;
const int MOD = 1000000007;

int n, h;
int a[N];

int dp[N][N];
int f(int x, int y) {
  if (x == n) return y == 0;
  if (~dp[x][y]) return dp[x][y];
  
  long long ret = 0;
  
  // Do nothing
  if (a[x] + y == h) {
    ret += f(x+1, y);
  }
  
  // Start Interval
  if (a[x] + y+1 == h) {
    ret += f(x+1, y+1);
  }
  
  // End Interval
  if (y > 0 && a[x] + y == h) {
    ret += 1LL * y * f(x+1, y-1);
  }
  
  // Start and End immediately
  if (a[x] + y+1 == h) {
    ret += f(x+1, y);
  }
  
  // End and Start
  if (a[x] + y+1 == h) {
    ret += 1LL * y * f(x+1, y);
  }
  
  return dp[x][y] = ret % MOD;
}

int main() {
  scanf("%d %d", &n, &h);
  for (int i=0; i<n; i++) {
    scanf("%d", a + i);
  }
  
  memset(dp, -1, sizeof dp);
  printf("%d\n", f(0, 0));
  
  return 0;
}