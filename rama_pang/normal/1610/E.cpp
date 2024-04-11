#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

#define int lint

void Main() {
  // cntLess >= cntMore
  // if we delete one of cntLess, than avg increases, so is better, but 1 less of cntless
  // if we delete one of cntMore, than avg decreases, so is more restricting
  // worst case is if we delete max or min
  // so all subarrays must be good
  // so 
  // L, M, R
  // say M > (L + R)/2
  // then (L + M + R) > L + R + (L + R)/2
  // (L + M + R)/3 > L/3 + R/3 + (L + R)/6
  // // M <= (L + M + R)/3
  // M <= L/3 + M/3 + R/4
  // 2M/3 <= L/3 + R/3
  // 2M <= L + R
  // M <= (L + R)/2
  // Contradiction
  //
  // so sequence must look like:
  // C[k - 1] <= (C[1] + C[k]) / 2
  // 2C[k - 1] <= C[1] + C[k]
  // C[k - 1] - C[k] <= C[1] - C[k - 1]
  // 0 2 4 8
  // 
  // 1,1,1,2,4,8,
  // M > (L + M + R)/3
  // M > 
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 1;
  for (int i = 0; i < n; i++) {
    if (i + 1 < n && a[i] == a[i + 1]) continue;
    int cnt = 0;
    while (i - cnt >= 0 && a[i - cnt] == a[i]) cnt += 1;
    if (i + 1 < n) {
      cnt += 1;
      int g = a[i + 1] - a[i];
      while (true) {
        auto it = lower_bound(begin(a), end(a), a[i] + g + g) - begin(a);
        if (it == n) break;
        g = a[it] - a[i];
        cnt += 1;
      }
    }
    ans = max(ans, cnt);
  }
  cout << n - ans << '\n';
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}