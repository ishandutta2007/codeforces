#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  const int MAX = 1e5 + 5;
  vector<int> A(MAX);
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    A[x]++;
  }
  vector<long long> dp(MAX);
  for (int i = 1; i < MAX; i++) {
    dp[i] = max(dp[i - 1], (i >= 2 ? dp[i - 2] : 0) + 1ll * i * A[i]);
  }
  cout << dp.back() << '\n';
  return 0;
}