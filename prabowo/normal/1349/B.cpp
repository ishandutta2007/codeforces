#include <bits/stdc++.h>
using namespace std;
  
int n, k;
 
int solve() {
  scanf("%d %d", &n, &k);

  bool found = false, can = false;
  int prv1 = -1, prv2 = -1, a;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a);
    if (a == k) found = true;
    if (a >= k) can |= (prv1 >= k) | (prv2 >= k);
    prv1 = prv2;
    prv2 = a;
  }
 
  if (n == 1) return 0 * printf(found ? "yes\n" : "no\n");
  printf(found && can ? "yes\n" : "no\n");
  return 0;
}
 
int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    solve();
  }
  return 0;
}