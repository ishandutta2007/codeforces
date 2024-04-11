#include <bits/stdc++.h>
using namespace std;

const int N = 1050000;

int h, g;
int a[N*2];

inline int height(int x) {
  return 32 - __builtin_clz(x);
}

int find(int x) {
  for (int i = height(x); i < h; ++i) {
    if (a[x*2] == 0 && a[x*2 + 1] == 0) return x;
    if (a[x*2] > a[x*2 + 1]) x = x*2;
    else x = x*2 + 1;
  }

  return x;
}

void erase(int x) {
  for (int i = height(x); i < h; ++i) {
    if (a[x*2] == 0 && a[x*2 + 1] == 0) {
      a[x] = 0;
      return;
    }
    if (a[x*2] > a[x*2 + 1]) {
      a[x] = a[x*2];
      x = x*2;
    } else {
      a[x] = a[x*2 + 1];
      x = x*2 + 1;
    }
  }

  a[x] = 0;
}

int ans[N];
int solve() {
  scanf("%d %d", &h, &g);
  long long sum = 0;
  for (int i = 1; i < 1 << h; ++i) {
    scanf("%d", &a[i]);
    sum += a[i];
  }

  int idx = 0;
  for (int i = 1; i < 1 << g; ++i) {
    while (height(find(i)) > g) {
      sum -= a[i];
      erase(i);
      ans[idx++] = i;
    }
  }

  printf("%lld\n", sum);
  for (int i = 0; i < idx; ++i) printf("%d ", ans[i]); printf("\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}