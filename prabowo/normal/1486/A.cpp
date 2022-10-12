#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;
const int INF = 1e9;

int n;
int a[N];

int solve() {
  scanf("%d", &n);

  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  for (int i = 0; i < n; ++i) {
    sum += a[i];
    sum -= i;

    if (sum < 0) return 0 * printf("NO\n");
  }

  printf("YES\n");

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