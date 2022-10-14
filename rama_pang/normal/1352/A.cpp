#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    vector<string> ans;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') continue;
      string t;
      t.push_back(s[i]);
      for (int j = i + 1; j < n; j++) {
        t.push_back('0');
      }
      ans.emplace_back(t);
    }

    cout << ans.size() << "\n";
    for (auto i : ans) cout << i << " ";
    cout << "\n";
  }
}