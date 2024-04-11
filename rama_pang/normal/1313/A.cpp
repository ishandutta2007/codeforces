#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  vector<int> plates;
  for (int mask = 1; mask < (1 << 3); mask++) {
    plates.emplace_back(mask);
  }

  int T;
  cin >> T;
  while (T--) {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    sort(begin(plates), end(plates));
    do {
      int cnt = 0;
      int ta = a, tb = b, tc = c;
      for (auto &i : plates) {
        bool can = true;
        if (i & (1 << 0)) {
          if (ta == 0) {
            can = false;
          }
        }
        if (i & (1 << 1)) {
          if (tb == 0) {
            can = false;
          }
        }
        if (i & (1 << 2)) {
          if (tc == 0) {
            can = false;
          }
        }
        if (can) {
          cnt++;
          if (i & (1 << 0)) {
            ta--;
          }
          if (i & (1 << 1)) {
            tb--;
          }
          if (i & (1 << 2)) {
            tc--;
          }
        }
      }
      ans = max(ans, cnt);
    } while (next_permutation(begin(plates), end(plates)));
    cout << ans << "\n";
  }
}