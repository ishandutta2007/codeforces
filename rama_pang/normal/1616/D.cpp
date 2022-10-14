#include <bits/stdc++.h>
using namespace std;

using lint = long long;
#define int lint

void Main() {
  // (a[l] - x) + ... + (a[r] - x) >= 0
  // a1 - x + a2 - x >= 0
  // a2 - x + a3 - x >= 0
  // a1 - x + a2 - x + a3 - x >= 0
  // +-+
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int x;
  cin >> x;
  for (int i = 0; i < n; i++) {
    a[i] -= x;
  }
  int ans = 0;
  vector<int> cur;
  for (int i = 0; i < n; i++) {
    int j = i;
    cur.emplace_back(a[i]);
    while (j + 1 < n) {
      if (cur.size() >= 1 && end(cur)[-1] + a[j + 1] < 0) break;
      if (cur.size() >= 2 && end(cur)[-2] + end(cur)[-1] + a[j + 1] < 0) break;
      cur.emplace_back(a[j + 1]);
      j += 1;
    }
    if (j + 1 < n) {
      ans += 1;
    }
    i = j + 1;
    cur.clear();
  }
  ans = n - ans;
  cout << ans << '\n';
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}