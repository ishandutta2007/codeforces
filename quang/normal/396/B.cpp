#include <bits/stdc++.h>

using namespace std;

int n;

bool prime(int u) {
  for (int i = 2; i * i <= u; i++) {
    if (u % i == 0) {
      return 0;
    }
  }
  return 1;
}

struct fraction {
  long long x, y;

  fraction(long long _x = 0, long long _y = 1) {
    x = _x;
    y = _y;
    long long z = __gcd(x, y);
    x /= z, y/= z;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    int pre = n;
    while (!prime(pre)) {
      pre--;
    }
    int next = n + 1;
    while (!prime(next)) {
      next++;
    }
    fraction res = fraction(1ll * pre * next - 2ll * next + 2ll *  (n - pre + 1), 2ll * pre * next);
    cout << res.x << "/" << res.y << endl;
  }
  return 0;
}