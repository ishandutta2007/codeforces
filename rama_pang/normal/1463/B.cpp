#include <bits/stdc++.h>
using namespace std;
using lint = long long;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  lint sum = accumulate(begin(a), end(a), 0ll);
  lint s1 = 0, s2 = 0;
  for (int i = 0; i < n; i++) {
    if (i & 1) {
      s1 += abs(a[i] - 1);
    } else {
      s2 += abs(a[i] - 1);
    }
  }
  assert(2 * min(s1, s2) <= sum);
  for (int i = 0; i < n; i++) {
    if (s1 < s2) {
      if (i & 1) {
        a[i] = 1;
      }
    } else {
      if (i & 1) {

      } else {
        a[i] = 1;
      }
    }
  }
  for (auto i : a) cout << i << ' '; cout << '\n';
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