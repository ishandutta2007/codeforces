#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    vector<string> s(2);
    cin >> n >> s[0] >> s[1];
    vector<vector<bool>> dp(2,vector<bool>(n,false));
    dp[0][0]=true;
    if(s[1][0]=='0'){dp[1][0]=true;}
    for(int i=1;i<n;i++){
      //cerr << i << '\n';
      if(s[0][i]=='0'){
        if(dp[0][i-1]||dp[1][i-1]){dp[0][i]=true;}
      }
      if(s[1][i]=='0'){
        if(dp[0][i-1]||dp[1][i-1]){dp[1][i]=true;}
      }
    }
    if(dp[1][n-1]){cout << "YES\n";}else{cout << "NO\n";}
  }
  return 0;
}