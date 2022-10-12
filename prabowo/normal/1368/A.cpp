#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int a, b, n;
int solve() {
  scanf("%d %d %d", &a, &b, &n);

  if (b < a) swap(a, b);

  int cnt = 0;
  while (b <= n) {
    a += b;
    swap(a, b);
    ++cnt;
  }

  printf("%d\n", cnt);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}