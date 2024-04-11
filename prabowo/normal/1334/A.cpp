#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n;
int p[N], c[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &p[i], &c[i]);
  }

  if (p[0] < c[0]) return 0 * printf("NO\n");
  for (int i = 1; i < n; ++i) {
    if (p[i] < c[i]) return 0 * printf("NO\n");
    if (p[i] < p[i-1]) return 0 * printf("NO\n");
    if (c[i] < c[i-1]) return 0 * printf("NO\n");
    if (c[i] - c[i-1] > p[i] - p[i-1]) return 0 * printf("NO\n");
  }  

  printf("YES\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}