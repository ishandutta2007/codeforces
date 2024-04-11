#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, S, E;
  cin >> N >> S >> E;
  S--, E--;

  vector<lint> X(N), A(N), B(N), C(N), D(N);
  for (int i = 0; i < N; i++) cin >> X[i];
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> B[i];
  for (int i = 0; i < N; i++) cin >> C[i];
  for (int i = 0; i < N; i++) cin >> D[i];

  const auto Update = [&](lint &a, lint b) { a = min(a, b); };

  vector<lint> dp(N + 5, INF); dp[0] = 0;
  for (int i = 0; i < N; i++) {
    vector<lint> ndp(N + 5, INF);
    // i to j, i < j:
    // * X[j] - X[i] + D[i] + A[j]
    // i to j, i > j:
    // * X[i] - X[j] + C[i] + B[j]
    int st = S < i;
    int et = E < i;
    if (i == S) {
      for (int c = 0; c <= N; c++) {
        // new component, i -> big
        Update(ndp[c + 1], dp[c] - X[i] + D[i]);
        // append to front of a free component, i -> small
        if (c - et > 0) Update(ndp[c], dp[c] + X[i] + C[i]);
        // append to front of a E component, i -> small,
        if (c == 1 && i + 1 == N) Update(ndp[c], dp[c] + X[i] + C[i]);
      }
    } else if (i == E) {
      for (int c = 0; c <= N; c++) {
        // new component, big -> i
        Update(ndp[c + 1], dp[c] - X[i] + B[i]);
        // append to back of a free component, small -> i
        if (c - st > 0) Update(ndp[c], dp[c] + X[i] + A[i]);
        // append to back of a S component, small -> i
        if (c == 1 && i + 1 == N) Update(ndp[c], dp[c] + X[i] + A[i]);
      }
    } else {
      for (int c = 0; c <= N; c++) {
        // new component, big -> i -> big
        Update(ndp[c + 1], dp[c] - X[i] + B[i] - X[i] + D[i]);
        // append to front of a free or E compnent, big -> i -> small
        if (c - st > 0) Update(ndp[c], dp[c] - X[i] + B[i] + X[i] + C[i]);
        // append to back of a free or S component, small -> i -> big
        if (c - et > 0) Update(ndp[c], dp[c] + X[i] + A[i] - X[i] + D[i]);
        // merge two free components, small -> i -> small
        if (c - st - et > 1) Update(ndp[c - 1], dp[c] + X[i] + A[i] + X[i] + C[i]);
        // merge S component and free component, small -> i -> small
        if (st > 0 && c - st - et > 0) Update(ndp[c - 1], dp[c] + X[i] + A[i] + X[i] + C[i]);
        // merge free component and E component, small -> i -> small
        if (c - st - et > 0 && et > 0) Update(ndp[c - 1], dp[c] + X[i] + A[i] + X[i] + C[i]);
        // merge S component and E component, small -> i -> small
        if (st > 0 && et > 0 && c == 2 && i + 1 == N) Update(ndp[c - 1], dp[c] + X[i] + A[i] + X[i] + C[i]);
      }
    }
    swap(dp, ndp);
  }

  cout << dp[1] << '\n';
  return 0;
}