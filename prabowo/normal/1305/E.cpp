#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

int n, m;
int ans[N];

bool has[N*N];

int solve() {
  scanf("%d %d", &n, &m);

  int _m = m;
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    ++cur;

    if (m >= i/2) {
      m -= i/2;
    } else if (m > 0) {
      if (i % 2 == 0) {
        cur += (i/2 - m) * 2 - 1;
      } else {
        cur += (i/2 - m) * 2;
      }
      m = 0;
    } else {
      while (has[cur]) ++cur;
    }

    ans[i] = cur;
    for (int j = 0; j < i; ++j) if (ans[i] + ans[j] < N*N) has[ans[i] + ans[j]] = true;
  }

  if (m != 0) return 0 * printf("-1\n");
  for (int i = 0; i < n; ++i) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) {
    solve();
  }

  return 0;
}