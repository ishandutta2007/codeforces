#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, b;
int t[N], d[N];
int top, bot;
long long q[N];
long long res[N];

int main() {
  scanf("%d %d", &n, &b);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", t + i, d + i);
  }
  top = bot = 0;
  for (int i = 1; i <= n; i++) {
    while (bot < top && q[bot] <= t[i]) {
      bot++;
    }
    if (bot == top) {
      res[i] = q[top++] = t[i] + d[i];
    } else {
      if (top - bot >= b + 1) {
        res[i] = -1;
      } else {
        res[i] = q[top - 1] + d[i];
        q[top++] = res[i];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%I64d ", res[i]);
  }
  return 0;
}