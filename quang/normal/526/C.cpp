#include <bits/stdc++.h>

using namespace std;

int c, h1, h2, w1, w2;

int main() {
  //freopen("C.in", "r", stdin);
  cin >> c >> h1 >> h2 >> w1 >> w2;
  if (w1 <= w2 && h1 >= h2) {
    int sl = c / w1;
    cout << 1ll * sl * h1;
    return 0;
  }
  if (w1 >= w2 && h1 <= h2) {
    int sl = c / w2;
    cout << 1ll * sl * h2;
    return 0;
  }
  long long res = 0;
  for (int i = 0; i <= 2000000; i++) {
    if (1ll * i * w1 > c) {
      break;
    }
    int cl = c - i * w1;
    cl /= w2;
    res = max(res, 1ll * h1 * i + 1ll * h2 * cl);
  }
 for (int i = 0; i <= 2000000; i++) {
    if (1ll * i * w2 > c) {
      break;
    }
    int cl = c - i * w2;
    cl /= w1;
    res = max(res, 1ll * h1 * cl + 1ll * h2 * i);
  }
  cout << res;
  return 0;
}