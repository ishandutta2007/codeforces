#include <bits/stdc++.h>

using namespace std;

long long a, b;

double check1() {
  long long x = a - b;
  if (x < 0) {
    return (1ll << 60);
  }
  if (x == 0) {
    return b;
  }
  long long k = x / (b * 2);
  if (k == 0) {
    return (1ll << 60);
  }
  return (double)x /((double)k * 2);
}

double check2() {
  long long x = a + b;
  long long k = x / (b * 2);
  if (k == 0) {
    return (1ll << 60);
  }
  return (double)x / ((double)k * 2);
}

int main() {
  ios_base::sync_with_stdio(0);
  #ifdef Doflamingo
  //freopen("input.txt", "r", stdin);
  #endif // Doflamingo
  cin >> a >> b;
  double res1 = (1ll << 60);
  res1 = min(res1, check1());
  res1 = min(res1, check2());
  if (res1 >= (1ll << 60) - 1) {
      cout << -1;
  } else {
    printf("%0.17f", res1);
  }
  return 0;
}