#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#define all(x) begin(x), end(x)
#define sz(x) (int) x.size()

string s, t;
int S, T;
short memo[415][415][415];

short dp(int pos, int fs, int sc) {
  if (pos == S) {
    if (sc == T) {
      return fs;
    } else {
      return -1;
    }
  }
  short &res = memo[pos][fs][sc];
  if (res != -2) {
    return res;
  }
  res = -1;

  if (fs < T) {
    if (s[pos] == t[fs]) {
      res = max(res, dp(pos + 1, fs + 1, sc));
    }
  }
  if (sc < T) {
    if (s[pos] == t[sc]) {
      res = max(res, dp(pos + 1, fs, sc + 1));
    }
  }
  res = max(res, dp(pos + 1, fs, sc));
  return res;
}

int solve() {
  cin >> s >> t;
  S = s.size(), T = t.size();
  int ans = 0;
  for (int i = 0; i < s.size() + 5; i++) {
    for (int j = 0; j < t.size() + 5; j++) {
      for (int k = 0; k < t.size() + 5; k++) {
        memo[i][j][k] = -2;
      }
    }
  }
  for (int i = 0; i < t.size(); i++) {
    int cut = dp(0, 0, i);
    if (cut != -1 && cut >= i) {
      ans = 1;
      break;
    }
  }
  if (ans == 0) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
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