#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#define all(x) begin(x), end(x)
#define sz(x) (int) x.size()


int solve() {
  lint N, M;
  cin >> N >> M;

  vector<lint> A(M);
  lint sum = 0;
  map<lint, lint> mp;
  for (int i = 0; i < M; i++) {
    cin >> A[i];
    sum += A[i];
    mp[A[i]]++;
  }
  if (sum < N) {
    cout << -1 << "\n";
    return 0;
  }
  lint ans = 0;
  for (lint j = 0; j < 62; j++) {
    if (N & (1ll << j)) {
      lint k;
      for (k = j; k < 62; k++) {
        if (mp[(1ll << k)] > 0) {
          mp[(1ll << k)]--;
          break;
        }
      }
      ans += k - j;
      mp[(1ll << j)] += (1ll << (k - j));
      mp[(1ll << j)]--;
    }
    mp[(1ll << (j + 1))] += mp[(1ll << j)] / 2;
  }

  cout << ans << "\n";

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    solve();
  }
  return 0;
}