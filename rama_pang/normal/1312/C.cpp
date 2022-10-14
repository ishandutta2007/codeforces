#include <bits/stdc++.h>
using namespace std;
using lint = long long;

lint power(lint n, lint k) {
  if (k == 0) {
    return 1;
  }
  lint res = power(n, k / 2);
  if (res >= 1e8 + 100) {
    res = 1e17;
    return res;
  }
  res *= res;
  if (res >= 1e16) {
    return res;
  }
  if (k & 1) res *= n;
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    lint n, k;
    cin >> n >> k;
    vector<lint> a(n);

    bool can = true;

    for (int i = 0; i < n; i++) {
      lint m;
      cin >> m;
      lint binary = 0;
      for (lint j = 55; j >= 0; j--) {
        if (m >= power(k, j)) {
          m -= power(k, j);
          binary |= 1ll << j;
        }
      }
      if (m > 0) {
        can = false;
      }
      a[i] = binary;
    }
    
    lint cur = 0;
    for (int i = 0; i < n; i++) {
      if ((cur ^ a[i]) == (cur | a[i])) {
        cur |= a[i];
      } else {
        can = false;
      }
    }

    if (can) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}