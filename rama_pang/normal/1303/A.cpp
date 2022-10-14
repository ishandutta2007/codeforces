#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#define all(x) begin(x), end(x)
#define sz(x) (int) x.size()



int solve() {

  string s;
  cin >> s;
  int mn = -1, mx = -1;
  for (int i = 0; i < s.size(); i++) {
    if (mn == -1 && s[i] == '1') {
      mn = i;
    }
    if (s[i] == '1') {
      mx = i;
    }
  }
  if (mn == -1 && mx == -1) {
    cout << 0 << "\n";
    return 0;
  }
  int cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1') cnt++;
  }
  cout << (mx - mn + 1 - cnt) << "\n";


}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    solve();
  }
  return 0;
}