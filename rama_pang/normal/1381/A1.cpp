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
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] == b[i]) {
        continue;
      }
      if (a.front() == b[i]) {
        ans.emplace_back(0);
        a.front() ^= '0' ^ '1';
      }
      ans.emplace_back(i);
      reverse(begin(a), begin(a) + i + 1);
      for (int j = 0; j <= i; j++) {
        a[j] ^= '0' ^ '1';
      }      
    }

    cout << ans.size() << " ";
    for (auto i : ans) {
      cout << i + 1 << " ";
    }
    cout << "\n";
  }
  return 0;
}