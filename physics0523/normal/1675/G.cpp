#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  vector<int> pt;
  for(int i=0;i<n;i++){
    int v;
    cin >> v;
    for(int j=0;j<v;j++){pt.push_back(n-1-i);}
  }
  reverse(pt.begin(),pt.end());
  vector<vector<int>> dp(m+1,vector<int>(m+1,1e9));
  dp[0][0]=0;
  for(int rem=n;rem>=1;rem--){
    int cpt=n-rem;
    vector<vector<int>> ndp(m+1,vector<int>(m+1,1e9));
    for(int sig=0;sig<=m;sig++){
      for(int pre=0;sig+rem*pre<=m;pre++){
        int del=0;
        for(int nx=0;sig+rem*nx<=m;nx++){
          if(pre<=nx){
            ndp[sig+nx][nx]=min(ndp[sig+nx][nx],dp[sig][pre]+del);
          }
          del+=abs(pt[sig+nx]-cpt);
        }
      }
    }
    dp=ndp;
  }

  int res=1e9;
  for(int i=0;i<=m;i++){res=min(res,dp[m][i]);}
  cout << res << '\n';
  return 0;
}