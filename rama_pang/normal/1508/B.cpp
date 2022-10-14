#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18 + 100;

void Main() {
  lint N, K;
  cin >> N >> K;
  vector<lint> dp(N + 1);
  lint sum = 1;
  dp[0] = 1;
  for (int i = 1; i <= N; i++) {
    dp[i] += sum;
    sum += dp[i];
    sum = min(sum, INF);
  }
  if (K > dp[N]) {
    cout << -1 << '\n';
    return;
  }
  vector<lint> ans;
  while (ans.size() < N) {
    int n = N - int(ans.size());
    for (int i = 1; i <= n; i++) {
      if (K > dp[n - i]) {
        K -= dp[n - i];
      } else {
        int base = ans.size() + 1;
        for (int j = i - 1; j >= 0; j--) {
          ans.emplace_back(base + j);
        }
        break;
      }
    }
  }
  for (auto i : ans) {
    cout << i << ' ';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}