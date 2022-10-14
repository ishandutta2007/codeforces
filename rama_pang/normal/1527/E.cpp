#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    A[i]--;
  }

  using lint = long long;
  const lint INF = 1e18;

  vector<lint> dp(N + 1, INF);
  dp[0] = 0;

  vector<vector<int>> occ(N);
  for (int i = 0; i < N; i++) {
    occ[i].emplace_back(-2);
    occ[i].emplace_back(-1);
  }
  for (int i = 0; i < N; i++) {
    occ[A[i]].emplace_back(i);
  }
  for (int i = 0; i < N; i++) {
    occ[i].emplace_back(N);
    occ[i].emplace_back(N + 1);
  }

  vector<pair<int, int>> active(N);
  for (int i = 0; i < N; i++) {
    active[i] = {2, 2};
  }

  long long cur_cost = 0;
  const auto Insert = [&](int id, int is_back) {
    int elem = A[id];
    const auto &dq = occ[elem];
    auto &[head, tail] = active[elem];
    if (head != tail) {
      cur_cost -= dq[tail - 1] - dq[head];
    }
    if (is_back == 1 && dq[tail] == id) {
      tail++;
    } else if (is_back == 0 && id == dq[head - 1]) {
      head--;
    } else {
      assert(false);
    }
    cur_cost += dq[tail - 1] - dq[head];
  };

  const auto Delete = [&](int id, int is_back) {
    int elem = A[id];
    const auto &dq = occ[elem];
    auto &[head, tail] = active[elem];
    cur_cost -= dq[tail - 1] - dq[head];
    if (is_back == 1 && dq[tail - 1] == id) {
      tail--;
    } else if (is_back == 0 && id == dq[head]) {
      head++;
    } else {
      assert(false);
    }
    if (head != tail) {
      cur_cost += dq[tail - 1] - dq[head];
    }
  };

  const auto Cost = [&](int L, int R) -> lint { // cost of array [L, R]
    static int l = 0;
    static int r = -1;
    while (r < R) Insert(++r, 1);
    while (l > L) Insert(--l, 0);
    while (r > R) Delete(r--, 1);
    while (l < L) Delete(l++, 0);
    return cur_cost;
  };

  for (int k = 0; k < K; k++) {
    static vector<lint> prv(N + 1);
    swap(prv, dp);
    fill(begin(dp), end(dp), INF);
    dp[0] = 0;
    const auto DnC = [&](const auto &self, int L, int R, int optL, int optR) -> void {
      if (L > R) return;
      int M = (L + R) / 2;
      int optM = -1;
      for (int i = optL; i <= optR && i < M; i++) {
        if (dp[M] > prv[i] + Cost(i, M - 1)) {
          dp[M] = prv[i] + Cost(i, M - 1);
          optM = i;
        }
      }
      self(self, L, M - 1, optL, optM);
      self(self, M + 1, R, optM, optR);
    };
    DnC(DnC, 1, N, 0, N);
  }

  cout << dp[N] << '\n';
  return 0;
}