#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> ans;
  vector<set<pair<int, int>>> ord(3);
  for (int i = 0; i < n; i++) {
    ord[a[i] % 3].emplace(a[i], i);
  }

  int cur = 0;
  for (int i = 0; i < n; i++) {
    if (ord[cur % 3].empty()) {
      break;
    }
    auto it = ord[cur % 3].upper_bound({cur, 1e9});
    if (it == begin(ord[cur % 3])) {
      break;
    }
    it = prev(it);
    cur = min(cur, it->first);
    if (cur < it->first) {
      break;
    }
    ans.emplace_back(it->second);
    ord[cur % 3].erase(it);
    cur += 1;
  }

  if (ans.size() != n) {
    cout << "Impossible\n";
  } else {
    cout << "Possible\n";
    for (auto i : ans) {
      cout << i + 1 << " ";
    }
    cout << "\n";
  }
  return 0;
}