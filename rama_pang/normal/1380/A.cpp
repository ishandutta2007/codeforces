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
    for (auto &i : a) {
      cin >> i;
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      ans = {i};
      for (int j = 0; j < i; j++) {
        if (a[j] < a[i]) {
          ans.emplace_back(j);
          break;
        }
      }
      for (int j = i + 1; j < n; j++) {
        if (a[j] < a[i]) {
          ans.emplace_back(j);
          break;
        }
      }
      if (ans.size() == 3) {
        break;
      }
      ans.clear();
    }
    if (ans.empty()) {
      cout << "NO\n";
      continue;
    }
    sort(begin(ans), end(ans));
    cout << "YES\n";
    for (auto i : ans) {
      cout << i + 1 << " ";
    }
    cout << "\n";
  }
}