#include <bits/stdc++.h>
using namespace std;
using lint = long long;

const int MAXN = 100005;
const int MAXP = 10;

int N, P, K;
lint A[MAXN];
lint S[MAXN][MAXP];
int order[MAXN];

lint dp[2][1 << MAXP];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N >> P >> K;
  
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
    order[i] = i;
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < P; j++) {
      cin >> S[i][j];
    }
  }

  sort(order + 1, order + N + 1, [&](int i, int j) {
    return A[i] > A[j];
  });

  for (int mask = 0; mask < (1 << P); mask++) {
    dp[1][mask] = -1e15;
  }
  dp[1][0] = 0;

  for (int i = 1; i <= N; i++) {
    int cur = order[i];
    // cout << "cur: " << cur << "\n";
    for (int mask = 0; mask < (1 << P); mask++) {
      int picked = __builtin_popcount(mask);
      dp[(i + 1) & 1][mask] = dp[i & 1][mask] + (i - picked <= K ? A[cur] : 0);
    }
    for (int mask = 0; mask < (1 << P); mask++) {
      for (int j = 0; j < P; j++) {
        if (mask & (1 << j)) {
          continue;
        }
        dp[(i + 1) & 1][mask ^ (1 << j)] = max(dp[(i + 1) & 1][mask ^ (1 << j)], dp[i & 1][mask] + S[cur][j]);
      }
    }
    // for (int mask = 0; mask < (1 << P); mask++) {
    //   cout << dp[(i + 1) & 1][mask] << " \n"[mask == (1 << P) - 1];
    // }
  }

  cout << dp[(N + 1) & 1][(1 << P) - 1] << "\n";
  return 0;
}