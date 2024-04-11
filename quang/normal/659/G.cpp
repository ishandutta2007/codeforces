#include <bits/stdc++.h>

using namespace std;

const int N = 1000010, MOD = 1000000007;

int n;
int h[N];
pair<int, int> dp[2];

inline int add(int u, int v) {
  u += v;
  if (u >= MOD) {
    u -= MOD;
  }
  return u;
}

inline int mul(int u, int v) {
  return (long long) u * v % MOD;
}

int get(int u) {
  if (u <= dp[0].first) {
    return mul(u, dp[0].second);
  }
  u -= dp[0].first;
  return add(mul(dp[0].first, dp[0].second), mul(u, dp[1].second));
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", h + i);
    h[i]--;
  }
  dp[0] = dp[1] = make_pair(0, 0);
  int res = 0;
  for (int i = 1; i <= n; i++) {
    if (h[i] == 0) {
      dp[0] = dp[1] = make_pair(0, 0);
      continue;
    }
    pair<int, int> now[2];
    if (h[i] > h[i - 1]) {
      now[0] = make_pair(h[i - 1], add(mul(dp[0].first, dp[0].second), mul(dp[1].first, dp[1].second)));
      now[1] = make_pair(h[i] - h[i - 1], 1);
      now[0].second = add(now[0].second, 1);
    } else {
      int foo = get(h[i]);
      now[0] = make_pair(h[i], foo);
      now[0].second = add(now[0].second, 1);
      now[1] = make_pair(0, 0);
    }
    res = add(res, mul(now[0].first, now[0].second));
    res = add(res, mul(now[1].first, now[1].second));
    dp[0] = now[0];
    dp[1] = now[1];
  }
  cout << res << endl;
  return 0;
}