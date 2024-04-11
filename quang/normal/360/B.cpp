#include <bits/stdc++.h>

using namespace std;

const int N = 2010;

int n, k;
int a[N];
int dp[N];

bool check(int x) {
  for (int i = 1; i <= n; i++) {
    dp[i] = 1;
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      if (abs(a[i] - a[j]) <= 1ll * x * (i - j)) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
  int maxval = *max_element(dp + 1, dp + n + 1);
  return maxval >= n - k;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int l = -1, r = 2000000010;
  while (r - l > 1) {
    int m = (1ll * l + r) >> 1;
    if (check(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << r << endl;
  return 0;
}