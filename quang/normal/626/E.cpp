#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

struct fraction {
  long long a;
  long long b;
};

bool operator < (const fraction &u, const fraction &v) {
  return u.a * v.b < u.b * v.a;
}

int n;
int x[N];
long long sum[N];
fraction res = {0, 1};
int posi, posk;

fraction get(int u, int len) {
  long long now = sum[u] - sum[u-  len - 1];
  now += sum[n] - sum[n - len];
  fraction cur = {now, 2ll * len + 1};
  cur.a -= cur.b * x[u];
  if (res < cur) {
    res = cur;
    posi = u;
    posk = len;
  }
  return cur;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", x + i);
  }
  posi = 1;
  sort(x + 1, x + n + 1);
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + x[i];
  }
  for (int i = 1; i <= n; i++) {
    int l = -1, r = min(i - 1, n - i) + 1;
    while (r - l > 2) {
      int m1 = (l + r) / 2;
      int m2 = m1 + 1;
      fraction x1 = get(i, m1);
      fraction x2 = get(i, m2);
      if (x1 < x2) {
        l = m1;
      } else {
        r = m2;
      }
    }
    get(i, (l + r) / 2);
  }
  printf("%d\n", posk * 2 + 1);
  printf("%d ", x[posi]);
  for (int i = 1; i <= posk; i++) {
    printf("%d %d ", x[posi - i], x[n - i + 1]);
  }
  return 0;
}