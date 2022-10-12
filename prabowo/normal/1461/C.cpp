#include <bits/stdc++.h>
using namespace std;
 
const int N = 100005;
 
int n, m;
int a[N];

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  int lim = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (a[i] != i + 1) {
      lim = i;
      break;
    }
  }

  // cerr << lim << endl;

  int r; double p;
  double ans = 1;
  for (int i = 0; i < m; ++i) {
    scanf("%d %lf", &r, &p);

    if (r > lim) {
      ans = ans * (1 - p);
    }
  }

  if (lim == 0) printf("1.00000000\n");
  else printf("%.8lf\n", 1 - ans);

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