#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,k;
  cin >> n >> m >> k;
  k++;
  vector<vector<vector<pi>>> dp(n,vector<vector<pi>>(m,vector<pi>(k,{-1e9,-1e9})));
  vector<string> s(n);
  for(auto &nx : s){cin >> nx;}
  for(int i=0;i<m;i++){
    dp[n-1][i][(s[n-1][i]-'0')%k]={s[n-1][i]-'0',-1};
  }
  for(int i=n-1;i>=1;i--){
    for(int j=0;j<m;j++){
      for(int l=0;l<k;l++){
        int v=dp[i][j][l].first;
        if(j!=0){
          int del=(s[i-1][j-1]-'0');
          dp[i-1][j-1][(l+del)%k]=max(
            dp[i-1][j-1][(l+del)%k],{v+del,0}
          );
        }
        if(j!=m-1){
          int del=(s[i-1][j+1]-'0');
          dp[i-1][j+1][(l+del)%k]=max(
            dp[i-1][j+1][(l+del)%k],{v+del,1}
          );
        }
      }
    }
  }
  int tj=0,tk=0;
  for(int i=0;i<m;i++){
    if(dp[0][tj][0]<dp[0][i][0]){tj=i;}
  }
  if(dp[0][tj][0].first<0){cout << "-1\n";return 0;}
  cout << dp[0][tj][0].first << '\n';
  string rs;
  for(int i=0;i<n-1;i++){
    int cur=(s[i][tj]-'0');
    if(dp[i][tj][tk].second==0){
      rs.push_back('L');
      tj++;
    }
    else{
      rs.push_back('R');
      tj--;
    }
    tk+=(k-cur%k);tk%=k;
  }
  reverse(rs.begin(),rs.end());
  cout << tj+1 << '\n';
  cout << rs << '\n';
  return 0;
}