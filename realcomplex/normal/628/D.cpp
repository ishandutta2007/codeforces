#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

const ll MOD = (ll)1e9 + 7;
const int LEN = 2005;
const int MD = 2005;

ll dp[LEN][MD][2];
int m, k;

ll calc(string kk){
  memset(dp, 0, sizeof dp);
  dp[0][0][1] = 1LL;
  int p = 1;
  for(int it = 0;it < (int)kk.size(); it ++ ){
    for(int x = 0;x < MD; x ++ ){
      for(int j = 0; j < 10;j ++ ){
        if(((it + 1) % 2 == 1 and j != k) or ((it + 1) % 2 == 0 and j == k)){
          if(j < kk[it]-'0'){
            dp[it + 1][(x * 10 + j) % m][0] += dp[it][x][0] + dp[it][x][1];
            dp[it + 1][(x * 10 + j) % m][0] %= MOD;
          }
          else if(j == kk[it]-'0'){
            dp[it + 1][(x * 10 + j) % m][1] += dp[it][x][1];
            dp[it + 1][(x * 10 + j) % m][0] += dp[it][x][0];
            dp[it + 1][(x * 10 + j) % m][1] %= MOD;
            dp[it + 1][(x * 10 + j) % m][1] %= MOD;
          }
          else{
            dp[it + 1][(x * 10 + j) % m][0] += dp[it][x][0];
            dp[it + 1][(x * 10 + j) % m][0] %= MOD;
          }
        }
      }
    }
  }
  int n = kk.size();
  ll oo = dp[n][0][0] + dp[n][0][1];
  return oo;
}

int is_ok(string kk){
  for(int i = 0;i < kk.size(); i ++ ){
    if(i%2){
      if(kk[i]-'0' != k){
        return 0;
      }
    }
    else{
      if(kk[i]-'0' == k){
        return 0;
      }
    }
  }
  int l = 0;
  for(int i = 0;i < kk.size(); i ++ ){
    l *= 10;
    l += kk[i]-'0';
    l %= m;
  }
  if(l != 0)
    return 0;
  return 1;
}

int main(){
  fastIO;
  cin >> m >> k;
  string c1, c2;
  cin >> c1 >> c2;
  ll A = calc(c1);
  ll B = calc(c2);
  cout << (B-A+is_ok(c1)+MOD)%MOD;
  return 0;
}