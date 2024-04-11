#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;

    if (n - k >= 0) {
      vector<int> ans(k, 1);
      ans[0] += n - k;
      if (ans[0] & 1) {
        cout << "YES\n";
        for (auto i : ans) cout << i << " ";
        cout << "\n";
        continue;
      }
    }

    if (n - 2 * k >= 0) {
      vector<int> ans(k, 2);
      ans[0] += n - 2 * k;
      if (ans[0] % 2 == 0) {
        cout << "YES\n";
        for (auto i : ans) cout << i << " ";
        cout << "\n";
        continue;
      }
    }

    cout << "NO\n";
  }
}