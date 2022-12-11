#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a)

const int N = 205;
const int MOD = (int)1e9 + 7;
int dp[N][N][N][2];

int len[N][2];
string s;

int func(string p){
  int siz = p.size();
  for(int y = siz; y > 0; y -- ){
    if(s.substr(0, y) == p.substr(siz - y, y)){
      return y;
    }
  }
  return 0;
}

int main(){
  fastIO;
  int n;
  cin >> n;
  cin >> s;
  if(s[0] == '(')
    len[0][0] = 1;
  else
    len[0][1] = 1;
  string t;
  int p = 1;
  for(char x : s){
    t.push_back(x);
    t.push_back('(');
    len[p][0] = func(t);
    t.pop_back();
    t.push_back(')');
    len[p][1] = func(t);
    t.pop_back();
    ++ p;
  }
  dp[0][0][0][0] = 1;
  int vl;
  for(int i = 0;i < 2*n; i ++ ){
    for(int j = 0;j <= n;j ++ ){
      for(int x = 0; x <= s.size(); x ++ ){
        for(int t = 0; t < 2; t ++ ){
          if(j > 0){
            vl = t;
            vl |= (len[x][1] == s.size());
            dp[i + 1][j - 1][len[x][1]][vl] += dp[i][j][x][t];
            dp[i + 1][j - 1][len[x][1]][vl] %= MOD;
          }
          if(j < n){
            vl = t;
            vl |= (len[x][0] == s.size());
            dp[i + 1][j + 1][len[x][0]][vl] += dp[i][j][x][t];
            dp[i + 1][j + 1][len[x][0]][vl] %= MOD;
          }
        }
      }
    }
  }
  int ans = 0;
  for(int j = 0; j <= s.size(); j ++ ){
    ans += dp[2 * n][0][j][1];
    ans %= MOD;
  }
  cout << ans;
  return 0;
}