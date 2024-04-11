#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, k, a, b, q;
int val[N];

struct bit {
  long long t[N];

  void add(int x, int v) {
    while (x < N) {
      t[x] += v;
      x += (x & -x);
    }
  }

  long long get(int x) {
    long long res = 0;
    while (x) {
      res += t[x];
      x -= (x & -x);
    }
    return res;
  }

  long long get(int l, int r) {
    if (l > r) {
      return 0ll;
    }
    return get(r) - get(l - 1);
  }
} bigA, smallA, bigB, smallB;

void push(int x, int sign) {
  if (val[x] < a) {
    smallA.add(x, val[x] * sign);
  } else {
    bigA.add(x, sign);
  }
  if (val[x] < b) {
    smallB.add(x, val[x] * sign);
  } else {
    bigB.add(x, sign);
  }
}

int main() {
  scanf("%d %d %d %d %d", &n, &k, &a, &b, &q);
  for (int i = 1; i <= q; i++) {
    int op, x, y;
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d %d", &x, &y);
      push(x, -1);
      val[x] += y;
      push(x, 1);
    } else {
      scanf("%d", &x);
      long long res = 0;
      res = smallB.get(1, x - 1) + 1ll * bigB.get(1, x - 1) * b;
      res += smallA.get(x + k, n) + 1ll * bigA.get(x + k, n) * a;
      printf("%I64d\n", res);
    }
  }
  return 0;
}