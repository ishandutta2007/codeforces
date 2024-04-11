#include <bits/stdc++.h>

using namespace std;

long long l, r;
int k;

void case1() {
  long long res = (1ll << 60);
  int m = 0;
  for (int mask = 0; mask < (1 << (r - l + 1)); mask++) {
    long long x = 0;
    int cnt = 0;
    for (int i = 0; i < r - l + 1; i++) {
      if (mask & (1 << i)) {
        cnt++;
        x ^= (l + i);
      }
    }
    if (cnt == 0 || cnt > k) {
      continue;
    }
    if (res > x) {
      res = x;
      m = mask;
    }
  }
  cout << res << endl;
  cout << __builtin_popcount(m) << endl;
  for (int i = 0; i < r - l + 1; i++) {
    if (m & (1 << i)) {
      cout << (i + l) << " ";
    }
  }
}

void case2() {
  if (k == 1) {
    cout << l << endl << 1 << endl;
    cout << l << endl;
    return;
  }
  if (k == 2) {
    if (l & 1) {
      l++;
    }
    cout << 1 << endl;
    cout << 2 << endl;
    cout << l << " " << l + 1 << endl;
    return;
  }
  if (k >= 4) {
    if (l & 1) {
      l++;
    }
    cout << 0 << endl;
    cout << 4 << endl;
    cout << l << " " << l + 1 << " " << l + 2 << " " << l + 3 << endl;
    return;
  }
  long long M = 3, m = 1;
  while (M <= r) {
    if (m >= l) {
      cout << 0 << endl << 3 << endl;
      cout << m << " " << M - 1 << " " << M;
      return;
    }
    m = m * 2 + 1;
    M *= 2;
  }
  cout << 1 << endl;
  if (l & 1) {
    l++;
  }
  cout << 2 << endl;
  cout << l << " " << l + 1 << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> l >> r >> k;
  if (r - l + 1 <= 4) {
    case1();
  } else {
    case2();
  }
  return 0;
}