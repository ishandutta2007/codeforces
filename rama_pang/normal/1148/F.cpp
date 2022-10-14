#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;

  vector<lint> v(n), m(n);
  lint total = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i] >> m[i];
    total += v[i];
  }

  if (total < 0) {
    for (int i = 0; i < n; i++) {
      v[i] *= -1;
    }
    total *= -1;
  }

  lint s = 0;
  for (lint b = 0; b < 62; b++) {
    lint sum = 0;
    for (int i = 0; i < n; i++) {
      if ((1ll << b) <= m[i] && m[i] < (1ll << (b + 1))) {
        if (__builtin_popcountll(m[i] & s) & 1) {
          sum -= v[i];
        } else {
          sum += v[i];
        }
      }
    }
    if (sum > 0) {
      s |= 1ll << b;
    }
  }

  lint cc = 0;
  for (int i = 0; i < n; i++) {
    if (__builtin_popcountll(m[i] & s) & 1) {
      cc -= v[i];
    } else {
      cc += v[i];
    }
  }
  if (cc >= 0) {
    cout << total << " " << cc << "\n";
  }
  cout << s << "\n";
  return 0;
}