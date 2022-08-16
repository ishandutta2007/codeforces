#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using db = long double;
const int N = 1e6 + 5, MOD = 1e9 + 7;
int p[N];
vector<int> v;
int cur = 0;
vector<int> facto(int x){
  vector<int> ret;
  while(x > 1){
    ret.push_back(p[x]);
    x /= p[x];
  }
  return ret;
}
void init(){
  int mx = 0;
  cout << mx << ' ' << cur << '\n';

}
int dp[20][2][N];
int n;
int go2[20][2];
int go3[20][2];
int useless[20][3];
int solve(int twos, int threes, int filling){
//  cout << twos << ' ' << threes << ' ' << filling << '\n';
  if(twos + threes + filling == 0)return 1;
  int &ret = dp[twos][threes][filling];
  if(~ret)
    return ret;
  ret = 0;
  ///use a useless
  if(filling)
    ret = ret + solve(twos,threes,filling-1) * 1ll * filling % MOD;
  ///use a two
  if(twos){
    ret = ret + solve(twos-1,threes,filling + useless[twos-1][threes] - useless[twos][threes] - 1) * 1ll * go2[twos][threes] % MOD;
  }
  if(ret >= MOD)ret -= MOD;
  if(threes){
    ret = ret + solve(twos,threes-1,filling + useless[twos][threes-1] - useless[twos][threes] - 1) * 1ll * go3[twos][threes] % MOD;
  }
  if(ret >= MOD)ret -= MOD;
  return ret;
}
int main(){
#ifdef ONLINE_JUDGE
ios_base::sync_with_stdio(0);cin.tie(0);
#endif // ONLINE_JUDGE


  cin >> n;
    for(int i = 2; i <= n; i++){
    if(!p[i])
      for(int j = i; j <= n; j += i)
        p[j] = i;
    auto x = facto(i);
    if(x.size() > cur){
      cur = x.size();
      v.clear();
    }
    if(x.size() == cur)
      v.push_back(i);
  }

  int ret = 0;
  memset(dp, -1, sizeof dp);
  for(int i = 0; i < 20; i++){
    for(int j = 0; j < 2; j++){
      ///number
      int num = (1 << i);
      if(j)num *= 3;
      if(i)
      for(int k = 1; k * (num / 2) <= n; k += 2){
        go2[i][j]++;
      }
      if(j)
      for(int k = 1; k * num / 3 <= n; k++)if(k%3!=0){
        go3[i][j]++;
      }
      useless[i][j] = n / num - 1;
    }
  }
  for(auto x : v){
//    cout << x << ' ' << cur << '\n';
    if(x % 3 == 0){
      ret += solve(cur-1,1,useless[cur-1][1]);
    } else {
      ret += solve(cur,0,useless[cur][0]);
    }
  }

  if(ret >= MOD)ret -= MOD;
  cout << ret << '\n';




  return 0;
}