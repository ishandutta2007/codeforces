#include <bits/stdc++.h>

using namespace std;

long long s, x;
int a[50], b[50];

int main() {
  cin >> s >> x;
  for (int i = 0; i < 50; i++) {
    a[i] = (s >> i) & 1;
    b[i] = (x >> i) & 1;
  }
  long long res = 1;
  for (int i = 49; i >= 0; i--) {
    if (a[i] == 0) {
      if (b[i]) {
        cout << 0 << endl;
        return 0;
      }
    }
    if (a[i] == 1) {
      if (!b[i]) {
        if (i == 0) {
          cout << 0 << endl;
          return 0;
        }
        a[i - 1] += 2;
      } else {
        res *= 2;
      }
    }
    if (a[i] == 2) {
      if (b[i]) {
        if (i == 0) {
          cout << 0 << endl;
          return 0;
        }
        a[i - 1] += 2;
        res *= 2;
      }
    }
    if (a[i] == 3) {
      if (!b[i]) {
        if (i == 0) {
          cout << 0 << endl;
          return 0;
        }
        a[i - 1] += 2;
      } else {
        cout << 0 << endl;
        return 0;
      }
    }
  }
  if (s == x) {
    res -= 2;
  }
  cout << res << endl;
  return 0;
}