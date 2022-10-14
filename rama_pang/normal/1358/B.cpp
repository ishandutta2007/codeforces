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
    sort(begin(a), end(a));
    
    auto Check = [&](int x) {
      return a[x] <= x + 1;
    };

    int ans = 1;
    for (int i = 0; i < n; i++) {
      if (Check(i)) {
        ans = max(ans, 1 + i + 1);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}