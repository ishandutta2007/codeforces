#include <bits/stdc++.h>
using namespace std;

const int N = 3005;

int n;
int a[N];

int cntsuf[N];
int cntpre[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    --a[i];
  }

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cntsuf[j] = 0;
      cntpre[j] = 0;
    }
    for (int j = n-1; j > i; --j) {
      ++cntsuf[a[j]];
    }
    long long pairs = 0;

    for (int j = i+1; j < n; ++j) {
      pairs -= (cntsuf[a[j]]--) * cntpre[a[j]];
      pairs += cntsuf[a[j]] * cntpre[a[j]];

      if (a[i] == a[j]) {
        ans += pairs;
      }

      pairs -= cntsuf[a[j]] * (cntpre[a[j]]++);
      pairs += cntsuf[a[j]] * cntpre[a[j]];
    }
  }

  printf("%lld\n", ans);
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