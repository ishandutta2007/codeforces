#include <bits/stdc++.h>
using namespace std;

using lint = long long;
#define int lint

void Main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  if (n == 1) {
    cout << s << s << '\n';
    return;
  }

  if (s[0] == s[1]) {
    cout << s[0] << s[0] << '\n';
    return;
  }

  string ans;
  char c;
  for (int i = 0; i < n; i++) {
    if (i == 0 || c >= s[i]) {
      c = s[i];
      ans.push_back(c);
    } else {
      break;
    }
  }
  // if (count(begin(ans), end(ans), ans[0]) == ans.size()) {
  //   while (ans.size() > 1) ans.pop_back();
  // }
  n = ans.size();
  string r = ans;
  reverse(begin(r), end(r));
  ans += r;
  cout << ans << '\n';
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}