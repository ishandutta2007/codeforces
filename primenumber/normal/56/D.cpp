#include <bits/stdc++.h>

#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)

using namespace std;

typedef vector<int> vecint;

int dp[1005][1005];
string dir[1005][1005];

int main()
{
  string s, t;
  cin>>s>>t;
  int n=s.size(), m=t.size();
  REP(i,n+1) {
    dp[i][0] = i;
    dir[i][0] = "DELETE";
  }
  REP(i,m+1) {
    dp[0][i] = i;
    dir[0][i] = "INSERT";
  }
  FOR(i,0,n) {
    FOR(j,0,m) {
      int cost = 1;
      if (s[i] == t[j])
        cost = 0;
      dp[i+1][j+1] = dp[i][j+1] + 1;
      dir[i+1][j+1] = "DELETE";
      if (dp[i+1][j+1] > dp[i+1][j] + 1) {
        dp[i+1][j+1] = dp[i+1][j] + 1;
        dir[i+1][j+1] = "INSERT";
      }
      if (dp[i+1][j+1] > dp[i][j] + cost) {
        dp[i+1][j+1] = dp[i][j] + cost;
        dir[i+1][j+1] = "REPLACE";
      }
    }
  }
  cout << dp[n][m] << endl;
  int i=n, j=m;
  while(i||j) {
    if (dir[i][j] == "INSERT") {
      cout << dir[i][j] << ' ' << (i+1) << ' ' << t[j-1] << endl;
      --j;
    } else if (dir[i][j] == "REPLACE") {
      if (dp[i][j] > dp[i-1][j-1])
        cout << dir[i][j] << ' ' << i << ' ' << t[j-1] << endl;
      --i;--j;
    } else {
      cout << dir[i][j] << ' ' << i << endl;
      --i;
    }
  }
  return 0;
}