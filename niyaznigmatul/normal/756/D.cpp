#include <bits/stdc++.h>

int const N = 5555;

int dp[2][N][N];

int pr[N];
int last[42];
int s[N];

int const MOD = 1000000007;

void add(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}

int main() {
  int n;
  scanf("%d", &n);
  int c = getchar();
  while (c <= 32) c = getchar();
  for (int i = 0; i < n; i++) {
    s[i] = c - 'a';
    c = getchar();
  }
  for (int i = 0; i < 26; i++) last[i] = -1;
  for (int i = 0; i < n; i++) {
    pr[i] = last[s[i]];
    last[s[i]] = i;
  }
  dp[0][0][0] = 1;
  for (int len = 0; len < n; len++) {
    for (int i = 0; i < n; i++) {
      for (int put = 0; put < 2; put++) {
        int &val = dp[put][len][i];
        if (put == 0 && pr[i] >= 0) {
          add(dp[0][len][i], MOD - dp[1][len][pr[i]]);
        }
        if (val == 0) continue;
        if (i + 1 < n) {
          add(dp[0][len][i + 1], val);
        }
        add(dp[1][len + 1][i], val);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < 26; i++) last[i] = -1;
  for (int i = n - 1; i >= 0; i--) {
    if (last[s[i]] >= 0) continue;
    last[s[i]] = i;
    add(ans, dp[1][n][i]);
  }
  printf("%d\n", ans);
}