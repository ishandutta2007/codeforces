#include <bits/stdc++.h>
using namespace std;

const int N = 33;

int n, k;
int a[N], b[N];

int solve() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
  sort(a, a + n);
  sort(b, b + n, greater<int>());
  for (int i = 0; i < k; ++i) {
    if (a[i] < b[i]) swap(a[i], b[i]);
  }

  int sum = 0;
  for (int i = 0; i < n; ++i) sum += a[i];
  printf("%d\n", sum);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}