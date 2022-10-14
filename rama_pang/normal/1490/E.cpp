#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    const auto Check = [&](int st) {
      priority_queue<lint, vector<lint>, greater<lint>> pq;
      lint sum = st;
      for (int i = 0; i < n; i++) {
        if (a[i] == st) {
          st = -1;
        } else {
          pq.emplace(a[i]);
        }
      }
      while (!pq.empty()) {
        if (pq.top() > sum) {
          return false;
        }
        sum += pq.top();
        pq.pop();
      }
      return true;
    };
    auto b = a;
    sort(begin(b), end(b));
    int lo = 0, hi = n - 1;
    while (lo < hi) {
      int md = (lo + hi) / 2;
      if (Check(b[md])) {
        hi = md;
      } else {
        lo = md + 1;
      }
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (a[i] >= b[lo]) {
        ans.emplace_back(i);
      }
    }
    cout << ans.size() << '\n';
    for (auto i : ans) cout << i + 1 << ' ';
    cout << '\n';
  }
  return 0;
}