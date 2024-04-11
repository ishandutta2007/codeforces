#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
int a[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  for (int i = 30; i >= 0; --i) {
    int cnt = 0;
    for (int j = 0; j < n; ++j) {
      if (a[j] >> i & 1) ++cnt;
    }

    if (cnt % 2 == 0) continue;

    if (cnt % 4 == 1) return 0 * printf("WIN\n");
    if (cnt % 4 == 3) {
      if (n - cnt & 1) return 0 * printf("WIN\n");
      return 0 * printf("LOSE\n");
    }
  }

  printf("DRAW\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}