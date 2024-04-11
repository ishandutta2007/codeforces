#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long ans = 0;
    for (int bit = 29; bit >= 0; bit--) {
      vector<int> b;
      int on = 0;
      for (int i = 0; i < (int) a.size(); i++) {
        if ((a[i] >> bit) & 1) {
          on += 1;
        } else {
          b.emplace_back(a[i]);
        }
      }
      ans += 1ll * on * (on - 1) / 2;
      a = b;
    }
    cout << ans << "\n";
  }
  return 0;
}