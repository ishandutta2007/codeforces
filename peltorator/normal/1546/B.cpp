#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n, m;
  cin >> n >> m;
  string ans(m, 0);
  for (int i = 0; i < 2 * n - 1; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      if (i < n) {
        ans[j] += s[j];
      } else {
        ans[j] -= s[j];
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