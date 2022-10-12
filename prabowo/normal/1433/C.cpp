#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

int n;
int a[N];

int solve() {
  int n;
  scanf("%d", &n);

  int maxi = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    maxi = max(maxi, a[i]);
  }

  for (int i = 0; i < n; ++i) {
    if (a[i] == maxi) {
      if (i > 0 && a[i-1] < maxi) return 0 * printf("%d\n", i + 1);
      if (i < n-1 && a[i+1] < maxi) return 0 * printf("%d\n", i + 1);
    }
  }

  printf("%d\n", -1);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}