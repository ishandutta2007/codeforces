#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  for (auto &i : a) i--;
  long long ans = 0;
  vector<vector<int>> rgt(n, vector<int>(n));
  for (int c = 0; c < n; c++) {
    for (int d = c; d < n; d++) {
      rgt[c][a[d]] += 1;
    }
    for (int i = 1; i < n; i++) {
      rgt[c][i] += rgt[c][i - 1];
    }
  }
  for (int b = 0; b < n; b++) {
    vector<int> cnt(n);
    for (int i = 0; i < b; i++) {
      cnt[a[i]] += 1;
    }
    for (int i = 1; i < n; i++) {
      cnt[i] += cnt[i - 1];
    }
    for (int c = b + 1; c + 1 < n; c++) {
      int way = (a[b] > 0 ? rgt[c + 1][a[b] - 1] : 0);
      ans += 1ll * (a[c] > 0 ? cnt[a[c] - 1] : 0) * way;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}