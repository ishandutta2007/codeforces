#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

long long n;
int m;
int a[N];

int cnt[60];

int solve() {
  scanf("%lld %d", &n, &m);

  for (int i = 0; i < 60; ++i) cnt[i] = 0;

  long long sum = 0;
  for (int i = 0; i < m; ++i) {
    scanf("%d", &a[i]);
    sum += a[i];
    ++cnt[__builtin_ctz(a[i])];
  }

  if (sum < n) return 0 * printf("-1\n");

  int ans = 0;
  long long pending = 0;
  for (int i = 0; i < 60; ++i) {
    pending += (1LL << i) * cnt[i];
    if (n >> i & 1) {
      if (pending < (1LL << i)) {
        for (int j = i+1; j < 60; ++j) {
          if (cnt[j] > 0) {
            --cnt[j];
            for (int k = j-1; k >= i; --k) ++cnt[k], ++ans;
            pending += 1LL << i;
            break;
          }
        }
      } else pending -= 1LL << i;
    }
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