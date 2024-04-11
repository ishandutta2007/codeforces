#include <bits/stdc++.h>

using namespace std;

long long n;

int main() {
  cin >> n;
  if (!n) {
    cout << 0 << " " << 0 << endl;
    return  0;
  }
  long long l = 0, r = 1e9;
  while (r - l > 1) {
    long long m = (l + r) >> 1;
    long long cnt = 6ll * m * (m + 1) / 2;
    if (cnt >= n) {
      r = m;
    } else {
      l = m;
    }
  }
  long long x = n - 6ll * r * (r - 1) / 2;
//  if (x == r * 6) {
//    cout << r * 2 << " " << 0 << endl;
//  }
  long long a = r * 2, b = 0;
  if (x <= r) {
    cout << a - x << " " << b + x * 2 << endl;
    return 0;
  }
  a -= r;
  b += r * 2;
  if (x <= r * 2) {
    x -= r;
    cout << a - x * 2 << " " << b << endl;
    return 0;
  }
  a -= r * 2;
  if (x <= r * 3) {
    x -= r * 2;
    cout << a - x << " " << b - x * 2 << endl;
    return 0;
  }
  a -= r,
  b -= r * 2;
  if (x <= r * 4) {
    x -= r * 3;
    cout << a + x << " " << b - x * 2 << endl;
    return 0;
  }
  a += r;
  b -= r * 2;
  if (x <= r * 5) {
    x -= r * 4;
    cout << a + x * 2 << " " << b << endl;
    return 0;
  }
  a += r * 2;
  x -= r * 5;
  cout << a + x << " " << b + x * 2 << endl;
  return 0;
}