#include <iostream>

using namespace std;

const int mod = 1000000007;
const int N = 4010;

long long dp[N];
long long X[N];
long long C[2][N];
int n;

int main() {
  cin >> n;
  for(int i = 0;i <= n;i++) {
    int idx = i % 2;
    if(i == 0) {
      dp[i] = 0;
      X[i] = 1;
      C[idx][0] = 1;
    }else {
      dp[i] = X[i-1];
      for(int j = 1;j <= i;j++) {
        dp[i] = (dp[i] + C[!idx][j-1] * dp[i-j]) % mod;
      }
      X[i] = (2 * X[i-1]) % mod;
      for(int j = 2;j <= i;j++) {
        X[i] = (X[i] + C[!idx][j-1] * X[i-j]) % mod;
      }
      for(int j = 0;j <= i;j++) {
        C[idx][j] = ((j > 0 ? C[!idx][j-1] : 0ll) + C[!idx][j]) % mod;
      }
    }
  }
  cout << dp[n] << endl;
  return 0;
}