#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
int a[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  long long lst = a[0];
  long long maks = 0;
  for (int i = 1; i < n; ++i) {
    maks = max(maks, max(0LL, lst - 1LL*a[i]));
    lst = max(lst, 1LL*a[i]);
  }

  int ans = 0;
  long long cur = 0;
  while (cur < maks) {
    cur *= 2; ++cur;
    ++ans;
  }

  printf("%d\n", ans);
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