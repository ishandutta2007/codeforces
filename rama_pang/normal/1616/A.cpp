#include <bits/stdc++.h>
using namespace std;

using lint = long long;
#define int lint

void Main() {
  int n;
  cin >> n;
  vector<int> cnt(200);
  while (n--) {
    int x;
    cin >> x;
    cnt[abs(x)]++;
  }
  int ans = 0;
  for (int i = 0; i < 200; i++) {
    if (i == 0) {
      ans += min(1ll, cnt[i]);
    } else {
      ans += min(2ll, cnt[i]);
    }
  }
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