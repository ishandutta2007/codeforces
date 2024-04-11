#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n0, n1, n2;
    cin >> n0 >> n1 >> n2;
    if (n1 == 0) {
      vector<int> ans;
      if (n0 == 0) {
        for (int i = 0; i < n2 + 1; i++) {
          ans.emplace_back(1);
        }
      } else if (n2 == 0) {
        for (int i = 0; i < n0 + 1; i++) {
          ans.emplace_back(0);
        }
      }

      for (auto i : ans) cout << i;
      cout << "\n";
      continue;
    }

    vector<int> ans;
    for (int i = 0; i < n1 + 1; i++) {
      ans.emplace_back(i % 2);
      if (ans.back() == 0 && n0 > 0) {
        while (n0--) {
          ans.emplace_back(ans.back());
        }
      } else if (ans.back() == 1 && n2 > 0) {
        while (n2--){
          ans.emplace_back(ans.back());
        }
      }
    }

    for (auto i : ans) cout << i;
    cout << "\n";
  }
}