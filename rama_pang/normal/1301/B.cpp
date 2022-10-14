#include <bits/stdc++.h>
using namespace std;

using doub = double;
using lint = long long;

#define alL(x) begin(x), end(x)
#define sz(x) (int) x.size()


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  
  
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), b;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    auto check = [&](int m) {
      int l = 0, r = 1e9;
      for (int i = 0; i < n; i++) {
        if (a[i] == -1) {
          continue;
        } else if ((i - 1 >= 0 && a[i - 1] == -1) || (i + 1 < n && a[i + 1] == -1)) {
          l = max(l, a[i] - m);
          r = min(r, a[i] + m);
        }
      }
      return pair<int, int>{l, r};
    };

    int l = 0, r = 1e9;
    int ans = -1, ansl = -1, ansr = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      pair<int, int> cur = check(mid);
      if (cur.first > cur.second) {
        l = mid + 1;
      } else {
        ansl = cur.first;
        ans = mid;
        r = mid - 1;
      }
    }
    
    for (int i = 0; i < n; i++) {
      if (a[i] == -1) a[i] = ansl;
    }
    for (int i = 0; i + 1 < n; i++) {
      ans = max(ans, abs(a[i + 1] - a[i]));
    }

    cout << ans << " " << ansl << "\n";
  }


}