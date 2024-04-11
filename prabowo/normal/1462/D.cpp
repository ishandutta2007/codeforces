#include <bits/stdc++.h>
using namespace std;
 
const int N = 3005;

int n;
int a[N];

int solve() {
  scanf("%d", &n);
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    sum += a[i];
  }

  for (int i = n; i > 0; --i) {
    if (sum % i != 0) continue;
    bool can = true;

    for (int j = 0; j < n; ) {
      int cum = 0;
      while (j < n && cum < sum / i) cum += a[j++];
      if (cum != sum / i) {
        can = false;
        break;
      }
    }

    if (can) return 0 * printf("%d\n", n - i);
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