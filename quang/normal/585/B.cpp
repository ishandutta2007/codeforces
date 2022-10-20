#include <bits/stdc++.h>

using namespace std;

const int N = 200;

int n, k;
char s[3][N];
int dp[3][N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &k);
    for (int i = 0; i <= n + 2; i++) {
        dp[0][i] = dp[1][i] = dp[2][i] = 0;
    }
    scanf("%s", s[0]);
    scanf("%s", s[1]);
    scanf("%s", s[2]);
    s[0][n] = s[1][n] = s[2][n] = '.';
    s[0][n + 1] = s[1][n + 1] = s[2][n + 1] = '.';
    s[0][n + 2] = s[1][n + 2] = s[2][n + 2] = '.';
    if (s[0][0] == 's') dp[0][0] = 1, s[0][0] = '.';
    if (s[1][0] == 's') dp[1][0] = 1,s[1][0] = '.';
    if (s[2][0] == 's') dp[2][0] = 1,s[2][0] = '.';
    int res = 0;
    for (int i = 3; i <= n + 2; i++) {
      for (int j = 0; j < 3; j++) {
        if (s[j][i] != '.') {
            continue;
        }
        if (j) {
          if (s[j][i - 1] == '.' && s[j][i - 2] == '.' && s[j - 1][i - 2] == '.') {
            dp[j][i] |= dp[j - 1][i - 3];
          }
        }
        if (j < 2) {
          if (s[j][i - 1] == '.' && s[j][i - 2] == '.' && s[j + 1][i - 2] == '.') {
            dp[j][i] |= dp[j + 1][i - 3];
          }
        }
        if (s[j][i - 1] == '.' && s[j][i - 2] == '.'&& s[j][i - 3] == '.') {
          dp[j][i] |= dp[j][i - 3];
        }
        if (i >= n) {
            res |= dp[j][i];
        }
      }
    }
    if(res) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
  }
  return 0;
}