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
    vector<int> a(n);
    for (auto &i : a) {
      cin >> i;
      i--;
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (i == 0 || i == n - 1) {
        ans.push_back(a[i]);
      } else if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
        ans.push_back(a[i]);
      } else if (a[i - 1] > a[i] && a[i] < a[i + 1]) {
        ans.push_back(a[i]);
      }
    }
    cout << ans.size() << "\n";
    for (auto i : ans) cout << i + 1 << " ";
    cout << "\n";
  } 
}