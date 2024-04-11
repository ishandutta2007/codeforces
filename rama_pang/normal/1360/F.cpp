#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    auto Valid = [&](string s) {
      for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
          if (s[j] != a[i][j]) {
            cnt++;
          }
        }
        if (cnt > 1) return false;
      }
      return true;
    };
    string ans = "-1";
    if (Valid(a[0])) {
      ans = a[0];
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < 26; j++) {
        string t = a[0];
        t[i] = j + 'a';
        if (Valid(t)) {
          ans = t;
        }
      }
    }
    cout << ans << "\n";
  }
}