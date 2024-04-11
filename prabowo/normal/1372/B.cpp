#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m;
int a[N];

int solve() {
  int n;
  scanf("%d", &n);

  for (int i = 2; i*i <= n; ++i) {
    if (n % i == 0) {
      return 0 * printf("%d %d\n", n/i, n - n/i);
    }
  }

  printf("%d %d\n", 1, n-1);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}