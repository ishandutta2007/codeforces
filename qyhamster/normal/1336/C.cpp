#include <bits/stdc++.h>
using namespace std;
long long dp[3010][3010],tmp[3010],b[3010];
const long long MOD = 998244353;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  b[0] = 1;
  for(int i = 1; i < 3010; i++) b[i] = b[i-1] * 2 % MOD;
  string s,t;
  cin >> s >> t;
  int n = s.length(), m = t.length();
  for(int i = 0; i < m; i++)
  {
    if(s[0] == t[i]) dp[i][i] = 2;
  }
  long long ans = dp[0][m-1];
  for(int i = 1; i < n; i++)
  {
    for(int j = 0; j < m; j++) tmp[j] = 0;
    for(int j = 0; j < m; j++)
    {
      if(t[j] == s[i])
      {
        if(j+1 < m) tmp[j] += dp[j+1][m-1];
        else tmp[j] += b[i];
        ///cout << j << "..." << b[i] << "..." << t[j] << "..." << s[i]  << "..." << tmp[1] << endl;
      }
      tmp[j] += dp[j][m-1];
    }
    if(i < m)
    {
      for(int j = 0; j < m-i; j++)
      {
        if(t[j] == s[i]) dp[j][j+i] += dp[j+1][j+i];
        if(t[j+i] == s[i]) dp[j][j+i] += dp[j][j+i-1];
        dp[j][j+i] %= MOD;
      }
    }
    if(i < m)
    {
      if(t[m-1] == s[i]) tmp[m-1-i] += dp[m-1-i][m-2];
    }
    for(int j = 0; j < m; j++) dp[j][m-1] = tmp[j] % MOD;
    //cout << dp[0][0] << " " << dp[0][1] << " " << dp[1][1] << endl;
    ans = (ans + dp[0][m-1]) % MOD;
  }
  cout << ans << endl;
  return 0;
}