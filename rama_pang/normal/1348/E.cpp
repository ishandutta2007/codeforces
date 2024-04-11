#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int MAXN = 505;

lint N, K;
lint A[MAXN], B[MAXN];
lint ans = 0;

bool dp[MAXN][MAXN];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
    // if (A[i] / K >= 2) {
    //   ans += A[i] / K - 1;
    //   A[i] %= K; A[i] += K;
    // }
    // if (B[i] / K >= 2) {
    //   ans += B[i] / K - 1;
    //   B[i] %= K; B[i] += K;
    // }
  }

  lint totA = 0, totB = 0;
  for (int i = 0; i < N; i++) {
    totA += A[i];
    totB += B[i];
  }

  ans += totA / K;
  ans += totB / K;
  totA %= K;
  totB %= K;
  if (totA + totB >= K) {
    dp[0][0] = 1;
    for (int n = 0; n < N; n++) {
      for (int k = 0; k <= K; k++) {
        dp[n + 1][k] |= dp[n][k];
        for (int a = 0; a <= K; a++) {
          int b = K - a;
          if (A[n] >= a && B[n] >= b) {
            dp[n + 1][(k + a) % K] |= dp[n][k];
          }
        }
      } 
    }
    for (int a = 0; a <= totA; a++) {
      int b = K - a;
      if (b <= totB) {
        if (dp[N][a]) {
          ans++;
          goto DONE;
        }
      }
    }

    


  }

  DONE: cout << ans << "\n";
  return 0;
}