#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n;
int a[N], cnt[N];
int used[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    cnt[a[i]] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (!cnt[i]) {
      puts("-1");
      return 0;
    }
  }
  long long res = 1;
  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      int tot = 0;
      int u = i;
      while (!used[u]) {
        tot++;
        used[u] = 1;
        u = a[u];
      }
      if (tot % 2 == 0) {
        tot /= 2;
      }
      res = 1ll * res * tot / __gcd(res, 1ll * tot);
    }
  }
  cout << res << endl;
  return 0;
}