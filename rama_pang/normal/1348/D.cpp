#include <bits/stdc++.h>
using namespace std;
using lint = long long;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    lint n;
    cin >> n;
    lint cur = 1;
    vector<lint> a;
    while (n > 0) {
      a.emplace_back(cur);
      n -= cur;
      lint nxt = cur;
      if (n <= 2 * cur) {
        cur = n;
        continue;
      }
      lint lo = cur;
      lint hi = 2 * cur;
      while (lo < hi) {
        lint mid = (lo + hi + 1) / 2;

        if (n >= 2 * mid) {
          lo = mid;
        } else {
          hi = mid - 1;
        }
      }
      cur = lo;

      // for (lint x = cur + 1; x <= 2 * cur; x++) {
      //   if (n >= 2 * x || n == x) nxt = x;
      // }

      // cur = nxt;
    }

    cout << int(a.size()) - 1 << "\n";
    for (int i = 1; i < a.size(); i++) {
      cout << a[i] - a[i - 1] << " ";
    }
    cout << "\n";
  }
}