#include <bits/stdc++.h>

using namespace std;

long long get(long long u) {
  long long res = 0;
  while (u) {
    res += u / 5;
    u /= 5;
  }
  return res;
}

int main() {
  int m;
  cin >> m;
  long long l = 0, r = (1ll << 60);
  while (r - l > 1) {
    long long mi = (l + r) >> 1;
    if (get(mi) >= m) {
      r = mi;
    } else {
      l = mi;
    }
  }
  if (get(r) == m) {
    cout << 5 << endl;
    for (int i = 0; i < 5; i++) {
      cout << r + i << " ";
    }
  } else {
    cout << 0 << endl;
  }
  return 0;
}