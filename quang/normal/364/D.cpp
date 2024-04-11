#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int n;
long long a[N];
long long d[N];
int cnt, s[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", a + i);
  }
  long long res = 0;
  for (int it = 1; it <= 10; it++) {
    cnt = 0;
    int id = 1ll * rand() * rand() % n + 1;
    for (int i = 1; 1ll * i * i <= a[id]; i++) {
      if (a[id] % i == 0) {
        d[++cnt] = i;
        if (1ll * i * i != a[id]) {
          d[++cnt] = a[id] / i;
        }
      }
    }
    sort(d + 1, d + cnt + 1);
    for (int i = 1; i <= cnt; i++) {
      s[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      long long x = __gcd(a[i], a[id]);
      x = lower_bound(d + 1, d + cnt + 1, x) - d;
      s[x]++;
    }
    for (int i = 1; i <= cnt; i++) {
      for (int j = i + 1; j <= cnt; j++) {
        if (d[j] % d[i] == 0) {
          s[i] += s[j];
        }
      }
      if (s[i] + s[i] >= n && d[i] > res) {
        res = d[i];
      }
    }
  }
  printf("%I64d", res);
  return 0;
}