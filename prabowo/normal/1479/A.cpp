#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
int a[N];

int ask(int x) {
  if (x < 0 || x >= n) return 1e9;
  printf("? %d\n", x + 1);
  fflush(stdout);
  int ret;
  scanf("%d", &ret);
  return ret;
}

int main() {
  scanf("%d", &n);

  int l = 0, r = n - 1;
  while (l < r) {
    int mid = (l + r) >> 1;

    if (ask(mid) < ask(mid + 1)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }

  printf("! %d\n", l + 1);
  fflush(stdout);
  return 0;
}