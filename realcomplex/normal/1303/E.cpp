#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int nx[405][26];
int dp[405][405];

void solve(){
  for(int i = 0 ; i < 405; i ++ ) for(int j = 0 ; j < 26; j ++ )
    nx[i][j]=-1;
  string s, t;
  cin >> s >> t;
  int n = s.size();
  int m = t.size();
  s = '#' + s;
  t = '#' + t;
  for(int i = n; i >= 1; i -- ){
    for(int j = 0 ; j < 26; j ++ ){
      nx[i][j]=nx[i+1][j];
    }
    nx[i][s[i] - 'a'] = i;
  }
  int s1, s2;
  for(int c = 1; c <= m; c ++ ){
    for(int i = 0 ; i <= n; i ++ ){
      for(int j = 0 ; j <= n; j ++ ){
        dp[i][j]=(int)1e9 + 9;
      }
    }  
    s1 = c;
    s2 = m - c;
    dp[0][0]=0;
    for(int i = 0 ; i <= s1; i ++ ){
      for(int j = 0 ; j <= s2; j ++ ){
        if(dp[i][j] > n) continue;
        if(i < s1){
          if(nx[dp[i][j]+1][t[i + 1] - 'a'] != -1)
            dp[i+1][j]=min(dp[i+1][j],nx[dp[i][j]+1][t[i + 1] - 'a']);
        }
        if(j < s2){
          if(nx[dp[i][j]+1][t[c + j + 1] - 'a'] != -1){
            dp[i][j+1]=min(dp[i][j+1],nx[dp[i][j]+1][t[c + j + 1] - 'a']);
          }
        }
      }
    }
    if(dp[s1][s2] <= n){
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}

int main(){ 
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 0; t < tc; t ++ ){  
    solve();
  }
  return 0;
}