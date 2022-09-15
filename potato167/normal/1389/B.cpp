#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  for(int i=0;i<N;i++){
    int m,k,l,Z=0;
    cin>>m>>k>>l;
    vector<int> p(m);
    for(int i=0;i<m;i++){
      cin>>p[i];
    }
    vector<vector<int>> dp(m,vector<int>(l+1));
    dp[0][0]=p[0];
    for(int j=1;j<=k;j++){
      dp[j][0]=dp[j-1][0]+p[j];
      Z=dp[j][0];
      for(int a=1;a*2<=min(l*2,j);a++){
        if(j-a*2!=0){
          dp[j-a*2][a]=max(dp[j-a*2+1][a-1],dp[j-a*2-1][a])+p[j-a*2];
        }
        else{
          dp[0][a]=dp[1][a-1]+p[0];
        }
        if(j==k){
          Z=max(Z,dp[j-a*2][a]);
        }
      }
    }
    cout<<Z<<endl;
  }
}