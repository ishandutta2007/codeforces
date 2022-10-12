#include <bits/stdc++.h>
using namespace std;
 
const int kMaxN = 200005;
const int kMaxK = 25;
const int kMaxA = 10000005;

int n, m, k;

bool prime[kMaxA];
int p[kMaxA];

void init() {
  memset(prime, true, sizeof prime);
  for (int i = 0; i < kMaxA; ++i) p[i] = 1;
  for (int i = 2; i < kMaxA; ++i) {
    if (!prime[i]) continue;
    for (int j = i; j < kMaxA; j += i) {
      prime[j] = false;
      int num = j, e = 0;
      do {
        num /= i; e ^= 1;
      } while (num % i == 0);
      if (e) p[j] *= i;
    }
  }
}

int h[kMaxN];

int dp[kMaxN][kMaxK];

int lft[kMaxK];
int cnt[kMaxK][kMaxN];
int out[kMaxK], lst[kMaxK];

int solve() {
  scanf("%d %d", &n, &k);
  k = min(k, n);
  m = 1;
  vector<int> comp;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &h[i]);
    comp.push_back(h[i] = p[h[i]]);
  }
  if (n == k) return 0 * printf("1\n");

  sort(comp.begin(), comp.end());
  comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
  for (int i = 1; i <= n; ++i) h[i] = lower_bound(comp.begin(), comp.end(), h[i]) - comp.begin();

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= k; ++j) {
      cnt[j][i] = 0;
      out[j] = lst[j] = lft[j] = 0;
      dp[i][j] = 0;
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= k; ++j) {
      if (++cnt[j][h[i]] > m) ++out[j];
      while (out[j] > j) if (cnt[j][h[++lft[j]]]-- > m) --out[j];
    }

    for (int j = k; j >= 0; --j) {
      if (dp[lft[lst[j]]][j - lst[j]] + 1 == dp[i-1][j]) {
        dp[i][j] = dp[i-1][j];
      } else if (j > 0 && dp[lft[lst[j-1] + 1]][j - lst[j-1] - 1] + 1 == dp[i-1][j]) {
        dp[i][j] = dp[i-1][j];
        lst[j] = lst[j-1] + 1;
      } else {
        dp[i][j] = dp[i-1][j] + 1;
        lst[j] = 0;
      }
    }
  }

  printf("%d\n", dp[n][k]);
  return 0;
}

int main() {
  init();
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}