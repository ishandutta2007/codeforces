#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int p, f;
    cin >> p >> f;
    int cnt1, cnt2;
    cin >> cnt1 >> cnt2;
    int w1, w2;
    cin >> w1 >> w2;
    
    vector<int> cost;
    for (int i = 0; i < cnt1; i++) {
      cost.emplace_back(w1);
    }
    for (int i = 0; i < cnt2; i++) {
      cost.emplace_back(w2);
    }
    sort(begin(cost), end(cost));

    auto Can = [&](int x) -> bool {
      int one = 0, two = 0;
      for (int i = 0; i < x; i++) {
        if (w1 == cost[i]) {
          one += 1;
        } else {
          two += 1;
        }
      }
      for (int i = 0; i <= one; i++) {
        if (1ll * i * w1 <= p) {
          int left = p - i * w1;
          int pick = left / w2;
          if (1ll * (one - i) * w1 + 1ll * max(0, two - pick) * w2 <= f) {
            return true;
          }
        }
      }
      return false;
    };
    int lo = 0, hi = cost.size();
    while (lo < hi) {
      int md = (lo + hi + 1) / 2;
      if (Can(md)) {
        lo = md;
      } else {
        hi = md - 1;
      }
    }
    cout << lo << "\n";
  }
  return 0;
}