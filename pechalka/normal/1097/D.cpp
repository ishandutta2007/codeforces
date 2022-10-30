#include <deque>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

const long long MOD = 1000000007;

long long dp[50][10001];
long long pref[50][10001];
long long divide[50];

long long pow(long long a, int n){
  if (n == 0)
    return 1;
  if (n % 2 == 1)
    return pow(a, n - 1) * a % MOD;
  long long tmp = pow(a, n / 2);
  return tmp * tmp % MOD;
}

int k;

long long get(long long p, int n){
  for (int j = 0; j <= k; ++j)
    dp[0][j] = 1;
  for (int j = 0; j <= k; ++j)
    pref[0][j] = 1;
  long long pw = p % MOD;
  for (int i = 1; i <= n; ++i){
    dp[i][0] = pw;
    pref[i][0] = pref[i - 1][0] + dp[i][0];
    if (pref[i][0] > MOD)
      pref[i][0] -= MOD;
    for (int j = 1; j <= k; ++j){
      dp[i][j] = pref[i][j - 1] * divide[i] % MOD;
      pref[i][j] = pref[i - 1][j] + dp[i][j];
      if (pref[i][j] > MOD)
        pref[i][j] -= MOD;
    }
    pw = pw * p % MOD;
  }
  return dp[n][k];
}

int main(){
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

  for (int i = 0; i < 50; ++i)
    divide[i] = pow(i + 1, MOD - 2);
  long long n;
  cin >> n >> k;
  long long ans = 1;
  for (long long i = 2; i * i <= n; ++i){
    if (n % i == 0){
      int cnt = 0;
      while (n % i == 0){
        ++cnt;
        n /= i;
      }
      ans = ans * get(i, cnt) % MOD;
    }
  }
  if (n > 1)
    ans = ans * get(n, 1) % MOD;
  cout << ans << '\n';
  return 0;
}