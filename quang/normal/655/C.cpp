#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, k;
char a[N];
int sum[N];

int main() {
  scanf("%d %d", &n, &k);
  scanf("%s", a + 1);
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + (a[i] == '0');
  }
  int res = 2e9;
  for (int i = 1; i <= n; i++) {
    if (a[i] == '1') {
      continue;
    }
    int l = -1, r = n + 1;
    while (r - l > 1) {
      int m = (l + r) >> 1;
      int tot = 0;
      int x = min(n, i + m);
      tot += sum[x] - sum[i];
      x = max(1, i - m);
      tot += sum[i - 1] - sum[x - 1];
      if (tot >= k) {
        r = m;
      } else {
        l = m;
      }
    }
    res = min(res, r);
  }
  cout << res << endl;
  return 0;
}