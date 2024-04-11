#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n;
int a[N];

int solve() {
  int n;
  scanf("%d", &n);

  int ans = 0;
  int lst = -1;
  bool zero = 0;
  for (int i = 1; i <= n; ++i) {
    int a;
    scanf("%d", &a);
    if (a == 0) {
      zero = true;
    } else {
      if (zero && lst != -1) ans += i - lst - 1; 
      lst = i;
      zero = false;
    }
  }

  printf("%d\n", ans);
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