#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const int MAXN = 100005;
const int MOD = 1e9 + 7;

int N, M, X;
int dp[340 * 340 * 340];

lint f(int pos, int n, int open) {
  if (open < 0 || n > N) {
    return 0;
  }
  if (pos == M) {
    return n == N && open == 0;
  }
  lint res = dp[pos * (N + 5) * (N + 5) + n * (N + 5) + open];
  if (res != -1) {
    return res;
  }
  res = 0;
  if (pos == X) {
    res += f(pos + 1, n + 1, open); // open and close an interval
    res += f(pos + 1, n + 1, open + 1); // open an interval
  } else {
    res += f(pos + 1, n + 1, open); // open and close an interval
    res += f(pos + 1, n + 1, open + 1); // open an interval
    res += f(pos + 1, n, open - 1); // close an interval
    res += f(pos + 1, n, open); // do nothing
  }
  return dp[pos * (N + 5) * (N + 5) + n * (N + 5) + open] = (res %= MOD);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  memset(dp, -1, sizeof(dp));

  cin >> N >> M >> X; X--;
  if (N > 2 * M) {
    cout << 0 << "\n";
  } else {
    int res = f(0, 0, 0);
    for (int i = 1; i <= N; i++) {
      res = 1ll * res * i % MOD;
    }
    cout << res << "\n";
  }
  return 0;
}