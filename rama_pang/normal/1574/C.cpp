#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  using lint = long long;

  int N;
  cin >> N;
  vector<lint> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(begin(A), end(A));
  lint S = accumulate(begin(A), end(A), 0ll);

  // cost: max(x - a, 0) + max(y - S + a, 0)
  // y -= S
  // cost: max(x - a, 0) + max(y + a, 0)
  // x <= y:
  // - if a < x: cost = x + y
  // - else: cost = y + a
  // y <= x:
  // - if y <= 0:
  //   - if a < x: cost = x - a + max(y + a, 0)
  //   - else: cost = max(y + a, 0)
  //     - if y + a >= 0: cost = y + a
  //       else: cost = x - a
  // - else:
  //   - if a < x: cost = x + y
  //   - else: cost = y + a
  int T = 1;
  cin >> T;
  while (T--) {
    lint x, y;
    cin >> x >> y;
    y -= S;
    lint ans = 2e18;
    const auto GetCost = [&](lint z) {
      return max(x - z, 0ll) + max(y + z, 0ll);
    };
    for (int rep = 0; rep < 3; rep++) {
      auto it = lower_bound(begin(A), end(A), (rep == 0 ? x : (rep == 1 ? y : -y)));
      if (it != begin(A)) ans = min(ans, GetCost(*prev(it)));
      if (it != end(A)) ans = min(ans, GetCost(*it));
      if (it != end(A) && next(it) != end(A)) ans = min(ans, GetCost(*next(it)));
    }
    cout << ans << '\n';
  }
  return 0;
}