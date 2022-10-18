#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n;
  string s, t;
  cin >> n >> s >> t;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (t[i] == '1') {
      if (s[i] == '0') {
        ans++;
        continue;
      }
      for (int j : {-1, 1}) {
        if (i + j >= 0 && i + j < n && s[i + j] == '1') {
          s[i + j] = '0';
          ans++;
          break;
        }
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}