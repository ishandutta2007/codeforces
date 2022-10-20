#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, q, a, b;
int v[N], c[N];
long long dp[N];
pair<long long, int> tmp[2];

int main() {
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", v + i);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", c + i);
  }
  while (q--) {
    tmp[0] = make_pair(-(1ll << 60), 0);
    tmp[1] = make_pair(-(1ll << 60), 0);
    scanf("%d %d", &a, &b);
    for (int i = 1; i <= n; i++) {
      dp[i] = -(1ll << 60);
    }
    long long res = 0;
    for (int i = 1; i <= n; i++) {
      long long now = 1ll * v[i] * b;
      now = max(now, dp[c[i]] + 1ll * v[i] * a);
      int pos = 0;
      if (tmp[pos].second == c[i]) {
        pos = 1;
      }
      now = max(now, tmp[pos].first + 1ll * v[i] * b);
      dp[c[i]] = max(dp[c[i]], now);
      res = max(res, now);
      pair<long long, int> foo = make_pair(now, c[i]);
      for (int i = 0; i <= 1; i++) {
        if (tmp[i].second == foo.second) {
          tmp[i].first = max(tmp[i].first, foo.first);
          break;
        } else {
          if (tmp[i] < foo) {
            swap(tmp[i], foo);
          }
        }
      }
    }
    printf("%I64d\n", res);
  }
  return 0;
}