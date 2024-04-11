#include <bits/stdc++.h>

#define Task "B"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 500, inf = (1 << 30);

int n;
int l[N], c[N];
vector <int> dp[N], x;

int Get(int val) {
  return lower_bound(x.begin(), x.end(), val) - x.begin();
}

int main() {
  //fi, fo;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", l + i);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", c + i);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 1; 1ll * j * j <= 1ll * l[i]; j++) {
      if (l[i] % j == 0) {
        x.push_back(j);
        if (j * j != l[i]) {
          x.push_back(l[i] / j);
        }
      }
    }
  }
  sort(x.begin(), x.end());
  x.resize(unique(x.begin(), x.end()) - x.begin());
  for (int i = 0; i <= n + 1; i++) {
    dp[i].resize(x.size() + 10);
    for (int j = 0; j < dp[i].size(); j++) {
      dp[i][j] = inf;
    }
    if (i < n) {
      dp[i][Get(l[i])] = c[i];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < x.size(); j++) {
      if (dp[i][j] == inf) {
        continue;
      }
      dp[i + 1][j] = min (dp[i + 1][j], dp[i][j]);
      int val = __gcd(x[j], l[i]);
      val = Get(val);
      dp[i + 1][val] = min (dp[i + 1][val], dp[i][j] + c[i]);
    }
  }
  cout << (dp[n][0] == inf ? -1 : dp[n][0]);
  return 0;
}