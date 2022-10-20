#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m, k, p;
int h[N], a[N];
long long tot[N], need[N], cut[N];

bool check(long long u) {
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    need[i] = max(0ll, tot[i] - u);
    sum += max(0ll, (need[i] + p - 1) / p);
  }
  if (sum > 1ll * m * k) {
    return 0;
  }
  for (int i = 0; i <= m + 1; i++) {
    cut[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    if (!need[i]) {
      continue;
    }
    for (long long j = (need[i] - 1) % p + 1; j <= need[i]; j += p) {
      if (j <= h[i]) {
        cut[0]++;
        continue;
      }
      int pos = (j - h[i] - 1) / a[i] + 1;
      if (pos >= m) {
        return 0;
      }
      cut[pos]++;
    }
  }
  int rest = 0;
  for (int i = 0; i < m; i++) {
    rest += cut[i];
    rest = max(0, rest - k);
  }
  return rest == 0;
}

long long random(int u) {
  long long res = rand();
  res = (res << 16) + rand();
  res = (res << 16) + rand();
  return res % u;
}

int main() {
  #ifdef QQ
  freopen("input.txt", "r", stdin);
  #endif // QQ
  scanf("%d %d %d %d", &n, &m, &k, &p);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", h + i, a + i);
    tot[i] = 1ll * a[i] * m + h[i];
  }
  long long l = 0, r = 1e14;
  while (r - l > 1) {
    long long mi = (l + r) >> 1;
    if (check(mi)) {
      r = mi;
    } else {
      l = mi;
    }
  }
  printf("%I64d\n", r);
//  n = 100000, m = 5000, k = 10, p = random(1e9) + 1;
//  cout << n << " " << m << " " << k << " " << p << endl;
//  for (int i = 1; i <= n;i++) {
//    cout << random(1e9) + 1 << " " << random(1e9)  + 1<< endl;
//  }
  return 0;
}