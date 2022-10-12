#include<bits/stdc++.h>

using namespace std;

int dp[1024][1024][21]={0};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,k;
  cin >> n >> m >> k;
  string s,t;
  cin >> s >> t;
  int res=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      //cout << i << ' ' << j << ':';
      for(int p=0;p<=2*k;p++){
        //cout << dp[i][j][p] << ' ';
        if(s[i]==t[j] && p<2*k){
          int np=p;
          if(np%2==0){np++;}
          dp[i+1][j+1][np]=max(dp[i+1][j+1][np],dp[i][j][p]+1);
          res=max(res,dp[i][j][p]+1);
        }
        {
          int np=p;
          if(np%2==1){np++;}
          dp[i+1][j][np]=max(dp[i+1][j][np],dp[i][j][p]);
          dp[i][j+1][np]=max(dp[i][j+1][np],dp[i][j][p]);
        }
      }
      //cout << '\n';
    }
  }
  cout << res << '\n';
  return 0;
}