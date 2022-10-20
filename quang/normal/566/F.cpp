#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int res = 0;
int dp[N];
int n;
int a[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int u;
    cin >> u;
    a[u] = 1;
    dp[u] = 1;
  }
  for (int i = 1; i <= 1000000; i++) {
    if (!a[i]) {
      continue;
    }
    res = max(res, dp[i]);
    for (int j = i + i; j <= 1000000; j += i) {
      if (a[j]) {
        dp[j] = max(dp[j], dp[i] + 1);
      }
    }
  }
  cout << res << endl;
  return 0;
}