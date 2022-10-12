#include<bits/stdc++.h>
#define llinf 4154118101919364364

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<long long> a(n);
    for(auto &nx : a){cin >> nx;}
    vector<vector<long long>> dp(n+1,vector<long long>(500,-llinf));
    dp[n][0]=llinf;
    for(int i=n-1;i>=0;i--){
      long long ss=0;
      for(int j=0;(j<500 && (i-j)>=0);j++){
        ss+=a[i-j];
        if(ss<dp[i+1][j]){
          //cerr << i-j << ' ' << j+1 << '\n';
          dp[i-j][j+1]=max(dp[i-j][j+1],ss);
        }
      }
      for(int j=0;j<500;j++){
        dp[i][j]=max(dp[i][j],dp[i+1][j]);
      }
    }
    for(int i=499;i>=0;i--){
      if(dp[0][i]>=0){cout << i << '\n';break;}
    }
  }
  return 0;
}