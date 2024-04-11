#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

void Main() {
  int N, M;
  cin >> N >> M;

  vector<pair<int, int>> A(N);
  vector<pair<int, pair<int, int>>> B(M);
  for (int i = 0; i < N; i++) cin >> A[i].first >> A[i].second;
  for (int i = 0; i < M; i++) cin >> B[i].second.first >> B[i].second.second >> B[i].first;

  sort(begin(B), end(B));
  const int INF = 1e9 + 10;
  const auto chmin = [&](int &a, int b) { a = min(a, b); };
  const auto chmax = [&](int &a, int b) { a = max(a, b); };

  vector<vector<int>> dpT(1 << N, vector<int>(M + 1, +INF)); // dpT[mask][number of quests] = minimum time
  vector<vector<int>> dpQ(1 << N, vector<int>(M + 1, -INF)); // dpQ[mask][last quest] = maximum number of quest, assuming at last quest

  vector<vector<int>> distT(1 << N, vector<int>(N, INF));
  vector<vector<int>> distQ(1 << N, vector<int>(M, INF));

  for (int mask = 0; mask < (1 << N); mask++) {
    for (int k = 0; k < N; k++) if ((mask >> k) & 1) {
      for (int i = 0; i < N; i++) {
        chmin(distT[mask][i], abs(A[i].first - A[k].first) + abs(A[i].second - A[k].second));
      }
      for (int i = 0; i < M; i++) {
        chmin(distQ[mask][i], abs(B[i].second.first - A[k].first) + abs(B[i].second.second - A[k].second));
      }
    }
  }

  for (int i = 0; i < M; i++) {
    chmax(dpQ[0][i], 1);
  }
  for (int i = 0; i < N; i++) {
    chmin(dpT[1 << i][0], 0);
  }

  int ans = 0;
  for (int mask = 0; mask < (1 << N); mask++) {
    for (int k = 0; k < M; k++) {
      ans = max(ans, dpQ[mask][k]);
      // from tower to tower
      for (int i = 0; i < N; i++) {
        if (!((mask >> i) & 1)) {
          chmin(dpT[mask | (1 << i)][k], dpT[mask][k] + distT[mask][i]);
        }
      }
      // from tower to quest
      for (int i = 0; i < M; i++) {
        if (dpT[mask][k] + distQ[mask][i] <= B[i].first) {
          chmax(dpQ[mask][i], k + 1);
        }
      }
      // from quest to quest
      for (int i = 0; i < M; i++) if (i != k) {
        if (B[k].first + min(distQ[mask][i], abs(B[i].second.first - B[k].second.first) + abs(B[i].second.second - B[k].second.second)) <= B[i].first) {
          chmax(dpQ[mask][i], dpQ[mask][k] + 1);
        }
      }
      // from quest to tower
      for (int i = 0; i < N; i++) if (dpQ[mask][k] >= 0) {
        if (!((mask >> i) & 1)) {
          chmin(dpT[mask | (1 << i)][dpQ[mask][k]], B[k].first + min(distT[mask][i], abs(A[i].first - B[k].second.first) + abs(A[i].second - B[k].second.second)));
        }
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