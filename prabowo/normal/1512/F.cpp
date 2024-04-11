#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n, c;
int a[N], b[N];

int solve() {
  scanf("%d %d", &n, &c);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n - 1; ++i) {
    scanf("%d", &b[i]);
  }

  long long ans = 1e18;

  long long days = 0;
  long long money = 0;
  for (int i = 0; i < n; ++i) {
    ans = min(ans, days + max(0LL, (c - money + a[i] - 1) / a[i]));
    long long work = max(0LL, (b[i] - money + a[i] - 1) / a[i]);
    money += 1LL * work * a[i] - b[i];
    days += work + 1;
  }

  printf("%lld\n", ans);
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