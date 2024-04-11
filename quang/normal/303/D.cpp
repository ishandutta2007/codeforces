#include <bits/stdc++.h>

using namespace std;

int n, x;
vector <int> divs;

int Power(int u, int v, int md) {
  int res = 1;
  while (v) {
    if (v & 1) {
      res = (long long)res * u % md;
    }
    u = (long long)u * u % md;
    v >>= 1;
  }
  return res;
}

int main() {
  scanf("%d %d", &n, &x);
  bool f = 0;
  for (int i = 2; i * i <= (n + 1); i++) {
    if ((n + 1) % i == 0) {
      f = 1;
      break;
    }
  }
  if (f) {
    cout << -1 << endl;
    return 0;
  }
  int m = n;
  for (int i = 2; i * i <= m; i++) {
    if (m % i == 0) {
      divs.push_back(i);
      while (m % i == 0) {
        m /= i;
      }
    }
  }
  if (m > 1) {
    divs.push_back(m);
  }
  for (int val = x - 1; val > 1; val--) {
    int ok = 0;
    for (int i = 0; i < divs.size(); i++) {
      if (Power(val, n / divs[i], n + 1) == 1) {
        ok = 1;
        break;
      }
    }
    if (!ok) {
      cout << val << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}