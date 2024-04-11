#include <bits/stdc++.h>

using namespace std;

long long res = 0;
int a[10];

int main() {
  for (int i = 1; i <= 6; i++) {
    cin >> a[i];
  }
  res = 2ll * (a[2] + a[3]) * (a[4] + a[5]);
  res -= 1ll * a[2] * a[2];
  res -= 1ll * a[5] * a[5];
  cout << res << endl;
  return 0;
}