#include <bits/stdc++.h>
using namespace std;

const int N = 4004;

int n, a, b, c;

int dp[N];
int f(int x) {
  if (x < 0) return -10000;
  if (x == 0) return 0;
  if (~dp[x]) return dp[x];

  return dp[x] = 1 + max(f(x-a), max(f(x-b), f(x-c)));
}

int solve() {
  scanf("%d %d %d %d", &n, &a, &b, &c);
  memset(dp, -1, sizeof dp);
  printf("%d\n", f(n));
  return 0;
}


int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}