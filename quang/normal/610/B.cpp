#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;
int a[N * 2], st[N * 2], top, bot;
int minval = 2e9;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    a[i + n] = a[i];
    minval = min(minval, a[i]);
  }
  int pre = 0;
  long long res = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == minval) {
      st[top++] = i;
    }
  }
  res = 1ll * minval * n + st[0] - 1;
  for (int i = n + 1; i < n + n; i++) {
    if (a[i] == minval) {
      st[top++] = i;
    }
    if (st[bot] + n <= i) {
      bot++;
    }
    res = max(res, 1ll * minval * n + st[bot] - (i - n + 1));
  }
  cout << res << endl;
    return 0;
}