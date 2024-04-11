#include <bits/stdc++.h>
using namespace std;

const int N = 500005;

int n;
int a[N];

int main() {
  scanf("%d", &n);

  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    sum += a[i];
  }

  int cnt = 0;
  if (sum % 3 != 0) return 0 * printf("0\n");

  long long pre = 0, suf = 0;
  for (int i = 0; i < n-1; ++i) {
    pre += a[i];
    if (pre == sum / 3) ++cnt;
  }

  long long ans = 0;
  for (int i = n-1; i >= 0; --i) {
    if (i > 0) {
      if (pre == sum/3) --cnt;
      pre -= a[i-1];
    }
    suf += a[i];

    if (suf == sum/3) ans += cnt;
  }

  printf("%lld\n", ans);
  return 0;
}