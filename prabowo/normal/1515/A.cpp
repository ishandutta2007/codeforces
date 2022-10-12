#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
 
int n;
int a[N];
 
int solve() {
  int x;
  scanf("%d %d", &n, &x);
 
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
 
  if (sum == x) return 0 * printf("NO\n");
 
  sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += a[i];
    if (sum == x) {
      sum -= a[i];
      swap(a[i], a[i + 1]);
      sum += a[i];
    }
  }
  
  printf("YES\n");
  for (int i = 0; i < n; ++i) printf("%d ", a[i]);
  printf("\n");
  return 0;
}
 
int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc + 1);
    solve();
  }
  return 0;
}