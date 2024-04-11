#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long t,x,y;
    cin >> t >> x >> y;
    long long app=t-(x+y);
    if(app<0){cout << "NO\n";continue;}
    vector<vector<int>> board(121,vector<int>(121,0));
    vector<vector<long long>> dp(121,vector<long long>(121,0));
    dp[0][0]=app;
    for(int i=0;i<120;i++){
      for(int j=0;j<120;j++){
        dp[i+1][j]+=(dp[i][j]/2);
        dp[i][j+1]+=(dp[i][j] - dp[i][j]/2);
        board[i][j]=dp[i][j]%2;
      }
    }

    bool ok=false;
    int p=0,q=0;
    while(p<120 && q<120){
      if(x==p && y==q){ok=true;break;}
      if(board[p][q]==0){q++;}else{p++;}
    }
    if(ok){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}