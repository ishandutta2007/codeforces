#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

long long dp[5][1000006];
string s;

int main() {
  ios::sync_with_stdio(false);
  cin >> s;
  if (s[0] == '?') dp[0][0] = dp[1][0] = dp[3][0] = 1;
  else if (s[0] == '0') dp[0][0] = 1;
  else if (s[0] == '1') dp[1][0] = 1;
  else if (s[0] == '*') dp[3][0] = 1;
  // REP (i, 5) cout << dp[i][0];
  FOR (i, 1, s.size() - 1) {
    // BUG(i);
    if (s[i] == '0' || s[i] == '?') dp[0][i] = (dp[0][i - 1] + dp[4][i - 1]) % mod;
    if (s[i] == '1' || s[i] == '?') {
      dp[1][i] = (dp[0][i - 1] + dp[4][i - 1]) % mod;
      dp[4][i] = (dp[3][i - 1]);
    }
    if (s[i] == '2' || s[i] == '?') dp[2][i] = (dp[3][i - 1]);
    if (s[i] == '*' || s[i] == '?') dp[3][i] = (dp[1][i - 1] + dp[2][i - 1] + dp[3][i - 1]) % mod;
  }
  int i = s.size() - 1;
  cout << (dp[0][i] + dp[3][i] + dp[4][i]) % mod;
}