#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 20;
const int MOD = 1000000007;
const int INV2 = (MOD + 1) / 2;

void fwht(int n, int a[]) {
  for (int len = 1; len < n; len <<= 1) {
    for (int i = 0; i < n; i += len << 1) {
      for (int j = 0; j < len; ++j) {
        int u = a[i + j], v = a[i + j + len];
        a[i + j] = (u + v) % MOD;
        a[i + j + len] = (u - v + MOD) % MOD;
      }
    }
  }
}

int n;
char s[N + 5];

int a[N];

int main() {
  scanf("%d", &n);
  scanf("%s", s);

  int ln = n;

  n = 1 << n;
  for (int i = 0; i < n; ++i) {
    a[i] = s[i] - '0';
  }

  fwht(n, a);
  for (int i = 0; i < n; ++i) a[i] = 1LL * a[i] * a[i] % MOD;
  fwht(n, a);

  vector<int> twos(ln + 1);
  twos[0] = 1;
  for (int i = 1; i < twos.size(); ++i) twos[i] = 1LL * INV2 * twos[i - 1] % MOD;

  int ans = 0;
  for (int i = 0; i < n; ++i) ans = (3LL * a[i] * twos[__builtin_popcount(i)] + ans) % MOD;
  printf("%d\n", ans);
  return 0;
}