#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int LG = 20;

int n;
int a[N];

int ans[N];

int solve() {
  scanf("%d", &n);
  vector<int> cnt(LG, 0);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    ans[i] = 0;

    for (int j = 0; j < LG; ++j) {
      if (a[i] >> j & 1) ++cnt[j];
    }
  }

  for (int i = 0; i < LG; ++i) {
    for (int j = 0; j < cnt[i]; ++j) {
      ans[j] |= 1 << i;
    }
  }

  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += 1LL * ans[i] * ans[i];
  }

  printf("%lld\n", sum);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) solve();
  return 0;
}