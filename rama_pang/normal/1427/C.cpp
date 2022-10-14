#include <bits/stdc++.h>
using namespace std;
using lint = long long;

void Main() {
  int R, N;
  cin >> R >> N;
  vector<int> X(N + 1), Y(N + 1), T(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> T[i] >> X[i] >> Y[i];
    X[i]--, Y[i]--;
  }

  vector<int> dp(N + 1, -1e9);
  vector<int> mx(N + 1, -1e9);
  dp[0] = 0;
  int curmx = -1e9;
  for (int i = 0; i <= N; i++) {
    curmx = max(curmx, mx[i]);
    dp[i] = max(dp[i], curmx);
    for (int j = i + 1; j <= i + 2 * R && j <= N; j++) {
      if (abs(X[i] - X[j]) + abs(Y[i] - Y[j]) <= T[j] - T[i]) {
        dp[j] = max(dp[j], dp[i] + 1);
      }
    }
    if (i + 2 * R <= N) {
      mx[i + 2 * R] = max(mx[i + 2 * R], dp[i] + 1);
    }
  }

  cout << *max_element(begin(dp), end(dp)) << "\n";

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