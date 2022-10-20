#include <bits/stdc++.h>

using namespace std;

const int N = 2000010;

int rub[N], f[N];
int a[N];

bool check(int u) {
  int v = 0;
  int w = u;
  while (w) {
    v = v * 10 + (w % 10);
    w /= 10;
  }
  return (u == v);
}

int main() {
  ios_base::sync_with_stdio(0);
  a[0] = a[1] = 1;
  for (int i = 2; i < N; i++) {
    if (!a[i]) {
      for (int j = i + i; j < N; j += i) {
        a[j] = 1;
      }
    }
  }
  for (int i = 1; i < N; i++) {
    f[i] = f[i - 1] + (a[i] == 0);
  }
  rub[0] = 0;
  for (int i = 1; i < N; i++) {
    rub[i] = rub[i - 1] + check(i);
  }
  int p, q;
  cin >> p >> q;
  int res = 0;
  for (int i = 1; i < N; i++) {
    if (1ll * q * f[i] <= 1ll * p * rub[i]) {
      res = i;
    }
  }
  cout << res << endl;
  return 0;
}