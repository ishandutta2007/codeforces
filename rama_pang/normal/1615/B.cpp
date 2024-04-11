#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 5;
int cnt[MAX][20];

void Main() {
  int l, r;
  cin >> l >> r;
  int ans = 1e9;
  for (int i = 0; i < 20; i++) {
    ans = min(ans, cnt[r][i] - cnt[l - 1][i]);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < 20; j++) {
      if (i) cnt[i][j] = cnt[i - 1][j];
      if ((i >> j) & 1) {

      } else {
        cnt[i][j]++;
      }
    }
  }

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}