#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
int d[N], a[N];
int pos[N];
int ok[N];

bool check(int u) {
  memset(pos, 0, sizeof pos);
  memset(ok, 0, sizeof ok);
  for (int i = 1; i <= u; i++) {
    if (d[i]) {
      pos[d[i]] = i;
    }
  }
  for (int i = 1; i <= m; i++) {
    if (!pos[i]) {
      return 0;
    }
    ok[pos[i]] = 1;
  }
  long long tot = 0;
  for (int i = u; i; i--) {
    if (ok[i]) {
      tot += a[d[i]];
    } else {
      tot--;
      tot = max(tot, 0ll);
    }
  }
  return tot == 0ll;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", d + i);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", a + i);
  }
  int low = 0, high = n + 1;
  while (high - low > 1) {
    int mid = (low + high) >> 1;
    if (check(mid)) {
      high = mid;
    } else {
      low = mid;
    }
  }
  if (high == n + 1) {
    puts("-1");
  } else {
    printf("%d\n", high);
  }
  return 0;
}