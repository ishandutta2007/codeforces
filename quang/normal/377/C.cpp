#include <bits/stdc++.h>

using namespace std;

int n, m;
int s[110], b[110], cnt[1 << 20], dp[1 << 20];
char a[110];

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    char x;
    int y;
    cin >> x >> y;
    a[m - i + 1] = x;
    b[m - i + 1] = y;
  }
  sort(s, s + n, greater<int> ());
  cnt[0] = dp[0] = 0;
  for (int mask = 1; mask < (1 << m); mask++) {
    cnt[mask] = cnt[mask - (mask & -mask)] + 1;
    if (b[cnt[mask]] == 1) {
      dp[mask] = -1000000000;
      for (int i = 0; i < m; i++) {
        if (mask & (1 << i)) {
          int foo = dp[mask ^ (1 << i)];
          if (a[cnt[mask]] == 'p') {
            foo += s[i];
          }
          dp[mask] = max(dp[mask], foo);
        }
      }
    } else {
      dp[mask] = 1000000000;
      for (int i = 0; i < m; i++) {
        if (mask & (1 << i)) {
          int foo = dp[mask ^ (1 << i)];
          if (a[cnt[mask]] == 'p') {
            foo -= s[i];
          }
          dp[mask] = min(dp[mask], foo);
        }
      }
    }
  }
  cout << dp[(1 << m) - 1];
  return 0;
}