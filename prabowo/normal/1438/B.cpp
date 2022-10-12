#include <bits/stdc++.h>
using namespace std;
 
const int N = 100005;

int n;
int b[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
  sort(b, b + n);
  printf(unique(b, b + n) - b == n ? "NO\n" : "YES\n");
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