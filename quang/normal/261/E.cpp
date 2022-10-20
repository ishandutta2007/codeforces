#include <bits/stdc++.h>

using namespace std;

const int N = 3000010, prime[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

int l, r, p;
int a[N], cnt;
int f[N], g[N];

bool check(int u) {
  for (int i = 2; i * i <= u; i++) {
    if (u % i == 0) {
      return 0;
    }
  }
  return 1;
}

void go(int sum, int u) {
  if (u > 25 || prime[u] > p) {
    a[++cnt] = sum;
    return;
  }
  long long x = 1;
  while (x * sum <= r) {
    go(x * sum, u + 1);
    x *= prime[u];
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> l >> r >> p;
  go(1, 1);
  sort(a + 1, a + cnt + 1);
  for (int i = 1; i <= cnt; i++) {
    f[i] = g[i] = 1e9;
  }
  f[1] = 1;
  g[1] = 0;
  for (int i = 2; i <= p; i++) {
    int cur = 1;
    for (int j = 1; j <= cnt; j++) {
      while (a[cur] * i < a[j]) {
        cur++;
      }
      f[j]++;
      if (a[cur] * i == a[j]) {
        f[j] = min(f[j], f[cur] + 1);
      }
      g[j] = min(g[j], f[j]);
    }
  }
  int res = 0;
  for (int i = 1; i <= cnt; i++) {
    if (l <= a[i] && a[i] <= r && g[i] <= p) {
      res++;
    }
  }
  cout << res << endl;
  return 0;
}