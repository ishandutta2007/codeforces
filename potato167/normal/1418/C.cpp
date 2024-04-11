#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  cin>>T;
  for(int i=0;i<T;i++){
    int N;
    cin>>N;
    vector<int> p(N+1);
    for(int i=0;i<N;i++){
      cin>>p[i];
    }
    vector<vector<int>> dp(N+3,vector<int>(2,16716717));
    dp[0][0]=0;
    for(int i=0;i<N;i++){
      dp[i+1][0]=min(dp[i+1][0],dp[i][1]);
      dp[i+2][0]=min(dp[i+2][0],dp[i][1]);
      dp[i+1][1]=min(dp[i+1][1],dp[i][0]+p[i]);
      dp[i+2][1]=min(dp[i+2][1],dp[i][0]+p[i]+p[i+1]);
    }
    cout<<min(dp[N][0],dp[N][1])<<endl;
  }
}