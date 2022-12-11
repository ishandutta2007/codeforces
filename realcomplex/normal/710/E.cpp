#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll dp[10000009];

int main(){
  int n;
  ll x,y;
  cin >> n >> x >> y;
  dp[1]=x;
  for(int i = 2;i<=n;i++){
    dp[i]=dp[i-1]+x;
    if(i%2==0)dp[i]=min(dp[i],dp[i/2]+y);
    else dp[i]=min(dp[i],dp[i/2+1]+y+x);
  }
  cout << dp[n];
  return 0;
}