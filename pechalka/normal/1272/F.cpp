#include <deque>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 1000000000;
const int MAXN = 200;

int dp[MAXN + 1][MAXN + 1][MAXN + 1];

pair<int, int> pr[201][201][201];

int main(){
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

  string s;
  string t;
  cin >> s;
  cin >> t;
  for (int i = 0; i <= 200; ++i){
    for (int j = 0; j <= 200; ++j)
      for (int k = 0; k <= 200; ++k)
        dp[i][j][k] = INF;
  }
  for (int i = 100; i <= 200; ++i)
    dp[0][0][i] = i - 100;
  for (int i = 0; i < 100; ++i)
    dp[0][0][i] = INF;
  int n = s.size();
  int m = t.size();
  for (int i = 0; i <= n; ++i){
    for (int j = 0; j <= m; ++j){
      if (i > 0 && s[i - 1] == '('){
        for (int k = 1; k <= 200; ++k){
          if (dp[i - 1][j][k - 1] + 1 < dp[i][j][k]){
            dp[i][j][k] = dp[i - 1][j][k - 1] + 1;
            pr[i][j][k] = make_pair(-1, 0);
          }
        }
      }
      if (i > 0 && s[i - 1] == ')'){
        for (int k = 100; k <= 199; ++k){
          if (dp[i - 1][j][k + 1] + 1 < dp[i][j][k]){
            dp[i][j][k] = dp[i - 1][j][k + 1] + 1;
            pr[i][j][k] = make_pair(-1, 0);
          }
        }
      }
      if (j > 0 && t[j - 1] == '('){
        for (int k = 1; k <= 200; ++k){
          if (dp[i][j - 1][k - 1] + 1 < dp[i][j][k]){
            dp[i][j][k] = dp[i][j - 1][k - 1] + 1;
            pr[i][j][k] = make_pair(0, -1);
          }
        }
      }
      if (j > 0 && t[j - 1] == ')'){
        for (int k = 100; k <= 199; ++k){
          if (dp[i][j - 1][k + 1] + 1 < dp[i][j][k]){
            dp[i][j][k] = dp[i][j - 1][k + 1] + 1;
            pr[i][j][k] = make_pair(0, -1);
          }
        }
      }
      if (i > 0 && j > 0 && s[i - 1] == t[j - 1] && s[i - 1] == '('){
        for (int k = 1; k <= 200; ++k){
          if (dp[i - 1][j - 1][k - 1] + 1 < dp[i][j][k]){
            dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
            pr[i][j][k] = make_pair(-1, -1);
          }
        }
      }
      if (i > 0 && j > 0 && s[i - 1] == t[j - 1] && s[i - 1] == ')'){
        for (int k = 100; k <= 199; ++k){
          if (dp[i - 1][j - 1][k + 1] + 1 < dp[i][j][k]){
            dp[i][j][k] = dp[i - 1][j - 1][k + 1] + 1;
            pr[i][j][k] = make_pair(-1, -1);
          }
        }
      }
    }
  }
  int ans = INF;
  int ansi = 0;
  for (int i = 0; i <= 200; ++i){
    if (dp[n][m][i] + abs(100 - i) < ans){
      ans = dp[n][m][i] + abs(100 - i);
      ansi = i;
    }
  }
  string res;
  if (ansi > 100){
    for (int i = 0; i < ansi - 100; ++i)
      res += ')';
  } else {
    for (int i = 0; i < 100 - ansi; ++i)
      res += '(';
  }
  int nowi = n;
  int nowj = m;
  int nowk = ansi;
  while (nowi || nowj){
    auto tmp = pr[nowi][nowj][nowk];
    if (tmp.first == -1){
      if (s[nowi - 1] == '(')
        --nowk;
      else
        ++nowk;
      res += s[nowi - 1];
    } else if (tmp.second == -1){
      if (t[nowj - 1] == '(')
        --nowk;
      else
        ++nowk;
      res += t[nowj - 1];
    }
    nowi += tmp.first;
    nowj += tmp.second;
  }
  for (int i = 0; i < nowk - 100; ++i)
    res += '(';
  reverse(res.begin(), res.end());
  cout << res << '\n';
  return 0;
}