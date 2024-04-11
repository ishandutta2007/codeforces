#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int lv(string s, int k, char c) {
      int cnt = 0;
      int ans = 0;
      for (int i = 0; i < s.size(); i++) {
            if (s[i] == c) {
                  cnt++;
                  if (cnt == k) {
                        ans++;
                        cnt = 0;
                  }
            } else {
                  cnt = 0;
            }
      }
      return ans;
}

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n, k; cin >> n >> k;
      string s; cin >> s;

      int ans = 0;
      for (char c = 'a'; c <= 'z'; c++) {
            ans = max(ans, lv(s, k, c));
      }
      cout << ans;

      return 0;
}