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
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) {
      cin >> a[i];
    }
    vector<int> odd, even;
    for (int i = 0; i < 2 * n; i++) {
      if (a[i] & 1) {
        odd.emplace_back(i);
      } else {
        even.emplace_back(i);
      }
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i + 1 < (int) odd.size(); i += 2) {
      ans.emplace_back(odd[i], odd[i + 1]);
    }
    for (int i = 0; i + 1 < (int) even.size(); i += 2) {
      ans.emplace_back(even[i], even[i + 1]);
    }
    for (int i = 0; i < n - 1; i++) {
      cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
    }
  }
}