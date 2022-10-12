#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, k;
int a[N];

int solve() {
  scanf("%d %d", &n, &k);
  vector<int> sum(k);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    ans += a[i] / k;
    ++sum[a[i] % k];
  }

  int l = 1, r = k - 1;
  while (l <= r) {
    if (sum[l] == 0) {
      ++l;
      continue;
    }
    if (sum[r] == 0) {
      --r;
      continue;
    }
    if (l + r < k) {
      ++l;
      continue;
    }
    if (l < r) {
      ++ans;
      --sum[l];
      --sum[r];
    } else {
      if (sum[l] < 2) break;
      sum[l] -= 2;
      ++ans;
    }
  }

  printf("%lld\n", ans);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc + 1);
    solve();
  }
  return 0;
}