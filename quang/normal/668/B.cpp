#include <bits/stdc++.h>

using namespace std;

const int N = 1000100;

int n, q;
int isOdd = 0, pos = 0, dis = 1;
int res[N];

int main() {
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= q; i++) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int u;
      scanf("%d", &u);
      pos = (pos + u + n) % n;
      if (abs(u) % 2) {
        isOdd ^= 1;
      }
    } else {
      if (isOdd) {
        pos = (pos - 1 + n) % n;
        dis += 2;
      } else {
        pos = (pos + 1) % n;
        dis -= 2;
      }
      isOdd ^= 1;
    }
  }
  dis %= n;
  if (dis < 0) {
    dis += n;
  }
  int now = pos;
  for (int i = 1; i <= n; i += 2) {
    res[now] =i;
    now = (now + 2) % n;
  }
  now = (pos + dis) % n;
  for (int i = 2; i <= n; i += 2) {
    res[now] = i;
    now = (now + 2) % n;
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", res[i]);
  }
  return 0;
}