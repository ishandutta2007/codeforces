#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint MOD = 1e9 + 7;

const int ZERO = 4e5 + 2;

int getScore[20][2 * ZERO + 1];

void Main() {
  int n;
  cin >> n;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> sum(n), req(n);
  for (int i = 0; i < n; i++) {
    auto s = a[i];
    int curreq = 0;
    int cursum = 0;
    for (auto c : s) {
      if (c == '(') {
        cursum += 1;
      } else if (c == ')') {
        cursum -= 1;
        curreq = max(curreq, -cursum);
      }
      // iff only when starting is -cursum, and it is >= curreq, we can get +1
      if (-cursum >= curreq) {
        getScore[i][ZERO - cursum] += 1;
      }
    }
    sum[i] = cursum;
    req[i] = curreq;
  }

  int ans = 0;
  vector<int> dp(1 << n, -1e6);
  dp[0] = 0;
  for (int mask = 0; mask < (1 << n); mask++) if (dp[mask] >= 0) {
    int cursum = 0;
    for (int i = 0; i < n; i++) {
      if ((mask >> i) & 1) {
        cursum += sum[i];
      }
    }
    for (int i = 0; i < n; i++) {
      if ((mask >> i) & 1) {
        continue;
      }
      int v = getScore[i][ZERO + cursum];
      ans = max(ans, dp[mask] + v);
      int valid = 1;
      if (cursum >= req[i]) {
        dp[mask | (1 << i)] = max(dp[mask | (1 << i)], dp[mask] + v);
      }
    }    
  }

  cout << ans << '\n';
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}