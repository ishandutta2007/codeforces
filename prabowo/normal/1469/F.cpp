#include <bits/stdc++.h>
using namespace std;
 
const int N = 1000005;
const int LN = 18;

int n, k;
int a[N];
int diff[N];

int solve() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  sort(a, a + n, greater<int>());

  diff[0] = 1; diff[1] = -1;
  long long sum = 0;
  for (int d = 0, i = 0; d + 1 < N; ++d) {
    diff[d + 1] += diff[d];
    sum += diff[d];
    if (sum + diff[d + 1] >= k) return 0 * printf("%d\n", d + 1);

    while (i < n && sum > 0) {
      diff[d + 2] += 2;
      --diff[d + a[i] / 2 + 2];
      --diff[d + (a[i] - 1) / 2 + 2];
      --sum;
      ++i;
    }
  }

  printf("-1\n");
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}