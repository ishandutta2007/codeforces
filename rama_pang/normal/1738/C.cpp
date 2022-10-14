#include <bits/stdc++.h>
using namespace std;

using lint = long long;

int dp[101][101][2][2];

void Main() {
  int n;
  cin >> n;
  int cnt0 = 0, cnt1 = 0;
  while (n--) {
    int x;
    cin >> x;
    if (x % 2 == 0) cnt0++;
    else cnt1++;
  }  
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i <= cnt0; i++) {
    for (int j = 0; j <= cnt1; j++) {
      for (int t = 0; t < 2; t++) {
        for (int s = 0; s < 2; s++) {
          if (i == 0 && j == 0) {
            if (s == 1) dp[i][j][t][s] = t == 0 ? 0 : 1;
            else dp[i][j][t][s] = t == 0 ? 1 : 0;
            continue;
          }
          if (t == 0) {
            // Alice
            int x = 0;
            if (i > 0) x |= !dp[i - 1][j][1 - t][s];
            if (j > 0) x |= !dp[i][j - 1][1 - t][1 - s];
            dp[i][j][t][s] = x;
          } else {
            int x = 0;
            if (i > 0) x |= !dp[i - 1][j][1 - t][s];
            if (j > 0) x |= !dp[i][j - 1][1 - t][s];
            dp[i][j][t][s] = x;
          }
        }
      }
    }
  }
  if (dp[cnt0][cnt1][0][0]) {
    cout << "Alice\n";
  } else {
    cout << "Bob\n";
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
}