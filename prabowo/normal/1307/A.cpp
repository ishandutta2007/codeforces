#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, d;
int a[N];

int solve() {
  scanf("%d %d", &n, &d);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  int ans = a[0];
  for (int i = 1; i < n; ++i) {
    int add = min(a[i], d / i);
    d -= add * i;
    ans += add;
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