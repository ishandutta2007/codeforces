#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
int a[N];

int cnt[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) cnt[i] = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    ++cnt[--a[i]];
  }

  int mod = 0;
  for (int i = 1; i < n; ++i) {
    if (cnt[i] > cnt[mod]) {
      mod = i;
    }
  }

  if (cnt[mod] > (n + 1) / 2) return 0 * printf("-1\n");

  for (int i = 0; i < n; ++i) cnt[i] = 0;

  int ans = 0;
  ++cnt[a[0]], ++cnt[a[n - 1]];
  for (int i = 1; i < n; ++i) {
    if (a[i] == a[i - 1]) {
      cnt[a[i]] += 2;
      ++ans;
    }
  }

  int maxi = 0;
  for (int i = 0; i < n; ++i) {
    if (cnt[i] > maxi) maxi = cnt[i];
  }

  if (maxi > ans + 2) ans += maxi - (ans + 2);

  printf("%d\n", ans);
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    solve();
  }
  return 0;
}