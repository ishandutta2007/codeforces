#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

void Main() {
  // Optimal = mincut on B -> A
  // Mincut = maxflow >= sum(chest)
  // dp tries all assignemnts on flow,
  // so one of them is maxflow
  // dp[key][chest][flow source -> key][all flows chest -> sink]

  int N, M;
  cin >> N >> M;
  vector<int> A(N), B(M);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int j = 0; j < M; j++) {
    cin >> B[j];
  }
  vector<vector<int>> C(N, vector<int>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> C[i][j];
    }
  }

  vector<int> pow5(N + 1, 1);
  for (int i = 1; i <= N; i++) {
    pow5[i] = 5 * pow5[i - 1];
  }

  const int INF = 1e9;
  vector<vector<int>> dp(5, vector<int>(pow5[N], INF));
  dp[0][0] = 0;

  for (int key = 0; key < M; key++) {
    for (int chest = 0; chest < N; chest++) {
      auto ndp = dp;
      for (int i = 0; i < 5; i++) fill(begin(dp[i]), end(dp[i]), INF);
      for (int fl = 0; fl <= B[key]; fl++) {
        for (int mask = 0; mask < pow5[N]; mask++) {
          dp[fl][mask] = min(dp[fl][mask], ndp[fl][mask]); // don't send flow
          for (int send_flow = 0; fl + send_flow <= B[key]; send_flow++) {
            int cur_chest_flow = (mask / pow5[chest]) % 5;
            if (cur_chest_flow + send_flow <= A[chest]) {
              auto &res = dp[fl + send_flow][mask + pow5[chest] * send_flow];
              res = min(res, ndp[fl][mask] + C[chest][key]);
            }
          }
        }
      }
    }
    auto ndp = dp;
    for (int i = 0; i < 5; i++) fill(begin(dp[i]), end(dp[i]), INF);
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < pow5[N]; j++) {
        dp[0][j] = min(dp[0][j], ndp[i][j]); //
      }
    }
  }

  int ans = INF;
  int sum_chest = 0;
  for (int i = 0; i < N; i++) sum_chest += A[i];
  for (int i = 0; i < pow5[N]; i++) {
    int flow = 0;
    for (int j = 0; j < N; j++) {
      flow += (i / pow5[j]) % 5;
    }
    if (flow >= sum_chest) {
      ans = min(ans, dp[0][i]);
    }
  }

  cout << (ans == INF ? -1 : ans) << '\n';
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