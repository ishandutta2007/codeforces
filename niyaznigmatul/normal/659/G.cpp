#include <bits/stdc++.h>

using namespace std;

int const N = 1234567;
int const MOD = 1000000007;

int a[N];

int mul(int a, int b) {
  return (int) ((long long) a * b % MOD);
}

void add(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  int ans = 0;
  int cur = 0;
  for (int i = 0; i < n; i++) {
    int z = a[i];
    if (i > 0) {
      z = std::min(z, a[i - 1]);
    }
    if (i > 0) {
      add(ans, mul(cur, z - 1));
    }
    add(ans, a[i] - 1);
    if (i + 1 < n) {
      int ncur = std::min(a[i + 1], a[i]) - 1;
      z = std::min(z, a[i + 1]);
      add(ncur, mul(cur, z - 1));
      cur = ncur;
    }
  }
  printf("%d\n", ans);
}