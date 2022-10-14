#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> lft, rgt, any;
  for (int i = 1; i <= n; i++) {
    if (i < a) {
      rgt.emplace_back(i);
    } else if (i > b) {
      lft.emplace_back(i);
    } else {
      if (i == a) {
        lft.emplace_back(i);
      } else if (i == b) {
        rgt.emplace_back(i);
      } else {
        any.emplace_back(i);
      }
    }
  }
  while (!any.empty()) {
    if (lft.size() < rgt.size()) {
      lft.emplace_back(any.back());
    } else {
      rgt.emplace_back(any.back());
    }
    any.pop_back();
  }
  if (lft.size() == rgt.size() && *min_element(begin(lft), end(lft)) == a && *max_element(begin(rgt), end(rgt)) == b) {
    for (auto x : lft) cout << x << ' ';
    for (auto x : rgt) cout << x << ' ';
    cout << '\n';
  } else {
    cout << "-1\n";
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }  
}