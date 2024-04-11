#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int a, b, p;
    cin >> a >> b >> p;
    string s;
    cin >> s;
    vector<lint> dp(s.size());
    dp[(int) s.size() - 1] = 0;
    char last = 'x';
    int id = s.size();
    for (int i = (int) s.size() - 2; i >= 0; i--) {
      if (last != s[i]) {
        last = s[i];
        id = i;
      }
      dp[i] = dp[id + 1] + (s[i] == 'A' ? a : b);
    }
    int ans = s.size();
    for (int i = (int) s.size() - 1; i >= 0; i--) {
      if (dp[i] <= p) {
        ans = i;
      }
    }
    cout << ans + 1 << "\n";
  }
  
}