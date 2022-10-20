#include <bits/stdc++.h>

using namespace std;

int n;
int c[10], d[10], f[10];
long long a[10], b[10];
int res = 1000000000;

int get(long long u) {
  int res = 0;
  for (int i = 2; 1ll * i * i <= u; i++) {
    while (u % i == 0) {
      u /= i;
      res++;
    }
  }
  res += (u > 1);
  return res;
}

void go(int u) {
  if (u > n) {
    int ans = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      cnt += (f[i] == 0);
      ans += c[i] > 1;
    }
    ans += (cnt > 1);
    for (int i = 1; i <= n; i++) {
      ans += d[i];
    }
    res = min(res, ans);
    return;
  }
  f[u] = 0;
  go(u + 1);
  for (int i = u + 1; i <= n; i++) {
    if (b[i] % a[u] == 0) {
      d[i] -= c[u];
      f[u] = i;
      b[i] /= a[u];
      go(u + 1);
      b[i] *= a[u];
      d[i] += c[u];
      f[i] = 0;
    }
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    b[i] = a[i];
    c[i] = get(a[i]);
    d[i] = c[i];
  }
  go(1);
  cout << res << endl;
  return 0;
}