#include <bits/stdc++.h>
using namespace std;

#define int long long

int bo;
vector<int> op(500005);
vector<int> cl(500005);

void solve() {
      string s; cin >> s;
      int neg = 0, pos = 0;

      int o = 0;
      for (char c: s) {
            if (c == '(') o++;
            else o--;
      }

      if (o == 0) {
            int valid = 1;
            for (char c: s) {
                  if (c == '(') o++;
                  else o--;

                  if (o < 0) valid = 0;
            }
            bo += valid;

            return;
      }

      if (o > 0) {
            o = 0;

            int valid = 1;
            for (char c: s) {
                  if (c == '(') o++;
                  else o--;

                  if (o < 0) valid = 0;
            }

            if (valid) op[o]++;

            return;
      }

      if (o < 0) {
            reverse(s.begin(), s.end());

            o = 0;

            int valid = 1;
            for (char c: s) {
                  if (c == ')') o++;
                  else o--;

                  if (o < 0) valid = 0;
            }

            if (valid) cl[o]++;

            return;
      }
}

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      while (n--) {
            solve();
      }

      int ans = bo/2;
      for (int i = 1; i <= 500000; i++) {
            ans += min(op[i], cl[i]);
      }
      cout << ans;

      return 0;
}