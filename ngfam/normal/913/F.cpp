#include <bits/stdc++.h>

using namespace std;

const int N = 2020;
const int mod = 998244353;

int fpow(int x, int y) {
  int ret = 1;
  while(y) {
    if(y & 1) ret = (1LL * ret * x) % mod;
    x = (1LL * x * x) % mod;
    y >>= 1;
  }
  return ret;
}

int n;
int a, b;
int g[N];
int dp[N];
int f[N][N]; //// chose j from i pepople so that these j people win everyone else i
int pconnect[N];

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n >> a >> b;

  int p = (1LL * a * fpow(b, mod - 2) % mod);
  int rp = (1 - p + mod) % mod;

  f[0][0] = 1;
  for(int i = 0; i < N - 1; ++i) {
    for(int j = 0; j <= i; ++j) {
      int winall = fpow(rp, i - j);
      int nowin = fpow(p, j);

      f[i + 1][j] += 1LL * f[i][j] * nowin % mod; /// not choosing i + 1
      f[i + 1][j + 1] += 1LL * f[i][j] * winall % mod;

      f[i + 1][j] %= mod;
      f[i + 1][j + 1] %= mod;
    }
    f[i][0] = 0;
  }

  for(int i = 1; i < N - 1; ++i) {
    pconnect[i] = 1;
    for(int j = 1; j < i; ++j) {
      pconnect[i] -= 1LL * f[i][j] * pconnect[j] % mod;
      pconnect[i] += mod;
      if(pconnect[i] >= mod) pconnect[i] -= mod;
    }
  }


  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j < i; ++j) {
      dp[i] += (dp[j] + dp[i - j] + 1LL * (i - j) * j + (j * (j - 1) / 2) % mod) * 1LL * (1LL * f[i][j] * pconnect[j] % mod) % mod;
      dp[i] %= mod;
    }

    int rate = pconnect[i];
    int kp = (1LL * i * (i - 1) / 2) * rate % mod;

    dp[i] = (dp[i] + kp) * 1LL * fpow((1 - rate + mod) % mod, mod - 2) % mod;

  }

  cout << dp[n] << endl;

  return 0;
}