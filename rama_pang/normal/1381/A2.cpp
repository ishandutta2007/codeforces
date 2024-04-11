#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<int> ans;
    function<void(int, int, int, int)> Solve = [&](int l, int r, int i, int rev) {
      if (i < 0) return;
      if (rev) {
        if ((a[l] ^ '1' ^ '0') == b[i]) {
          return Solve(l + 1, r, i - 1, rev);
        }
        if ((a[r] ^ '1' ^ '0') == b[i]) {
          ans.emplace_back(0);
          a[r] ^= '0' ^ '1';
        }
        ans.emplace_back(i);
        return Solve(l, r - 1, i - 1, rev ^ 1);        
      } else {
        if (a[r] == b[i]) {
          return Solve(l, r - 1, i - 1, rev);
        }
        if (a[l] == b[i]) {
          ans.emplace_back(0);
          a[l] ^= '0' ^ '1';
        }
        ans.emplace_back(i);
        return Solve(l + 1, r, i - 1, rev ^ 1);
      }
    };
    Solve(0, n - 1, n - 1, 0);
    cout << ans.size() << " ";
    for (auto i : ans) {
      cout << i + 1 << " ";
    }
    cout << "\n";
  }
  return 0;
}