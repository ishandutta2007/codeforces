#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
  int n, m;
  long long k;
  cin >> n >> m >> k;
  vector<long long> A(n);
  for (int i = 0; i < n; ++i)
    cin >> A[i];
  if (m > n){
    A.resize(m, -1);
    n = m;
  }
  long long ans = 0;
  vector<long long> dp(n);
  dp[n - 1] = A[n - 1] - k;
  for (int i = 1; i < m; ++i)
    dp[n - i - 1] = max(dp[n - i] + A[n - i - 1], A[n - i - 1] - k);
  for (int i = n - m - 1; i >= 0; --i){
    long long S = -k;
    for (int j = 0; j < m; ++j) {
      S += A[i + j];
      dp[i] = max(dp[i], S);
    }
    dp[i] = max(dp[i], S + dp[i + m]);
  }
  for (int i = 0; i < n; ++i)
    ans = max(ans, dp[i]);
  cout << ans;
  return 0;
}