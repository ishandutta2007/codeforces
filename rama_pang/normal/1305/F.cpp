#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<lint> a(n);
  for (auto &i : a) {
    cin >> i;
  }

  lint g = a[0];
  for (int i = 1; i < n; i++) {
    g = __gcd(g, a[i]);
  }

  if (g != 1) {
    cout << 0 << "\n";
    return 0;
  }
  
  auto cost = [&](lint g) {
    lint res = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] < g) {
        res += g - a[i];
        continue;
      }

      lint op1 = a[i] % g;
      lint op2 = g - op1;

      res += min(op1, op2);
    }
    return res;
  };

  lint ans = cost(2);
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

  auto solve = [&](lint n) {
    lint res = 1e18;
    for (lint i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        while (n % i == 0) {
          n /= i;
        }
        res = min(res, cost(i));
      }
    }
    if (n > 1) {
      res = min(res, cost(n));
    }
    return res;
  };

  for (int rep = 0; rep < 20; rep++) {
    int i = rnd() % n;
    ans = min(ans, solve(a[i] - 1));
    ans = min(ans, solve(a[i] + 1));
    ans = min(ans, solve(a[i]));
  }

  cout << ans << "\n";
  return 0;
}