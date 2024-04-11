#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m;
int a[N];


int solve() {
  scanf("%d %d", &n, &m);
  if (n > m) return 0 * printf("0\n");

  int ans = 1;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    for (int j = 0; j < i; ++j) {
      ans = 1LL * ans * abs(a[i] - a[j]) % m;
    }
  }

  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) {
    solve();
  }

  return 0;
}