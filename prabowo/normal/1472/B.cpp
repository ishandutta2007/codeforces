#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;
const int INF = 1e9;

int n, m, k;
int a[N];

int solve() {
  vector<int> cnt(3, 0);
  scanf("%d", &n);
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    ++cnt[a[i]];
    sum += a[i];
  }

  if (sum % 2 != 0) return 0 * printf("NO\n");
  sum /= 2;
  for (int i = 0; i <= cnt[1]; ++i) {
    if ((sum - i) % 2 == 0 && (sum - (cnt[1] - i)) % 2 == 0) return 0 * printf("YES\n");
  }

  printf("NO\n");
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