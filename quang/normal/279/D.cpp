#include <bits/stdc++.h>

using namespace std;

int n;
int dp[1 << 23];
int a[30];

int get(int mask, int u) {
  if (dp[mask]) {
    return dp[mask];
  }
  if (u == 0) {
    return dp[mask] = 1;
  }
  int cnt = __builtin_popcount(mask);
  int best = n + 1;
  for (int i = 0; i < u; i++) {
    for (int j = 0; j <= i; j++) {
      if (a[u] == a[i] + a[j]) {
        int next = mask & (~(1 << u)) | (1 << (u - 1)) | (1 << i) | (1 << j);
        best = min(best, max(get(next, u - 1), cnt));
      }
    }
  }
  return dp[mask] = best;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int res =  get(1 << (n - 1), n - 1);
  if (res > n) {
    cout << -1;
  } else {
    cout << res;
  }
  return 0;
}