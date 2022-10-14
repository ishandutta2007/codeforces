#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  vector<array<int, 3>> all;
  for (int i = 0; i < n; i++) {
    all.push_back({a[i], b[i], i});
    all.push_back({b[i], a[i], i});
  }
  sort(begin(all), end(all));
  vector<int> ans(n, -1);
  set<pair<int, int>> s;
  for (int i = 0; i < (int) all.size(); i++) {
    int j = i;
    while (j + 1 < (int) all.size() && all[j + 1][0] == all[i][0]) {
      j += 1;
    }
    for (int k = i; k <= j; k++) {
      auto it = s.lower_bound({all[k][1], -1});
      if (it != begin(s)) {
        assert(prev(it)->first < all[k][1]);
        assert(prev(it)->second != all[k][2]);
        ans[all[k][2]] = prev(it)->second;
      }
    }
    for (int k = i; k <= j; k++) {
      s.insert({all[k][1], all[k][2]});
    }
    i = j;
  }
  for (auto i : ans) {
    if (i != -1) i++;
    cout << i << ' ';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}