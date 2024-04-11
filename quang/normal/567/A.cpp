#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int a[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 1; i <= n; i++) {
    int res = 2e9 + 10;
    if (i > 1) {
      res = min(res, a[i] - a[i - 1]);
    }
    if (i < n) {
      res = min(res, a[i + 1] - a[i]);
    }
    printf("%d %d\n",res, max(a[n] - a[i], a[i] - a[1]));
  }
}