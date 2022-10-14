#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) {
      cin >> i;
    }
    auto Check = [&](int x) {
      deque<int> b;
      vector<int> res;
      for (int i = x; i < n; i++) {
        b.emplace_back(a[i]);
      }
      while (!b.empty()) {
        if (b.front() < b.back()) {
          res.emplace_back(b.front());
          b.pop_front();
        } else {
          res.emplace_back(b.back());
          b.pop_back();
        }
      }
      return is_sorted(begin(res), end(res));
    };
    int lo = 0, hi = n;
    while (lo < hi) {
      int md = (lo + hi) / 2;
      if (Check(md)) {
        hi = md;
      } else {
        lo = md + 1;
      }
    }
    cout << lo << "\n";
  }  
  return 0;
}