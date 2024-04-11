#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, p, k;
int a[N];

int cnt[N];
int sum[N];

void solve() {
  scanf("%d %d %d", &n, &p, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    sum[i] = cnt[i] = 0;
  }

  sort(a, a + n);

  for (int i = k-1; i < n; ++i) {
    int idx = (i - k + 1) % k;
    if (sum[idx] + a[i] <= p) {
      sum[idx] += a[i];
      ++cnt[idx];
    }
  }

  for (int i = 1; i < k; ++i) a[i] += a[i-1];

  int ans = 0;

  for (int i = 0; i < k; ++i) {
    if (i == 0 || p - sum[i] >= a[i-1]) { 
      ans = max(ans, cnt[i]*k + i);
    }
  }

  printf("%d\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}