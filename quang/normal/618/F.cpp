#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int n;
long long a[N], b[N];
pair<int, int> pre[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", a + i);
    a[i] += a[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", b + i);
    b[i] += b[i - 1];
  }
  int f = 0;
  if (a[n] > b[n]) {
    swap(b, a);
    f = 1;
  }
  for (int i = 0; i < n; i++) {
    pre[i] = make_pair(-1, -1);
  }
  int cur = 0;
  pre[0] = make_pair(0, 0);
  for (int i = 1; i <= n; i++) {
    while (a[i] >= b[cur + 1]) {
      cur++;
    }
    int delta = a[i] - b[cur];
    if (pre[delta].first != -1) {
      if (!f) {
        printf("%d\n", i - pre[delta].first);
        for (int j = pre[delta].first + 1; j <= i; j++) {
          printf("%d ", j);
        }
        printf("\n");
        printf("%d\n", cur - pre[delta].second);
        for (int j = pre[delta].second + 1; j <= cur; j++) {
          printf("%d ", j);
        }
      } else {
        printf("%d\n", cur - pre[delta].second);
        for (int j = pre[delta].second + 1; j <= cur; j++) {
          printf("%d ", j);
        }
        printf("\n");
        printf("%d\n", i - pre[delta].first);
        for (int j = pre[delta].first + 1; j <= i; j++) {
          printf("%d ", j);
        }
      }
      return 0;
    }
    pre[delta] = make_pair(i, cur);
  }
  return 0;
}