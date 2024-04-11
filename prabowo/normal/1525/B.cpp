#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n;
int a[N];
char s[N];

int solve() {
  scanf("%d", &n);

  bool isSorted = true;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    --a[i];

    if (a[i] != i) isSorted = false;
  }

  if (isSorted) return 0 * printf("0\n");
  if (a[0] == 0 || a[n - 1] == n - 1) return 0 * printf("1\n");
  if (a[0] == n - 1 && a[n - 1] == 0) return 0 * printf("3\n");
  printf("2\n");
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