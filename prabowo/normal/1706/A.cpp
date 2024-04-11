#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m;
int a[N];

char s[N];

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    --a[i];
  }

  for (int i = 0; i < m; ++i) s[i] = 'B';
  s[m] = 0;

  for (int i = 0; i < n; ++i) {
    int mini = min(a[i], m - a[i] - 1);
    int maxi = max(a[i], m - a[i] - 1);

    if (s[mini] == 'B') {
      s[mini] = 'A';
    } else {
      s[maxi] = 'A';
    }
  }

  printf("%s\n", s);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc + 1);
    solve();
  }
  return 0;
}