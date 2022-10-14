#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int Z = 30;
const int K = 305;

int dp[2][2 * Z + 1][K][K];

void Move() {
  for (int i = 0; i < 2 * Z + 1; i++) {
    for (int j = 0; j < K; j++) {
      for (int k = 0; k < K; k++) {
        dp[1][i][j][k] = dp[0][i][j][k];
      }
    }
  }
}

void Reset() {
  for (int i = 0; i < 2 * Z + 1; i++) {
    for (int j = 0; j < K; j++) {
      for (int k = 0; k < K; k++) {
        dp[0][i][j][k] = INF;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string S;
  cin >> S;
  reverse(begin(S), end(S));
  S.push_back('0');

  int N = S.size();

  Reset();
  dp[0][Z][K - 1][K - 1] = 0;
  // dp[pos][carry][active_positive][active_negative]
  // note: carry can be negative

  const auto chmin = [&](int &a, int b) { a = min(a, b); };
  const auto floor = [&](int a, int b) { return a / b - ((a ^ b) < 0 && a % b); };

  for (int pos = 0; pos < N; pos++) {
    Move(); Reset();
    for (int carry = -Z; carry <= Z; carry++) {
      for (int active_pos = K - 1; active_pos >= 0; active_pos--) {
        for (int active_neg = K - 1; active_neg >= 0; active_neg--) {
          if (active_pos > 0) {
            chmin(dp[1][carry + Z][active_pos - 1][active_neg], dp[1][carry + Z][active_pos][active_neg]);
          }
          if (active_neg > 0) {
            chmin(dp[1][carry + Z][active_pos][active_neg - 1], dp[1][carry + Z][active_pos][active_neg]);
          }
          int digit = ((carry + active_pos - active_neg) % 10 + 10) % 10;
          int ncarry = floor(carry + active_pos - active_neg, 10);
          if (digit == S[pos] - '0' && -Z <= ncarry && ncarry <= Z) {
            chmin(dp[0][ncarry + Z][active_pos][active_neg], dp[1][carry + Z][active_pos][active_neg] + active_pos + active_neg);
          }
        }
      }
    }
  }

  int ans = INF;
  for (int i = 0; i < K; i++) {
    for (int j = 0; j < K; j++) {
      ans = min(ans, dp[0][Z][i][j]);
    }
  }

  cout << ans << '\n';
  return 0;
}