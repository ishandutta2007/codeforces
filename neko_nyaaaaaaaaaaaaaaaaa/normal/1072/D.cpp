#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

      int n, k; cin >> n >> k;
      vector<vector<char>> c(4008, vector<char>(4008, '|'));
      vector<vector<int>> dp(4008, vector<int>(4008));
      for (int i = 2; i <= 2000; i++) {
            dp[i][0] = dp[0][i] = 5000;
      }

      int len = 1;
      for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                  char x; cin >> x;
                  c[i][j] = x;
                  dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + (x != 'a');
                  if (dp[i][j] <= k) {
                        len = max(len, i+j);
                  }
            }
      }
      if (len == 2*n) {while (--len) cout << 'a'; return 0;}

      string ans;
      for (int i = 1; i < len; i++) ans += 'a';

      set<pair<int, int>> q;
      if (len == 1) {ans += c[1][1]; q.insert({1, 1});}
      for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                  if (i+j == len && dp[i][j] <= k) {q.insert({i, j});}
            }
      }

      while (ans.size() < 2*n-1) {
            char r = '|';
            for (pair<int, int> p: q) {
                  r = min(r, min(c[p.first][p.second + 1], c[p.first + 1][p.second]));
            }
            ans += r;
            if (ans.size() == 2*n-1) break;

            set<pair<int, int>> s;
            for (pair<int, int> p: q) {
                  if (c[p.first][p.second + 1] == r) s.insert({p.first, p.second + 1});
                  if (c[p.first + 1][p.second] == r) s.insert({p.first + 1, p.second});
            }
            swap(s, q);
      }

      cout << ans;

	return 0;
}