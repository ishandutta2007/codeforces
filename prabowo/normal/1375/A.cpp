#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int MOD = 998244353;

int n;
int a[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    printf("%d ", abs(a[i]) * (i & 1 ? -1 : 1));
  }
  printf("\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}