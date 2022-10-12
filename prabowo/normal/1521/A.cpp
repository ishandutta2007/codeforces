#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n, m, k;
int a[N];
char s[N];

int solve() {
  long long a, b;
  scanf("%lld %lld", &a, &b);

  if (b == 1) return 0 * printf("NO\n");

  if (b == 2) b *= 2;

  printf("YES\n");
  printf("%lld %lld %lld\n", a, a * (b - 1), a * b);
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