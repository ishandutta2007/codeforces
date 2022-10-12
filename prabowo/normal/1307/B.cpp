#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, x;
int a[N];

int solve() {
  scanf("%d %d", &n, &x);
  int maxi = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    maxi = max(maxi, a[i]);
  }

  int ans = (x + maxi - 1) / maxi;
  if (ans == 1) {
    for (int i = 0; i < n; ++i) {
      if (a[i] == x) return 0 * printf("1\n");
    }

    ++ans;
  }

  printf("%d\n", ans);

  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) {
    solve();
  }

  return 0;
}