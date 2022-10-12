#include <bits/stdc++.h>
using namespace std;
 
const int N = 1000005;
const int INF = 1e9;
 
int n;
int a[N];
int b[N];
 
int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
  }
 
  int line = INF + INF;
 
  for (int i = 0; i < n-1; ++i) {
    if (a[i] > b[i]) {
      if (line < a[i] - b[i]) return 0 * printf("NO\n");
      if (b[n-1] < a[i] - b[i]) return 0 * printf("NO\n");
      line -= a[i] - b[i];
      b[n-1] -= a[i] - b[i];
      a[i] = b[i];
    }
 
    b[i] -= a[i];
    if (b[i] > a[i+1]) {
      a[i+1] = 0;
    } else {
      a[i+1] -= b[i];
    }
    line = min(line, a[i]);
  }
 
  if (a[n-1] > 0 && b[n-1] < a[n-1]) return 0 * printf("NO\n");

  printf("YES\n");
  return 0;
}
 
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}