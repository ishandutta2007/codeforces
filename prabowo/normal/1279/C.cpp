#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, m;
int a[N];
int b[N];

int pos[N];

int solve() {  
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    pos[a[i]] = i;
  }

  int deepest = 0;
  long long ans = 0;
  for (int i = 0; i < m; ++i) {
    scanf("%d", &b[i]);
    if (pos[b[i]] > deepest) {
      deepest = pos[b[i]];
      ans += (pos[b[i]] - i) * 2 + 1;
    } else ++ans;
  }

  printf("%lld\n", ans);
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}