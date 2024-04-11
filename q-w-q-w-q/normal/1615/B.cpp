#include <cstdio>
#include <iostream>

using namespace std;

int s[200005][20];

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  for (int i = 1; i <= 200000; i++)
    for (int j = 0; j < 18; j++)
      s[i][j] = s[i - 1][j] + (i >> j & 1);

  int t;
  cin >> t;
  while (t--) {
    int l, r, ans = 1 << 30;
    cin >> l >> r;

    for (int i = 0; i < 18; i++)
      ans = min(ans, r - l + 1 - (s[r][i] - s[l - 1][i]));

    cout << ans << '\n';
  }
}