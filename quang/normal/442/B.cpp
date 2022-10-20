#include <bits/stdc++.h>

using namespace std;

int n;
double a[101];

int main() {
  ios_base::sync_with_stdio(0);
  //freopen("B.inp", "r", stdin);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  double res = 0.0;
  sort(a + 1, a + n + 1);
  double Res = 0.0, Mul = 1.0;
  for (int i = n; i >= 0; i--) {
    Res = Res * (1.0 - a[i]) + Mul * a[i];
    Mul *= (1.0 - a[i]);
    res = max(res, Res);
  }
  printf("%0.15f", res);
}