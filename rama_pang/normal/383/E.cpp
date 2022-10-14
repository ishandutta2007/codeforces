#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N;
  cin >> N;

  const int M = 24;
  vector<int> A(1 << M);

  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    int mask = 0;
    for (auto j : s) {
      mask |= 1 << (j - 'a');
    }
    for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
      if (__builtin_popcount(submask) & 1) {
        A[submask]++;
      } else {
        A[submask]--;
      }
    }
  }

  vector<int> dp(1 << M);
  for (int i = 0; i < (1 << M); i++) {
    dp[i] = A[i];
  }
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < (1 << M); j++) {
      if (j & (1 << i)) {
        dp[j] += dp[j ^ (1 << i)];
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < (1 << M); i++) {
    ans ^= dp[i] * dp[i];
  }
  cout << ans << "\n";
  return 0;
}