#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n;
long long k, x;
long long a[N];

int solve() {
  scanf("%d %lld %lld", &n, &k, &x);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
  }

  sort(a, a + n);

  vector<long long> gaps;

  int ans = 0;
  for (int i = 0; i < n; ) {
    int j = i;
    while (j < n && j == i || a[j] - a[j - 1] <= x) ++j;
    if (j < n) {
      gaps.push_back(a[j] - a[j - 1]);
    }
    i = j;
    ++ans;
  }

  sort(gaps.begin(), gaps.end(), greater<long long>());
  while (gaps.size() > 0 && (gaps.back() - 1) / x <= k) {
    k -= (gaps.back() - 1) / x;
    gaps.pop_back();
    --ans;
  }

  printf("%d\n", ans);
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