#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
const int MOD = 1000000007;

int n, m;
int s[N];

int pre[N][N];
int suf[N][N];

int f[N], h[N];
bool cow[N][N];

void init() {
  for (int i = 1; i <= n; ++i) {
    ++pre[i][s[i]];
    for (int j = 1; j <= n; ++j) {
      pre[i][j] += pre[i-1][j];
    }
  }

  for (int i = n; i > 0; --i) {
    ++suf[i][s[i]];
    for (int j = n; j >= 1; --j) {
      suf[i][j] += suf[i+1][j];
    }
  }
}

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &s[i]);
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d %d", &f[i], &h[i]);
    cow[f[i]][h[i]] = true;
  }

  init();

  pair<int, int> ans = {0, 0};
  for (int i = 0; i <= n; ++i) {
    if (i > 0 && !cow[s[i]][pre[i][s[i]]]) continue;

    vector<int> fav1(n+1, 0), fav2(n+1, 0), fav3(n+1, 0);

    int cnt = 0;
    int sum = 1;
    for (int j = 1; j <= m; ++j) {
      if (f[j] == s[i] && h[j] == pre[i][s[i]]) {
        ++cnt;
        continue;
      }

      int can = 0;
      if (pre[i][f[j]] >= h[j] && f[j] != s[i]) can |= 1;
      if (suf[i+1][f[j]] >= h[j]) can |= 2;

      if (can > 0) {
        if (can == 1) ++fav1[f[j]];
        if (can == 2) ++fav2[f[j]];
        if (can == 3) ++fav3[f[j]];
      }
    }

    for (int j = 1; j <= n; ++j) {
      if (fav1[j] == 0 && fav2[j] == 0 && fav3[j] == 0) continue;
      if (fav1[j] > 0 && fav2[j] > 0 || fav1[j] > 0 && fav3[j] > 0 || fav2[j] > 0 && fav3[j] > 0 || fav3[j] >= 2) {
        cnt += 2;
        sum = (1LL * fav1[j] * fav2[j] + 1LL * fav1[j] * fav3[j] + 1LL * fav2[j] * fav3[j] + 1LL * fav3[j] * (fav3[j] - 1)) % MOD * sum % MOD;
      } else {
        cnt += 1;
        sum = (fav1[j] + fav2[j] + fav3[j] * 2LL) % MOD * sum % MOD;
      }
    }

    // cerr << i << " " << cnt << " " << sum << endl;

    if (cnt > ans.first) {
      ans.first = cnt;
      ans.second = sum;
    } else if (cnt == ans.first) {
      ans.second = (ans.second + sum) % MOD;
    }
  }

  printf("%d %d\n", ans.first, ans.second);
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