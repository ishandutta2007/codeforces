#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll dp[2][12];
int main() {
 fastIO;
 int n,m;
 ll k;
 cin >> n >> m >> k;
 for(int t = 1; t < m; t ++)
  dp[0][t]=-(ll)1e18;
 ll x;
 ll res = 0;
 for(int i = 0; i < n; i ++){
  cin >> x;
  for(int t = 0; t < m; t ++){
   dp[1][(t+1)%m]=max(dp[0][t]+x-(t==0)*k,x-k);
  }
  for(int t = 0; t < m ; t ++){
    dp[0][t]  = dp[1][t];
    res = max(res,dp[1][t]);
   }
 }
 cout << res;
 return 0;
}