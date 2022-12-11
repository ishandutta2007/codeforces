#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int dp[8];

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int z = 0 ; z < tc; z ++ ){
    string t;
    cin >> t;
    for(int i = 0 ; i < 8 ; i ++ ){
      dp[i]=-1;
    }
    dp[0]=0;
    int d;
    int ans = (int)1e7;
    for(char x : t){
      d=x-'1';
      for(int j = 7; j >= 1; j -- ){
        if(dp[j] != -1) dp[j]=dp[j]+1;
        if((j & (1 << d))){
          if(dp[(j ^ (1 << d))] != -1){
            if(dp[j] == -1) dp[j] = (int)1e7;
            dp[j]=min(dp[j],dp[(j ^ (1 << d))]+1);
          }
        }
      }
      if(dp[7] != -1) ans = min(ans, dp[7]);
    }
    if(ans == (int)1e7) cout << 0 << "\n";
    else cout << ans << "\n";
  }
  return 0;
}