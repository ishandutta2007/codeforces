#include <bits/stdc++.h>
using namespace std;

using lint = long long;
#define int lint

void Main() {
  string s;
  cin >> s;
  vector<int> last(26, -1);
  vector<int> nxt(s.size(), -1);
  string ans;
  for (int i = int(s.size()) - 1; i >= 0; i--) {
    int c = s[i] - 'a';
    nxt[i] = last[c];
    last[c] = i;
  }
  for (int i = 0; i < int(s.size()); i++) {
    if (nxt[i] == -1) {
      for (int j = i; j < int(s.size()); j++) {
        ans.push_back(s[j]);
      }
      break;
    }
  }
  // reverse(begin(ans), end(ans));
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