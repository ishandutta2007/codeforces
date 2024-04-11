#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, m;
int used[N];
int st[N], top;
int a[N];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int u;
    scanf("%d", &u);
    a[u % m]++;
  }
  if (a[0]) {
    puts("YES");
    return 0;
  }
  st[0] = 0;
  top = 1;
  for (int it = 1; it < m; it++) {
    int cur = 0;
    for (int x = 1; x <= a[it]; x++) {
      int xx = top;
      for (int i = cur; i < xx; i++) {
        if (used[(st[i] + it) %m]) {
          continue;
        }
        if ((st[i] + it) % m == 0) {
          puts("YES");
          return 0;
        }
        used[(st[i] + it) % m] = 1;
        st[top++] = (st[i] + it) % m;
      }
      cur = xx;
    }
  }
  puts("NO");
  return 0;
}