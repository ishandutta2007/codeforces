#include <bits/stdc++.h>
using namespace std;

const int N = 505;
const int MOD = 1000000007;

int n;
int cnt[N];

int pot[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    if (a >= 0) ++cnt[--a];
  }

  for (int i = 1; i < n; ++i) pot[i] = (2 * pot[i - 1] + 1) % MOD;

  int ans = pot[n - 1];
  for (int i = 0; i < n; ++i) ans = (ans - pot[cnt[i]]) % MOD;
  if (ans < 0) ans += MOD;

  printf("%d\n", ans);
  return 0;
}