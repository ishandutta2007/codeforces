#include <bits/stdc++.h>

using namespace std;

const int N = 1000010, MOD = 1000000007;

inline int add(int u, int v) {
  u += v;
  if (u >= MOD) {
    u -= MOD;
  }
  return u;
}

inline int sub(int u, int v) {
  u -= v;
  if (u < 0) {
    u += MOD;
  }
  return u;
}

int n, k, m;
char a[N + N];
int dp[N + N];
int last[30];

int main() {
  scanf("%d %d", &n, &k);
  scanf("%s", a + 1);
  m = strlen(a + 1);
  dp[0] = 1;
  n += m;
  for (int i = 1; i <= m ;i++) {
    int foo = 0;
    if (last[a[i] - 'a'] == 0) {
      foo = dp[i - 1];
    } else {
      foo = sub(dp[i - 1], dp[last[a[i] - 'a'] - 1]);
    }
    last[a[i] - 'a'] = i;
    dp[i] = add(dp[i - 1], foo);
  }
  for (int i = m + 1; i <= n; i++) {
    int minval = 1e9, pos = 0;
    for (int j = 0; j < k; j++) {
      if (last[j] < minval) {
        minval = last[j];
        pos = j;
      }
    }
    int foo = 0;
    if (minval == 0) {
      foo = dp[i - 1];
    } else {
      foo = sub(dp[i - 1], dp[minval - 1]);
    }
    last[pos] = i;
    dp[i] = add(dp[i - 1], foo);
//    a[i] = pos + 'a';
  }
//  cout << (a + 1) << endl;
  cout << dp[n] << endl;
  return 0;
}