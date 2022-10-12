#include <bits/stdc++.h>
using namespace std;
 
const int N = 100005;
 
int x, y;

int solve() {
  scanf("%d %d", &x, &y);
  printf("%d %d\n", x - 1, y);
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