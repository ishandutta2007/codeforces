#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        cin >> a[i][j];
      }
    }
    if((n+m)%2==0){cout << "NO\n";continue;}

    vector<vector<pi>> dp(n,vector<pi>(m,{1e9,-1e9}));
    dp[0][0].first=0;dp[0][0].second=0;

    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(i){
          dp[i][j].first=min(dp[i-1][j].first,dp[i][j].first);
          dp[i][j].second=max(dp[i-1][j].second,dp[i][j].second);
        }
        if(j){
          dp[i][j].first=min(dp[i][j-1].first,dp[i][j].first);
          dp[i][j].second=max(dp[i][j-1].second,dp[i][j].second);
        }
        dp[i][j].first+=a[i][j];
        dp[i][j].second+=a[i][j];
        // cout << "[" << dp[i][j].first << ',';
        // cout << dp[i][j].second << "] ";
      }// cout << '\n';
    }
    if(dp[n-1][m-1].first<=0 && 0<=dp[n-1][m-1].second){
      cout << "YES\n";
    }
    else{
      cout << "NO\n";
    }
  }
  return 0;
}