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
    string s;
    cin >> s;
    vector<int> ans(n);
    int cur = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        ans[i] = cur++;
      } else {
        ans[i] = --cur;
      }
    }
    int mn = *min_element(begin(ans), end(ans));
    for (int i = 0; i < n; i++) {
      ans[i] -= mn;
      ans[i]++;
    }
    cout << *max_element(begin(ans), end(ans)) << "\n";
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}