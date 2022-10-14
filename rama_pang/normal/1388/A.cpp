#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  const vector<int> ints = {6, 10, 14, 15, 21, 35, 22, 33};  
  while (T--) {
    int n;
    cin >> n;
    vector<int> ans;
    for (auto i : ints) {
      for (auto j : ints) {
        for (auto k : ints) {
          int l = n - i - j - k;
          if (l <= 0 || i == j || i == k || i == l || j == k || j == l || k == l) {
            continue;
          }
          ans = {i, j, k, l};
        }
      }
    }

    if (ans.empty()) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      for (auto i : ans) {
        cout << i << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}