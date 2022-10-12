#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n, m, k;
int a[N];
char s[N];

int solve() {
  scanf("%d", &n);

  int idx = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] < a[idx]) idx = i;
  }

  printf("%d\n", n - 1);
  for (int i = 0; i < n; ++i) {
    if (i == idx) continue;
    if (idx % 2 == i % 2) {
      printf("%d %d %d %d\n", i + 1, idx + 1, a[idx], a[idx]);
    } else {
      printf("%d %d %d %d\n", i + 1, idx + 1, a[idx] + 1, a[idx]);
    }
  }

  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}