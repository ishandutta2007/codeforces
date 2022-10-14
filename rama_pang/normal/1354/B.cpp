#include <bits/stdc++.h>
using namespace std;
using lint = long long;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<pair<int, int>>> nearest(n, vector<pair<int, int>>(3, {-1, -1}));
    int l[3] = {-1, -1, -1};
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 3; j++) {
        nearest[i][j].first = l[j];
      }
      l[s[i] - '1'] = i;
    }
    l[0] = l[1] = l[2] = n + 1;
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j < 3; j++) {
        nearest[i][j].second = l[j];
      }
      l[s[i] - '1'] = i;
    }
    int ans = n + 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
          if (j == k) continue;
          if (j == s[i] - '1') continue;
          if (k == s[i] - '1') continue;
          if (nearest[i][j].first == -1) continue;
          if (nearest[i][k].second == n + 1) continue;
          ans = min(ans, (i - nearest[i][j].first) + (nearest[i][k].second - i) + 1);
        }
      }
    }
    if (ans == n + 1) ans = 0;
    cout << ans << "\n";
  }
}