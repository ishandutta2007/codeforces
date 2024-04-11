#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int h, c, t;
    cin >> h >> c >> t;
    vector<pair<double, lint>> ans;
    ans.emplace_back(abs(t - h), 1);
    ans.emplace_back(abs(t - 1.00 * (c + h) / 2), 2);
    lint lo = 1, hi = 1e8;
    
    auto Check = [&](lint x) {
      return abs(1.00 * ((x + 1) * h + x * c) / (2 * x + 1) - t);
    };

    while (lo < hi) {
      lint mid = (lo + hi) / 2;
      if (Check(mid) <= Check(mid + 1)) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    ans.emplace_back(abs(t - (1.00 * (lo + 1) * h + 1.00 * lo * c) / (2.00 * lo + 1)), 2 * lo + 1);
    sort(begin(ans), end(ans));
    cout << ans[0].second << "\n";
  }
}