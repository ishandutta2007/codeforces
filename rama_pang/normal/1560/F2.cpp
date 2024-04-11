#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  string n;
  cin >> n;
  int k;
  cin >> k;
  lint ans = 1e18;
  int mask = 0;
  lint leading = 0;
  for (int i = 0; i < n.size(); i++) {
    int lo = n[i] - '0';
    for (int j = lo + 1; j < 10; j++) {
      if (__builtin_popcount(mask | (1 << j)) <= k) {
        lint bd = leading * 10 + j;
        if (__builtin_popcount(mask | (1 << j) | (1 << 0)) <= k) {
          for (int x = i + 1; x < n.size(); x++) {
            bd = bd * 10;
          }
          ans = min(ans, bd);
        } else {
          int lowest = 9;
          for (int l = 9; l >= 1; l--) {
            if (((mask | (1 << j)) >> l) & 1) {
              lowest = l;
            }
          }
          for (int x = i + 1; x < n.size(); x++) {
            bd = bd * 10 + lowest;
          }
          ans = min(ans, bd);
        }
      }
    }
    mask |= 1 << lo;
    leading = leading * 10 + lo;
  }
  if (__builtin_popcount(mask) <= k) ans = min(ans, leading);
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}