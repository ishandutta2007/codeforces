#include <bits/stdc++.h>
using namespace std;

const int N = 55;

int n;
int a[N];

int solve() {
  scanf("%d", &n);

  int cnt[2] = {0, 0};
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    ++cnt[a[i] & 1];
  }

  if (cnt[0] & 1) {
    sort(a, a + n);
    for (int i = 1; i < n; ++i) {
      if (a[i] == a[i-1] + 1) return 0 * printf("YES\n");
    }

    return 0 * printf("NO\n");
  }

  printf("YES\n");
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}