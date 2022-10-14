#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int TT = 1;
  cin >> TT;
  while (TT--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    int cnt = 0;
    for (int i = 1; i + 1 < n; i++) {
      if (a[i] < a[i - 1] && a[i] < a[i + 1]) cnt++;
      if (a[i] > a[i - 1] && a[i] > a[i + 1]) cnt++;
    }
    const auto Check = [&](int i) {
      if (i <= 0 || i + 1 >= n) return 0;
      if (a[i] < a[i - 1] && a[i] < a[i + 1]) return 1;
      if (a[i] > a[i - 1] && a[i] > a[i + 1]) return 1;
      return 0;
    };
    int ans = cnt;
    const auto Change = [&](int i, int x) {
      int cur = cnt;
      cur -= Check(i - 1);
      cur -= Check(i);
      cur -= Check(i + 1);
      
      int old = a[i];
      a[i] = x;

      cur += Check(i - 1);
      cur += Check(i);
      cur += Check(i + 1);

      a[i] = old;
      ans = min(ans, cur);
    };
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        Change(i, a[i - 1]);
      }
      if (i + 1 < n) {
        Change(i, a[i + 1]);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}