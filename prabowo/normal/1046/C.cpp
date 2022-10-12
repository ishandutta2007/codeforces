#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, d;
int s[N], p[N];

int solve() {
  scanf("%d %d", &n, &d);
  --d;

  for (int i = 0; i < n; ++i) {
    scanf("%d", &s[i]);
  }

  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
  }

  int ans = d + 1;
  for (int i = 0, j = n-1; i < d; ++i) {
    if (s[i] + p[j] <= s[d] + p[0]) {
      --ans;
      --j;
    }
  }

  printf("%d\n", ans);
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